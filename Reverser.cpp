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
    if (str.length() == 1) {
        return str;
    }
    else {
        return str.back() + reverseString(str.substr(0, str.length() - 1));
    }
}

