#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <vector>
#include <string>
#include <iostream>
#include "Trie.h"
class Autocomplete {
    public:
    Trie trie;
    std::vector<std::string> getSuggestions(std::string partialWord);
    void insert(std::string word);
    void findAllWords(TrieNode* node, std::string prefix, std::vector<std::string>& suggestions);

};

#endif