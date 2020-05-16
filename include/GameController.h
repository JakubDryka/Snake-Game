#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "../Board.h"
#include "Player.h"

#define UP_ARROW    72
#define LEFT_ARROW  75
#define DOWN_ARROW  80
#define RIGHT_ARROW 77


class GameController
{
    public:
        GameController();
        void Input(char inputFromPlayer, Player player1);
        void movePlayer(Player player1);

    protected:

    private:
};

#endif // GAMECONTROLLER_H
