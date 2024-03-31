#include "Finder.h"
#include <string>
#include <iostream>
#include<vector>
int main() {
    Finder f;
    std::string s1 = "4634554567";
    std::string s2 = "45689";
    std::vector<int> returned = f.findSubstrings(s1,s2);
    for (int i = 0; i < returned.size() -1; i++ )
    {std::cout << returned.at(i) << std::endl;}
}