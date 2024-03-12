#include "Reverser.h"
#include <iostream>
#include <string>
int Reverser::reverseDigit(int num) {
    static int rev_num = 0;
    if (num <= -1) {
        return -1;
    }
    if (num <= 0) {
        return rev_num;
    }
    rev_num = rev_num* 10 + num%10;
    reverseDigit(num/10);
    return rev_num;
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

