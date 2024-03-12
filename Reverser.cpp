#include "Reverser.h"
#include <iostream>
int Reverser::reverseDigit(int num) {
    static int rev_num;
    if (num <= 0) {
        return rev_num;
    }
    rev_num = rev_num* 10 + num%10;
    reverseDigit(num/10);
}

std::string Reverser::reverseString(std::string str) {
    static std::string reversed = str;
    static int n = str.length()-1; static int i = 0;
    if (n<=i) {return reversed;}
    std::swap(reversed[i],reversed[n]);
    n--, i++;

    reverseString(reversed);
}