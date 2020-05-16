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
//        class Player_Segment
//        {
//            public
//        };
        //std::deque < int> dane;
        unsigned int _playerXcord = 5;
        unsigned int _playerYcord = 5;
        char _playerDirection = UP_ARROW;
        void setDirection(char newDirection);
        char getDirection();

    protected:

    private:
        unsigned int _points = 0;
};

#endif // PLAYER_H
