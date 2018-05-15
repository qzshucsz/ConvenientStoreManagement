//
// Created by chen on 2018/5/11.
//
#include <vector>
#include "Warehouse.h"
#include "Item.h"
#include "StringProcessor.h"
#ifndef FAMILYMART_SHOP_H
#define FAMILYMART_SHOP_H


class Shop {
public:
    Shop();
    ~Shop();
    void setShopName(const string &mShopName);
    void setItemNumber(const string &mItemNumber);
    void insertItem(Item& item);
    void setSellItem(Item &sellItem,string &discount);
    void increaseSaleAmount();
    void setPurchaseItem(const Item &item);
    void setPurchaseItemNumber(const string &purchaseNumber);

    float getSaleAmount();
    string getShopName();
    vector<Item> getItems();

private:
    vector<Item> mItems;
    vector<Item> mPurchaseItems;
    vector<Item> mSellItems;
    Warehouse *mWarehouse = NULL;
    float mTurnover = 0;//该商店的营业额
    string shopName;//商店名称，由SHOP与编号组成
    int itemNumber;//商品总数
    int saleAmount = 0;
    int purchaseAmount = 0;
    StringProcessor *mStrProcessor = new StringProcessor();


};


#endif //FAMILYMART_SHOP_H
