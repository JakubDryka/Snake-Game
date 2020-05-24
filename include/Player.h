#ifndef PLAYER_H
#define PLAYER_H

#define UP_ARROW    72
#define LEFT_ARROW  75
#define DOWN_ARROW  80
#define RIGHT_ARROW 77

#include <deque>
#include <iostream>
#include <array>

const unsigned BOARD_HEIGHT = 10;
const unsigned BOARD_WIDTH = 20;
typedef std::array<std::array<char, BOARD_WIDTH>, BOARD_HEIGHT> GameBoardArray;

class Player
{
    unsigned int _playerStartXcord = 1;
    unsigned int _playerStartYcord = 1;
    unsigned int _points = 0;
    char _playerDirection = 'd';
    std::deque<std::pair<int, int>> _snakeBody;
public:
    Player();
    void addNewSnakePart();
    void movePlayer();
    void useInput(char inputFromPlayer);
    void addPoints(int amount);
    int getPoints();
    int getSnakeSize();
    int getSnakesPartCordX(int numberOfPart);
    int getSnakesPartCordY(int numberOfPart);
};

#endif // PLAYER_H
