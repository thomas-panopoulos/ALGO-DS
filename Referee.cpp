#include "Player.h"
#include "Referee.h"


Player* Referee::refGame(Player* player1, Player* player2) {
    switch(player1->makeMove()) {
        case 'R':
            if (player2->makeMove() == 'R') {
                return nullptr;
            }
            else if (player2->makeMove() == 'S') {
                return player1;
            }
            else if (player2->makeMove() == 'P') {
                return player2;
            }
            break;
        case 'S':
            if (player2->makeMove() == 'S') {
                return nullptr;
            }
            else if (player2->makeMove() == 'R') {
                return player2;
            }
            else if (player2->makeMove() == 'P') {
                return player1;
            }
            break;
        case 'P':
            if (player2->makeMove() == 'P') {
                return nullptr;
            }
            else if (player2->makeMove() == 'S') {
                return player2;
            }
            else if (player2->makeMove() == 'R') {
                return player1;
            }
            break;
    };
    return nullptr;
};