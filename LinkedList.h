#include "Node.h"
#pragma Once

class LinkedList {
    private:
    Node* head;
    public:
    LinkedList(int* array, int len);
    void insertPosition(int pos, int newNum);
    bool deletePosition(int pos);
    int get(int pos);
    int search(int target);
    void printlist();
    LinkedList() : head(nullptr) {};

};