#include <string>
#include <vector>
#include "Document.h"
#include "DocumentManager.h"
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    DocumentManager ds;
    ds.addDocument("test",1,1);
    ds.addDocument("test2",2,1);
    ds.addPatron(1);
    ds.addPatron(2);
    cout << ds.borrowDocument(1,1) << endl;
    cout << ds.borrowDocument(1,1) << endl;
    cout << ds.borrowDocument(1,2) << endl;
    cout << ds.borrowDocument(2,2) << endl;
}