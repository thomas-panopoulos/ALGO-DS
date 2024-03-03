#include "Human.h"

    char Human::makeMove()
    {
        std::cout << "Enter move:";
        std::cin >> this->move;
        return this->move;
    };