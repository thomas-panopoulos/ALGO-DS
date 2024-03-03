#pragma once
#include "Player.h"
class Computer : public Player {
    private:
    std::string name = "Computer";
    public:
    char makeMove();
    std::string getName() { return this->name; }
};