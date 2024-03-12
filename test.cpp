#include <iostream>
#include <string>
#include "Reverser.h"
#include "Truckloads.h"
#include "EfficientTruckloads.h"

int main() {
    Reverser r;
    Truckloads t;
    EfficientTruckloads et;
    std::cout << r.reverseDigit(123456) << std::endl;
    std::cout << r.reverseString("123456") << std::endl;
    std::cout << t.numTrucks(1024,5) << std::endl;
    std::cout << et.numTrucks(1024,5) << std::endl;
}