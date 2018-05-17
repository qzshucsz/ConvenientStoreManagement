//
// Created by chen on 2018/5/11.
//
#include <iostream>
#include "Shop.h"

Shop::Shop() {

}

Shop::~Shop() {
    //关闭店铺时,将仓库关闭并清空
    delete mWarehouse;
    cout<<"deconstructor of ~Shop()"<<endl;
}

void Shop::setShopName(const string &mShopName) {
    //读入shop.txt时设置商店名称
    shopName = mShopName;
}

void Shop::setItemNumber(const string &mItemNumber) {
    itemNumber = mStrProcessor->stringToInt(mItemNumber);
    //初始化该商店的仓库
    if(itemNumber <= 25){
        mWarehouse = new Warehouse(shopName, Warehouse::twenty_five);
    }else if(itemNumber <= 50){
        mWarehouse = new Warehouse(shopName, Warehouse::fifty);
    }else if(itemNumber <= 100){
        mWarehouse = new Warehouse(shopName, Warehouse::one_hundred);
    }else{
        cout<<"the size of warehouse is illegal!"<<endl;
        return;
    }
    //商店仓库已存储的商品数量
    mWarehouse->setWarehouseUsedsize(itemNumber);
}


void Shop::insertItem(Item &item) {
    //初始读入shop.txt时将商品入库
    mItems.insert(mItems.end(),item);
}

string Shop::getShopName() {
    //商店名称查询接口,主要供show_all_shop_name()使用
    return shopName;
}

void Shop::setSellItem(Item &sellItem, string &discount) {
    //每售出一件商品（该商品不缺货的情况下）均做记录
    bool hasTheItem = false;
    Item *tempItem = new Item();
    for(auto &item:mItems){
//        cout<<item.getItemName(item)<<endl;
        if(sellItem.getItemName(sellItem)==item.getItemName(item)){
            hasTheItem = true;
            tempItem = &item;
            break;
        }
    }
    if(hasTheItem) {
        mSellItems.insert(mSellItems.end(), *tempItem);
        //计算商店营业额
        mTurnover += tempItem->getItemPrice() * mStrProcessor->stringToFloat(discount);
//        cout << shopName << " turn over:" << mTurnover << endl;
        for(auto it = mItems.begin();it!=mItems.end();){
            //将售出的商品从商店的库存中移除
            if(it->getItemName(*it) == tempItem->getItemName(*tempItem)){
                it = mItems.erase(it);
//                cout<<"delete the sell item"<<endl;
                break;
            }else{
                it++;
            }
        }
    }
}


void Shop::increaseSaleAmount() {
    //售出商品数量
    saleAmount+=1;
}

float Shop::getSaleAmount() {
    //查询销售额（后助教改为总利润）
    return mTurnover;
}

void Shop::setPurchaseItem(const Item &item) {
    //进货商品清单
    mPurchaseItems.insert(mPurchaseItems.end(),item);
}

vector<Item> Shop::getItems() {
    //查询商店目前库存的所有商品
    return mItems;
}


