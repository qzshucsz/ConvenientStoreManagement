#include <iostream>
#include <vector>
//#include <afxres.h>
#include "FamilyMart.h"

int main() {
    using namespace std;
//    char chpath[MAX_PATH];
//    GetModuleFileName(NULL,(LPSTR)chpath,sizeof(chpath));
    string exePath("/root/OOP/FamilyMart/cmake-build-debug/FamilyMart.exe");
    string currentPath = exePath.substr(0,exePath.find("FamilyMart.exe"));
    string shopFile= currentPath+"shop.txt";
    cout<<"current pah:"<<currentPath<<endl;
    FamilyMart *testMart = new FamilyMart(shopFile);
    cout<<"FamilyMart execute over"<<endl;
    string command;
    while(getline(cin,command)) {
        cout << "command you enter:" << command << endl;
        if (command.find("purchase file") != string::npos) {
            cout << "find purchase file in the command" << endl;
            string purchaseFile = currentPath + command.substr(command.find("(") + 1, command.find(")") - command.find("(") - 1);
            cout<<"purchase file"<<purchaseFile<<endl;
            testMart->purchase_file(purchaseFile);

        } else if (command.find("sell file") != string::npos) {
            cout << "find sell file in the command" << endl;
            string sellFile = currentPath + command.substr(command.find("(") + 1, command.find(")") - command.find("(") - 1);
            cout << "sell file:" << sellFile << endl;
            testMart->sell_file(sellFile);
            cout << "Sell file execute over" << endl;

        } else if (command.find("show_sale_amount")!= string::npos) {
            cout << "find show_sale_amount in the command" << endl;
            testMart->show_sale_amount();

        } else if (command.find("show_all_shop_name")!= string::npos) {
            cout << "find show_all_shop_name in the command" << endl;
            testMart->show_all_shop_name();
            cout << "show all shop name execute over" << endl;

        } else if (command.find("close")!= string::npos) {
            cout << "find close in the command" << endl;
            testMart->close();
            break;
        }
        else {
            cout << "Usage: you can use the follow interfaces:" << endl;
            cout << "purchase file(file)" << endl;
            cout << "sell file(file)" << endl;
            cout << "show_sale_amount()" << endl;
            cout << "show_all_shop_name()" << endl;
            cout << "close()" << endl;
            cout << "Remind: Enter close() to quit the application."<<endl;
        }
    }

    return 0;
}