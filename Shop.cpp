//
// Created by chen on 2018/5/11.
//
#include <iostream>
#include "Shop.h"
#include "Warehouse.h"

Shop::Shop() {

}

Shop::~Shop() {
    delete mWarehouse;
    cout<<"deconstructor of ~Shop()"<<endl;
}

void Shop::setShopName(const string &mShopName) {
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
        std::cout<<"the size of warehouse is illegal!"<<endl;
        return;
    }

    mWarehouse->setWarehouseUsedsize(itemNumber);
}


void Shop::insertItem(Item &item) {
    mItems.insert(mItems.end(),item);
}

string Shop::getShopName() {
    return shopName;
}

void Shop::setSellItem(Item &sellItem, string &discount) {
    cout<<"searching "<<sellItem.getItemName(sellItem)<<" in "<<endl;
    bool hasTheItem = false;
    Item *tempItem = new Item();
    for(auto &item:mItems){
        cout<<item.getItemName(item)<<endl;
        if(sellItem.getItemName(sellItem)==item.getItemName(item)){
            cout<<"find the item:"<<item.getItemName(item)<<endl;
            hasTheItem = true;
            tempItem = &item;
            break;
        }
    }
    if(hasTheItem) {
        mSellItems.insert(mSellItems.end(), *tempItem);
        cout<<"sell item in the shop, name:"<<tempItem->getItemName(*tempItem)<<endl;
        mTurnover += tempItem->getItemPrice() * mStrProcessor->stringToFloat(discount);//计算商店营业额
        cout << shopName << " turn over:" << mTurnover << endl;
        for(auto it = mItems.begin();it!=mItems.end();){
            if(it->getItemName(*it) == tempItem->getItemName(*tempItem)){
                it = mItems.erase(it);
                cout<<"delete the sell item"<<endl;
                break;
            }else{
                it++;
            }
        }
    }else{
        cout<<"the shop does not have the item:"<<endl;
    }
}


void Shop::increaseSaleAmount() {
    saleAmount+=1;
}

float Shop::getSaleAmount() {
    return mTurnover;
}

void Shop::setPurchaseItem(const Item &item) {
    mPurchaseItems.insert(mPurchaseItems.end(),item);
}

void Shop::setPurchaseItemNumber(const string &purchaseNumber) {
    purchaseAmount = mStrProcessor->stringToInt(purchaseNumber);

}


vector<Item> Shop::getItems() {
    return mItems;
}


