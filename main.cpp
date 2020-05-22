#include <iostream>
#include <array>
#include <conio.h>
#include "Board.h"
#include <cstdlib>
#include <windows.h>
#include <ctime>

int main()
{
    char input1;
    Board board1;
    board1.printStartMenu();
    do
    {
        if(_kbhit())
        {
            input1 = getch();
            if(input1 == '\x1B')
            {
                return 0;
            }
            else if(input1 == 'p' || input1 == 'P')
            {
                srand( time( NULL ) );

                Player player1;
                player1.addNewSnakePart();

                board1.initializeBoard(player1);
                board1.printBoard(player1);
                board1.generateFood(player1);

                do
                {
                    Sleep(500);
                    if(_kbhit())
                    {
                        input1 = getch();
                        player1.useInput(input1);
                        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
                    }
                    player1.movePlayer();
                    board1.checkIfPlayerHitHimself(player1);
                    board1.checkIfPlayerAteFood(player1);
                    board1.printBoard(player1);
                }
                while (input1 != '\x1B' && board1.gameEnded == false);
                board1.gameEnd(player1);
                return 0;
            }
        }
    }
    while(input1 != '\x1B');
    return 0;
}

