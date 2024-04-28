#include <iostream>
#include "LinkedList.h"

int main() {
    int array[4] = {1, 2, 3, 4};
    LinkedList list(array, 4);
    list.insertPosition(10,9);
    list.printList();
    list.deletePosition(2);
    list.printList();
    int to_print = list.get(2);
    std::cout << to_print << std::endl;
    int to_search = list.search(2);
    std::cout << to_search << std::endl;
}