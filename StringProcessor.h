//
// Created by chen on 2018/5/11.
//
#include <vector>
#include <string>
#ifndef FAMILYMART_STRINGPROCESSOR_H
#define FAMILYMART_STRINGPROCESSOR_H
using namespace std;
class StringProcessor {
public:
    vector<string> split(const string& mLine,const string& splitSignStr);
    bool hasStartWith(const string& singlePattern,const string& unjudgedLine);
    float stringToFloat(const string& str);
    int stringToInt(const string& str);
private:
    template <class Type>
    Type stringToNum(const string& str);


};


#endif //FAMILYMART_STRINGPROCESSOR_H
