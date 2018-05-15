//
// Created by chen on 2018/5/11.
//
#include <string>
#include "StringProcessor.h"
#ifndef FAMILYMART_ITEM_H
#define FAMILYMART_ITEM_H
using namespace std;

class Item {
public:
    Item();
    ~Item();
    void setItemName(const string& itemName);
    void setItemPrice(const string& itemPrice);
    void setItemProductionData(const string& itemProductionData);
    void setItemShelfLife(const string& intemShelfLife);
    float getItemPrice();
    string getItemName(const Item &item);
private:
    string name;
    float price;
    string productionData;
    string shelfLife;
    StringProcessor *mStrProcessor = new StringProcessor();
};


#endif //FAMILYMART_ITEM_H
