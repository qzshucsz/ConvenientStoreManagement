//
// Created by chen on 2018/5/11.
//
#include <string>
#include <vector>
#include "Shop.h"
#include "StringProcessor.h"

#ifndef FAMILYMART_FAMILYMART_H
#define FAMILYMART_FAMILYMART_H
using namespace std;
class FamilyMart {
public:
    explicit FamilyMart(const string& shopFile);
    ~FamilyMart();
    void purchase_file(const string& purchaseFile);
    void sell_file(const string& sellFile);
    void show_sale_amount();
    void show_all_shop_name();
    void close();

private:
    void getStockInfoFromShopFile(Shop &mShop,const string& shopFile);
    vector<Shop> mShops;
    StringProcessor *mStrProcessor = new StringProcessor();//字符串处理器，封装了本lab中需要的字符串处理接口
    Shop *currentShop = new Shop();
    Item *currentItem = new Item();
};


#endif //FAMILYMART_FAMILYMART_H
