#ifndef BOARD_H
#define BOARD_H
#include <array>
#include <cstdlib>
#include "windows.h"
#include "Player.h"

const unsigned BOARD_HEIGHT = 10;
const unsigned BOARD_WIDTH = 20;
typedef std::array<std::array<char, BOARD_WIDTH>, BOARD_HEIGHT> GameBoardArray;

class Board
{
public:
    GameBoardArray _board;
    unsigned int _foodXcord = 21;
    unsigned int _foodYcord = 11;
    bool gameEnded = false;
    void printBoard(Player player1);
    void makeFrame();
    void generateFood(Player player1);
    void checkIfPlayerAteFood(Player &player1);
    void checkIfPlayerHitHimself(Player &player1);
    void initializeBoard(Player player1);
    void gameEnd(Player player1);
    void printData(Board board, Player player1);
    void printStartMenu();
    Board();
};

#endif // BOARD_H
