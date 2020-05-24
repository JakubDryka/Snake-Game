#include <iostream>
#include <array>
#include <conio.h>
#include "Board.h"
#include <cstdlib>
#include <windows.h>
#include <ctime>

int main()
{
    char inputFromPlayer;
    Board gameboard;
    gameboard.printStartMenu();
    do
    {
        if(_kbhit())
        {
            inputFromPlayer = getch();
            if(inputFromPlayer == '\x1B')
            {
                return 0;
            }
            else if(inputFromPlayer == 'p' || inputFromPlayer == 'P')
            {
                srand( time( NULL ) );
                Player player1;
                player1.addNewSnakePart();
                gameboard.initializeBoard(player1);
                gameboard.printBoard(player1);
                gameboard.generateFood(player1);

                do
                {
                    Sleep(500);
                    if(_kbhit())
                    {
                        inputFromPlayer = getch();
                        player1.useInput(inputFromPlayer);
                        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
                    }
                    player1.movePlayer();
                    gameboard.checkIfPlayerHitHimself(player1);
                    gameboard.checkIfPlayerAteFood(player1);
                    gameboard.printBoard(player1);
                }
                while (inputFromPlayer != '\x1B' && gameboard.gameEnded == false);
                gameboard.gameEnd(player1);
                return 0;
            }
        }
    }
    while(inputFromPlayer != '\x1B');
    return 0;
}

