//
// Created by chen on 2018/5/11.
//

#include <iostream>
#include "Item.h"

using  namespace std;
Item::Item() {
//do nothing

}

Item::~Item() {
//do nothing

}

float Item::getItemPrice() {
    //商品价格查询接口
    return price;
}


void Item::setItemName(const string &itemName) {
    //设置商品名称
    name = itemName;
}

void Item::setItemPrice(const string &itemPrice) {
    //设置商品价格
    float temPrice = mStrProcessor->stringToFloat(itemPrice);
    price = temPrice;
}

void Item::setItemProductionData(const string &itemProductionData) {
    //设置商品生产日期
    productionData = itemProductionData;
}

void Item::setItemShelfLife(const string &itemShelfLife) {
    //设置商品保质期（保质天数）
    shelfLife = itemShelfLife;
}

string Item::getItemName(const Item &item) {
    //商品名称查询接口
    return item.name;
}

string Item::getItemProductionData(const Item &item) {
    //商品生产日期查询接口
    return productionData;
}

string Item::getItemShelfLife(const Item &item) {
    //商品保质期查询接口
    return shelfLife;
}
