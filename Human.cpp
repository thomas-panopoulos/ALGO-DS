#include "Human.h"
#include "Move.h"
#include "Ninja.h"
#include "Monkey.h"
#include "Rock.h"
#include "Paper.h"
#include "Pirate.h"
#include "Robot.h"
#include "Zombie.h"
#include "Move.h"

Move* Human::makeMove() {
    std::cin >> this->moveName;
    if (this->moveName == "Ninja") {this->move = new Ninja();}
    if (this->moveName == "Monkey") {this->move = new Monkey();}

}