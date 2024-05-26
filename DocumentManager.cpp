#include <string>
#include <vector>
#include "Document.h"
#include "DocumentManager.h"
#include <iterator>
#include <algorithm>
#include <iostream>
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
    //cout << patronID << endl << docid << endl;
    Document* target;
    for (auto i : this->patrons) {
        if (i == patronID) {
            idfound = 1;
        }

    }
    if (idfound == 0) {
        return false;
    }
    for (auto i : this->documents) {
        if (i.id == docid) {
            target = &i;
            if (i.borrowed.size()-1 == (i.license_limit)) {
                return false;
            }/*
            vector<int>::iterator it = std::find(i.borrowed.begin(), i.borrowed.end(), patronID);
            if (it != i.borrowed.end()) {
                return false;
            }*/

        }
    }
    if (std::find(target->borrowed.begin(), target->borrowed.end(), patronID) != target->borrowed.end()) {
        return true;
    }
    target->borrowed.push_back(patronID);
    return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    for (auto j : this->patrons) {
        if (j == patronID) {
            for (auto i : this->documents) {
                if (i.id == docid) {
                    vector<int>::iterator it = std::find(i.borrowed.begin(), i.borrowed.end(), patronID);
                    if (it != i.borrowed.end()) {
                        i.borrowed.erase(it);
                    }
                }
            }
            break;
        }

    }
}