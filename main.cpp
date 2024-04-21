#include "BubbleSort.h"
#include <iostream>
#include <vector>
#include <string>
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
    std::vector<int> sorted = QS.sort(input);
    RecursiveBinarySearch RBS;
    bool found = RBS.search(sorted, 1);
    found == 0 ? std::cout << "false" : std::cout << "true";
    for (auto i : sorted) {
        std::cout <<' '+ std::to_string(i);
    }
    std::cout << "\n";
}