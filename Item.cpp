//
// Created by chen on 2018/5/11.
//

#include <iostream>
#include "Item.h"

using  namespace std;
Item::Item() {
//do nothing

}

float Item::getItemPrice() {
    cout<<"the price of "<<name<<" is "<<price<<endl;
    return price;
}

Item::~Item() {

}

void Item::setItemName(const string &itemName) {
    name = itemName;
}

void Item::setItemPrice(const string &itemPrice) {
    float temPrice = mStrProcessor->stringToFloat(itemPrice);
    price = temPrice;
}

void Item::setItemProductionData(const string &itemProductionData) {
    productionData = itemProductionData;
}

void Item::setItemShelfLife(const string &itemShelfLife) {
    shelfLife = itemShelfLife;
}

string Item::getItemName(const Item &item) {
    return item.name;
}
