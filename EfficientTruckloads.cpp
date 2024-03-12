#include "EfficientTruckloads.h"
#include <unordered_map>
#include <string>
#include <iostream>
int EfficientTruckloads::numTrucks(int numCrates, int maxLoad) {
        static std::unordered_map<std::string,int> memoization;
        std::string name = std::to_string(numCrates) + "-" + std::to_string(maxLoad);
        if(memoization.contains(name)) return memoization[name];

        if (numCrates <= maxLoad) {
            return 1;
        }
        if (numCrates % 2) {
            memoization[name] = numTrucks(numCrates%maxLoad+numCrates/2, maxLoad) + numTrucks(numCrates/2, maxLoad);
        }
        memoization[name] = 2 * numTrucks(numCrates/2, maxLoad);
        return memoization[name];
    }