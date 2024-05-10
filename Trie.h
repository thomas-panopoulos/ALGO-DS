#ifndef TRIE_H
#define TRIE_H
#include <vector>
#include <unordered_map>
struct TrieNode {
    public:
    bool isEndOfWord;
    std::unordered_map<char, TrieNode*> children;

    TrieNode()
    {
        isEndOfWord = false;
    }
};

class Trie {
    public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
};

#endif