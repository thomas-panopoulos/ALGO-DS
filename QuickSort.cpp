#include "QuickSort.h"
#include <algorithm>
#include <vector>
#include <iostream>
std::vector<int> QuickSort::sort(std::vector<int> list) {
    int pivotCount =0;
    int pivot;
    if (list.size() <= 1)
        return list;
    if (list.size() > 3) {
        pivot = list.at(2);
    }
    else {pivot = list[list.size() / 2];}
    
    std::vector<int> left, right, result;
    for (int i = 0; i < list.size(); i++) {
        if (list[i] < pivot) {
            left.push_back(list[i]);
        }
        else if (list[i] > pivot) {
            right.push_back(list[i]);
        }
        else if (list[i] == pivot) {
            pivotCount++;
            //std::cout << "test" << std::endl;
        }

    }

    left = sort(left);
    right = sort(right);

    result.insert(result.end(), left.begin(), left.end());
    for (int i = 0; i < pivotCount; i++) {
    result.push_back(pivot);
    }
    result.insert(result.end(), right.begin(), right.end());

    return result;
}