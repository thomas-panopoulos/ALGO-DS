#include "LinkedList.h"
#include <numeric>
#include <limits>
#include <iostream>
#include <string>
LinkedList::LinkedList(int* array, int len) {
    head = new Node(*(array));

    for (int i = 1; i < len; i++) {

        Node* newNode = new Node(*(array+i));
        Node* traverse = head;
        //go to end of list using temp node and jump pointer chain, then append new node to tail.
        while (traverse->getLink() != nullptr) {

            traverse = traverse->getLink();

        }

        traverse->setLink(newNode);
    }
}
void LinkedList::insertPosition(int pos, int newNum) {
    Node* traverse = head;
    Node* newNode = new Node(newNum);
    int index = 1;
    if (pos <= 1 || head == nullptr) {
        newNode->setLink(head);
        this->head = newNode;
        return;
    }

    while (traverse->getLink() != nullptr && index < pos - 1) {
        traverse = traverse->getLink();
        index++;
    }

    newNode->setLink(traverse->getLink());
    traverse->setLink(newNode);
}


bool LinkedList::deletePosition(int pos) {
    if (head == nullptr) {
        return false;
    }

    Node* traverse = head;

    if (pos == 1) {
        this->head = traverse->getLink();
        delete traverse;
        return true;
    }
    for (int i = 1; i < pos-1 && traverse->getLink() != nullptr; i++) {
        traverse = traverse->getLink();
    }
    if (traverse == nullptr || traverse->getLink() == nullptr) {
        return false;
    }

    Node* temp = traverse->getLink();
    traverse->setLink(temp->getLink());
    delete temp;
    return true;
}
int LinkedList::get(int pos) {
    if (head == nullptr || pos <= 0) {
        return std::numeric_limits<int>::max();
    }

    Node* traverse = head;
    for (int i = 1; i < pos; i++) {
        traverse = traverse->getLink();
        if (traverse == nullptr) {
            return std::numeric_limits<int>::max();
        }
    }
    return traverse->getData();
}
int LinkedList::search(int target) {

    if (head == nullptr || target <= 0) {
        return -1;
    }
    int index = 1;
    Node* traverse = head;

    while (traverse != nullptr) {
        
        if (traverse->getData() == target) {
            return index;
        }
        else {
            traverse = traverse->getLink();
            index++;
        }
    }
    return -1;
}
void LinkedList::printList() { 
    Node* temp = head; 
    std::string str;
    // Check for empty list. 
    if (head == nullptr) { 
        return; 
    } 
  
    // Traverse the list. 
    str.push_back('[');
    while (temp != nullptr) { 
        str = str + std::to_string(temp->getData());
        str.push_back(' '); 
        temp = temp->getLink(); 
    }
    str.pop_back();
    str.push_back(']');
    std::cout << str << std::endl;
} 

LinkedList::~LinkedList() {
    Node* traverse = head;
        while (traverse != nullptr) {
            Node* next = traverse->getLink();
            delete traverse;
            traverse = next;
        }
        this->head = nullptr;
}