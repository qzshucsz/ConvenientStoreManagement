//
// Created by chen on 2018/5/11.
//
#include <sstream>
#include <iterator>
#include <iostream>
#include "StringProcessor.h"

vector<string> StringProcessor::split(const string &mLine,const string& splitSignStr) {
    std::cout<<"split string"<<endl;
    istringstream mStrStream(mLine);
    istringstream mSign(splitSignStr);
    vector<string> strs{istream_iterator<string>(mStrStream),istream_iterator<string>(mSign)};
    return strs;
}

bool StringProcessor::hasStartWith(const string &singlePattern, const string &unjudgedLine) {
    return unjudgedLine.compare(0,singlePattern.length(),singlePattern)==0;
}

template <class Type>
Type StringProcessor::stringToNum(const string &str) {
    istringstream iss(str);
    Type num;
    iss >> num;
    return num;
}

float StringProcessor::stringToFloat(const string &str) {
    return stringToNum<float>(str);
}

int StringProcessor::stringToInt(const string &str) {
    return stringToNum<int>(str);
}


