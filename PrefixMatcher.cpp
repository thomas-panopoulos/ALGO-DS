#include "PrefixMatcher.h"

void PrefixMatcher::insert(std::string address, int router) {
    PrefixTrieNode* traverse = trie.root;
    for (char c : address) {
        if (traverse->children.find(c) == traverse->children.end()) {
            traverse->children[c] = new PrefixTrieNode();
        }
        traverse = traverse->children[c]; //set traverse to next depth on tree
    }
    traverse->routerNumber = router; // set router number at tail of branch
}


int PrefixMatcher::selectRouter(std::string address) {
    PrefixTrieNode* traverse = trie.root;
    int selectedRouter = -1;

    for (char c : address) {
        if (traverse->children.find(c) != traverse->children.end()) {
            traverse = traverse->children[c];
        }
        if (traverse->routerNumber != -1) {
            selectedRouter = traverse->routerNumber;
        }
        else {
            break; //not found 
        }
    }
    return selectedRouter;
}