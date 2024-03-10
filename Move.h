#pragma once
#include <vector>
#include <string>
class Move {
    protected:
    std::string name;
    std::vector <std::string>moves;
    public:
    std::string getName() {return this->name;}
};