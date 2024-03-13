#include "Reverser.h"
#include <iostream>
#include <string>
#include <cmath>
int Reverser::reverseDigit(int num) {

    if (num < 0) {
        return -1;
    }
    if (num < 10) {
        return num;
    }
    int numDigits = ceil(log10(num));
    
    
    return num%10* pow(10, (numDigits-1)) + reverseDigit(num/10);;
}

std::string Reverser::reverseString(std::string str) {
    static std::string reversed;
    if(str.length() > 0) {
        reversed.push_back(str.back());
        str.pop_back();
        reverseString(str);
    }
    return reversed;
}

