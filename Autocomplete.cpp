#include "Autocomplete.h"
#include <map>



void Autocomplete::insert(std::string word) {
    TrieNode* traverse = trie.root;
    for(char& c : word) {
        if (traverse->children.find(c) == traverse->children.end())
        {
            //make new node
            traverse->children[c] = new TrieNode();
        }
        traverse = traverse->children[c];
    }
    traverse->isEndOfWord = true;
}

std::vector<std::string> Autocomplete::getSuggestions(std::string word) {
    TrieNode* traverse = trie.root;
    std::vector<std::string> results;
    for(char& c : word) {
        //check if the node exist for the current character in the Trie:
        if (traverse->children.find(c) != traverse->children.end()) {
            traverse = traverse->children[c]; //first character found and following down the chain
        }
        else {
            return results;//word not found
        }
    }
    if (traverse->isEndOfWord) {
        results.push_back(word);
    }

    findAllWords(traverse, word, results);
    return results;
}

 void Autocomplete::findAllWords(TrieNode* node, std::string prefix, std::vector<std::string>& suggestions) {
        if (node->isEndOfWord) {
            suggestions.push_back(prefix);
        }

        for (auto& child : node->children) {
            findAllWords(child.second, prefix + child.first, suggestions);
        }
    }