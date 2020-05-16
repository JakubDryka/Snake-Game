#include <iostream>
#include <array>
#include <conio.h>
#include "Board.h"
#include "GameController.h"
#include <cstdlib>
#include <windows.h>

int main()
{
    Player player1;
    GameController game1;
    Board board;
    board.initializeBoard(player1);
    board.printBoard(player1);
    std::cout<<("Wcisnij ESC aby zamknac");

    while(player1._playerXcord)
    {
        Sleep(900);
        if(_kbhit())
        {
            char input1 = getch();
            game1.Input(input1, player1);
        }
        game1.movePlayer(player1);
        system("cls");
        board.printBoard(player1);
    }
    return 0;
}
