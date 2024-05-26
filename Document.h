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
    int current_borrowed;
    Document(string name, int id, int license_limit) : name(name), id(id), license_limit(license_limit), current_borrowed(0) {};
    void increment() { current_borrowed++;};
    void decrement() { current_borrowed--;}
};

#endif