//
// Created by chen on 2018/5/11.
//
#include <string>

#ifndef FAMILYMART_WAREHOUSE_H
#define FAMILYMART_WAREHOUSE_H
using namespace std;

class Warehouse {
public:
    enum FamilyMartWarehouseSize{
        //分别对应容量为25,50和100的仓库
        twenty_five,
        fifty,
        one_hundred
    };

    Warehouse(const string& shopName,FamilyMartWarehouseSize warehouseSize);
    ~Warehouse();
    void setWarehouseUsedsize(const int &usedSize);

private:
    string mShopName;//标记该仓库属于哪个商店
    int mWarehouseSize;
    int hasUsedSize = 0;

};


#endif //FAMILYMART_WAREHOUSE_H
