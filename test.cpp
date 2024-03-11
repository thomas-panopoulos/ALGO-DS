#include <iostream>
#include <string>
#include "Reverser.h"



int main() {
    Reverser r;
    std::cout << r.reverseDigit(-1) << std::endl;
    std::cout << r.reverseString("123456") << std::endl;
}