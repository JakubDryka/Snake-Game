#ifndef PLAYER_H
#define PLAYER_H

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
    private:
        unsigned int _points = 0;
};

#endif // PLAYER_H
