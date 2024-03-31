#include "Finder.h"
using namespace std;
vector<int> Finder::findSubstrings(string s1, string s2) {
vector<int> result;
size_t found;
for(size_t i = 1; i <= s2.size(); i++) {
if (result.size() > 0) {
    size_t found = s1.find(s2.substr(0, i), result.at(i-2));
}

size_t found = s1.find(s2.substr(0, i),0);


if (found != string::npos) {
result.push_back(found);
} else {
//result.push_back(-1);
while (result.size() < s2.size()) {
    result.push_back(-1);
} 
}
}
return result;
}