#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
#include <iostream>

class Human : public Player {
    private:
    Move* move;
    std::string name;
    public:
    Human() {this->name = "Human";}
    Human(std::string name) : name(name) {}
    Move* makeMove();
    std::string getName() { return this->name; }

};

#endif