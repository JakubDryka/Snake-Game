#ifndef BOARD_H
#define BOARD_H
#include <array>
#include <cstdlib>
#include "windows.h"
#include "Player.h"

class Board
{
    void makeFrame();
    std::pair<int, int> _foodCord;
    GameBoardArray _board;
public:
    bool gameEnded = false;
    void printBoard(Player player1);
    void generateFood(Player player1);
    void checkIfPlayerAteFood(Player &player1);
    void checkIfPlayerHitHimself(Player &player1);
    void initializeBoard(Player player1);
    void gameEnd(Player player1);
    void printStartMenu();
    Board();
};

#endif // BOARD_H
