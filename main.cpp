#include "BubbleSort.h"
#include <iostream>
#include <vector>
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
int main() {
    std::vector<int> input;
    int x;
    do{
        std::cin >> x;
        input.push_back(x);
    }
    while(std::cin.peek() != '\n');
    QuickSort QS;
    std::vector<int> test{1,2,5,4,2};
    std::vector<int> sorted = QS.sort(test);
    RecursiveBinarySearch RBS;
    //bool found = RBS.search(sorted, 1);
    //std::cout << found;
    for (auto i : sorted) {
        std::cout << i << std::endl;
    }
}