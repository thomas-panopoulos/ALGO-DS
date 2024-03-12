#include "Truckloads.h"

int Truckloads::numTrucks(int numCrates, int maxLoad) {
        if (numCrates <= maxLoad) {
            return 1;
        }
        if (numCrates % 2) {
            return numTrucks(numCrates%maxLoad+numCrates/2, maxLoad) + numTrucks(numCrates/2, maxLoad);
        }
        return 2 * numTrucks(numCrates/2, maxLoad);
    }