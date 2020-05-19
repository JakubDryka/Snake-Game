#ifndef PLAYER_H
#define PLAYER_H

#define UP_ARROW    72
#define LEFT_ARROW  75
#define DOWN_ARROW  80
#define RIGHT_ARROW 77

#include <deque>


class Player
{
    public:
        Player();
        unsigned int _playerXcord = 1;
        unsigned int _playerYcord = 8;
        char _playerDirection = 'd';
        void movePlayer();
        void useInput(char inputFromPlayer);
        unsigned int _points = 0;
};

#endif // PLAYER_H
