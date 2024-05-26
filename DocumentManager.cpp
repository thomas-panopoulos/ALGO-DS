#include <string>
#include <vector>
#include "Document.h"
#include "DocumentManager.h"
#include <iterator>
#include <algorithm>
using namespace std;

void DocumentManager::addDocument(string name, int id, int license_limit) {
    Document doc = Document(name, id, license_limit);
    this->documents.push_back(doc);
}

void DocumentManager::addPatron(int patronID) {
    patrons.push_back(patronID);
}

int DocumentManager::search(string name) {
    for (auto i : this->documents) {
        if (i.name == name)
            return i.id;
    }
    return 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    bool idfound = 0;
    bool docufound = 0;
    for (auto i : this->patrons) {
        if (i == patronID) {
            idfound = 1;
        }
    }
    for (auto i : this->documents) {
        if (i.id == docid) {
            docufound = 1;
            if (i.borrowed.size() == i.license_limit) {
                return false;
            }
            i.borrowed.push_back(patronID);
            return true;
        }
    }
    if (docufound == 0 || idfound == 0) {
        return false;
    }
}

void DocumentManager::returnDocument(int docid, int patronID) {
    for (auto i : this->documents) {
        if (i.id == docid) {
            vector<int>::iterator it = std::find(i.borrowed.begin(), i.borrowed.end(), patronID);
            if (it != i.borrowed.end()) {
                i.borrowed.erase(it);
            }
        }
    }
}