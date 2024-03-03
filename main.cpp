#include "Computer.h"
#include "Human.h"
#include "Referee.h"
#include "Player.h"
int main() {
    Computer c;
    std::string name = "Player";
    Human p1(name);
    Referee r;
    Player* p;
    r.refGame(&p1, &c);
    
}