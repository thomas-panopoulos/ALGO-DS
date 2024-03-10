#pragma once
#include "Player.h"
#include "Move.h"
class Computer : public Player {
    private:
    std::string name = "Computer";
    public:
    Move* makeMove();
    std::string getName() { return this->name; }
};