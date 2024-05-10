#ifndef TRIE_H
#define TRIE_H
#include <vector>
#include <unordered_map>
struct PrefixTrieNode {
    public:
    int routerNumber;
    std::unordered_map<char, PrefixTrieNode*> children;

    PrefixTrieNode() : routerNumber(-1) {};
};

class PrefixTrie {
    public:
    PrefixTrieNode* root;
    PrefixTrie() {
        root = new PrefixTrieNode();
    }
};

#endif