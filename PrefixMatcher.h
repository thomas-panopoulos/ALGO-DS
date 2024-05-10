#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <vector>
#include <string>
#include <iostream>
#include "prefixTrie.h"

class PrefixMatcher {
    public:
    PrefixTrie trie;
    int selectRouter(std::string networkAddress);
    void insert(std::string address, int routerNumber);
};


#endif