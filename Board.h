#ifndef BOARD_H
#define BOARD_H
#include <array>
#include "Player.h"

const unsigned BOARD_HEIGHT = 10;
const unsigned BOARD_WIDTH = 20;
typedef std::array<std::array<char, BOARD_WIDTH>, BOARD_HEIGHT> GameBoardArray;

class Board
{
    public:
    GameBoardArray _board;
    void printBoard(Player player1);
    void makeFrame();
    Board();
    void initializeBoard(Player player1);
};

#endif // BOARD_H
