#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Document {
    public:
    string name;
    int id, license_limit;
    vector<int> borrowed;
    int current_borrowed = borrowed.size();
    Document(string name, int id, int license_limit) : name(name), id(id), license_limit(license_limit) {};
};

#endif