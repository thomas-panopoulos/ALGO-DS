#include "RecursiveBinarySearch.h"
#include <vector>
bool RecursiveBinarySearch::search(std::vector<int> list, int num) {
    if (list[list.size() / 2] == num) {
        return true;
    }
    if (list[list.size() / 2] > num) {
        std::vector<int>::const_iterator start = list.begin();
        std::vector<int>::const_iterator end = list.end()-list.size() / 2 -1;
        std::vector<int> next(start,end);
        search(next, num);
    }
    if (list[list.size() / 2] < num) {
        std::vector<int>::const_iterator start = list.begin()+list.size() / 2 + 1;
        std::vector<int>::const_iterator end = list.end();
        std::vector<int> next(start,end);
        search(next, num);
    }
    return false;
}