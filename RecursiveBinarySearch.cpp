#include "RecursiveBinarySearch.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
bool RecursiveBinarySearch::search(std::vector<int> list, int num) {
    if (list.empty()) {
        return 0;
    }

    auto mid = list.begin() + (list.end() - list.begin()) / 2;
    if (*mid == num) {
        return true;
    }   
    else if (*mid > num) {
        std::vector<int> next(list.begin(), mid);
        return search(next, num);
    }
    else {
        std::vector<int> next(mid+1, list.end());
        return search(next, num);
    }
}