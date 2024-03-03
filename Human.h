#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
#include <iostream>

class Human : public Player {
    private:
    char move;
    std::string name;
    public:
    Human() {this->name = "default constructor";}
    Human(std::string name) : name(name) {}
    char makeMove();
    std::string getName() { return this->name; }

};

#endif