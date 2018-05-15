//
// Created by chen on 2018/5/11.
//

#include <iostream>
#include "Warehouse.h"


using namespace std;
Warehouse::Warehouse(const string& shopName,FamilyMartWarehouseSize warehouseSize) {
    mShopName = shopName;
    switch(warehouseSize){
        case twenty_five:
            mWarehouseSize = 25;
            break;
        case fifty:
            mWarehouseSize = 50;
            break;
        case one_hundred:
            mWarehouseSize = 100;
            break;
        default:
            mWarehouseSize =0;
            break;
    }
    cout<<" "<<mShopName<<" "<<mWarehouseSize<<" constructor is invoked"<<endl;
}

Warehouse::~Warehouse() {

    cout << " " << mShopName << " " << mWarehouseSize << " deconstructor is invoked" << endl;
}

void Warehouse::setWarehouseUsedsize(const int &usedSize) {
    hasUsedSize = usedSize;
}


