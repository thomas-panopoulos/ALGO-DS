#include <iostream>
#include <string>
#include "Reverser.h"
#include "Truckloads.h"


int main() {
    Reverser r;
    Truckloads t;
    std::cout << r.reverseDigit(123456) << std::endl;
    std::cout << r.reverseString("123456") << std::endl;
    std::cout << t.numTrucks(1024,5) << std::endl;
}