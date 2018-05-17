//
// Created by chen on 2018/5/11.
//

#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>
#include "FamilyMart.h"
#define SHOP_MAXSIZE 20

FamilyMart::FamilyMart(const string& shopFile) {
    mShops.reserve(SHOP_MAXSIZE);//为店铺容器创建出足够的空间,避免内存重新配置而导致程序出错
    getStockInfoFromShopFile(*currentShop,shopFile);
    cout<<"after initialization the "<<currentShop->getShopName()<<":"<<endl;
    for(auto &shop:mShops){
        cout<<shop.getShopName()<<endl;
        for(auto &item:shop.getItems()){
            cout<<item.getItemName(item)<<endl;
        }
    }
}

FamilyMart::~FamilyMart() {


}

void FamilyMart::purchase_file(const string &purchaseFile) {
    //商店进货
    ifstream purchaseStream;
    purchaseStream.open(purchaseFile,ios_base::in);
    if(!purchaseStream.is_open()){
        cout<<"can not open the purchase file"<<endl;
        return;
    }
    string lineStr;
    while(getline(purchaseStream,lineStr)){
        if(!mStrProcessor->hasStartWith("\t",lineStr)){
            vector<string> mPurchaseItemInfos = mStrProcessor->split(lineStr," ");
            if(mStrProcessor->hasStartWith("PURCHASE",lineStr)){
                for(auto &shop:mShops){
                    if(mStrProcessor->hasStartWith(shop.getShopName(),mPurchaseItemInfos[2])){
                        currentShop = &shop;
//                        cout<<"find the purchase shop:"<<currentShop->getShopName()<<endl;
                        break;
                    }
                }
            }
            else if(mStrProcessor->hasStartWith("name",lineStr)){//商品信息标签，跳过
                continue;
            }else{//记录进货的商品信息
//                cout<<"item name:"<<mPurchaseItemInfos[0]<<endl;
                Item *purchaseItem = new Item();
                purchaseItem->setItemName(mPurchaseItemInfos[0]);
                purchaseItem->setItemPrice(mPurchaseItemInfos[1]);
                purchaseItem->setItemShelfLife(mPurchaseItemInfos[2]);
                purchaseItem->setItemProductionData(mPurchaseItemInfos[3]);
                currentShop->setPurchaseItem(*purchaseItem);
                currentShop->insertItem(*purchaseItem);
                delete purchaseItem;
            }

        }

    }

    cout<<"after finish the purchase:"<<endl;
    for(auto &shop:mShops){
        cout<<shop.getShopName()<<endl;
        for(auto &item:shop.getItems()){
            cout<<item.getItemName(item)<<endl;
        }
    }

}

void FamilyMart::sell_file(const string &sellFile) {
    //读入销售商品清单及打折情况
    ifstream sellStream;
    sellStream.open(sellFile,ios_base::in);
    if(!sellStream.is_open()){
        cout<<"can not open the sell file."<<endl;
        return;
    }
    vector<string> mSellGoodsInfos;
    string lineStr;
    while(getline(sellStream,lineStr)) {
        string discount = "1";//商品进行打折销售的情况，默认值为不打折
        if (strlen(lineStr.c_str())!=0) {//跳过空白行
            if (mStrProcessor->hasStartWith("SALE", lineStr)) {
                mSellGoodsInfos = mStrProcessor->split(lineStr, " ");
                if (mSellGoodsInfos.size() == 2) {
                    for(auto &shop:mShops){
                        if(mStrProcessor->hasStartWith(mSellGoodsInfos[1],shop.getShopName())){
                            currentShop = &shop;
                            break;
                        }
                    }

                } else if (mSellGoodsInfos.size() == 3) {
                    for(auto &shop:mShops){
                        if(mStrProcessor->hasStartWith(mSellGoodsInfos[2],shop.getShopName())){
                            currentShop = &shop;
                            break;
                        }
                    }
                    discount = mSellGoodsInfos[1];
                }

            }else {
                bool hasFindItem = false;//借助该标志，如果商店的在售商品中没有sell清单中的商品，则呼略
                for(auto &mItem:currentShop->getItems()){
                    if(mStrProcessor->hasStartWith(mItem.getItemName(mItem),lineStr)){
                        currentItem  = &mItem;
//                      cout<<"the sell item name:"<<currentItem ->getItemName(*currentItem )<<endl;
                        hasFindItem = true;
                        break;
                    }
                }
                if(hasFindItem) {
                    cout<<"sell the Item: "<<currentItem->getItemName(*currentItem)<<endl;
                    currentShop->setSellItem(*currentItem , discount);
                    currentShop->increaseSaleAmount();
                    //卖出商品后,检查是否需要开新店
                    float surplusForOpenNewShop = currentShop->getSaleAmount()- newShopNum*50;
                    if(surplusForOpenNewShop >= 55) {
                        int shopNum = newShopNum+1;
                        stringstream intStream;
                        intStream<<(++shopNum);
                        string newShopName = "SHOP"+intStream.str();
                        Shop *newShop = new Shop();
                        newShop->setShopName(newShopName);
//                        cout<<"the turnover is larger than 55, create new shop: "<<newShopName<<endl;
                        mShops.push_back(*newShop);
                        newShopNum++;
                    }
                }
            }
        }

    }
    cout<<"after sell"<<endl;
    for(auto &shop:mShops){
        cout<<shop.getShopName()<<endl;
        for(auto &item:shop.getItems()){
            cout<<item.getItemName(item)<<endl;
        }
    }

}

void FamilyMart::show_sale_amount() {
    //查询指定商店的商品销售数量
    cout<<"the sale amount:"<<endl;
    for(auto &shop:mShops) {
        cout<<shop.getShopName()<<":"<<shop.getSaleAmount() << endl;
    }
}

void FamilyMart::show_all_shop_name() {
    //输出当前所有店铺的名字
    cout<<"all shop name are as follows:"<<endl;
    for(auto &shop:mShops){
        cout<<shop.getShopName()<<endl;
    }

}

void FamilyMart::close() {
    mShops.clear();

}

void FamilyMart::getStockInfoFromShopFile(Shop &mShop,const string &shopFile) {
    ifstream shopStockInfo;
    shopStockInfo.open(shopFile,ios_base::in);
    if(!shopStockInfo.is_open()){
        cout<<"can not open the shop file "<<shopFile<<endl;
        return;
    }
    string lineStr;
    vector<string> mInfos;
    //读取商店信息并设置相关数据
    while(getline(shopStockInfo,lineStr)){
        mInfos = mStrProcessor->split(lineStr," ");
        if(mStrProcessor->hasStartWith("SHOP",lineStr)) {//包含商店信息
            bool isShopInfo = true;
            for(auto &info: mInfos){
                if(isShopInfo){
                    //读入并设置商店名称信息
                    mShop.setShopName(info);
                    isShopInfo = false;
                }
                else{
                    //读取并设置该商店商品数量
                    mShop.setItemNumber(info);
                }
            }
        }

        else if(mStrProcessor->hasStartWith("name",lineStr)) {//商品属性名称标识，跳过
            continue;
        }else if(mStrProcessor->hasStartWith("\t",lineStr)){//空白行，跳过
            continue;
        }
        else{
            //依据shop file的商品信息格式，依次为
            //name	price	life(days)	product_date
            //存储对应的商品及其属性
            auto *tempItem = new Item();
            tempItem->setItemName(mInfos[0]);
            tempItem->setItemPrice(mInfos[1]);
            tempItem->setItemShelfLife(mInfos[2]);
            tempItem->setItemProductionData(mInfos[3]);
            mShop.insertItem(*tempItem);
            delete tempItem;
        }

    }
    mShops.push_back(mShop);
}

