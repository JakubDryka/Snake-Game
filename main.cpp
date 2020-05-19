#include <iostream>
#include <array>
#include <conio.h>
#include "Board.h"
#include "GameController.h"
#include "Player.h"
#include <cstdlib>
#include <windows.h>

int main()
{
    Player player1;
    Board board;
    board.initializeBoard(player1);
    board.printBoard(player1);
        char input1;

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
        system("cls");
        std::cout<<player1._playerDirection<<std::endl;
        board.printBoard(player1);
        std::cout<<("Wcisnij ESC aby zamknac")<<std::endl;
    } while (input1 != '\x1B');


    return 0;
}



//    char input1;
//
//    do
//    {
//        Sleep(500);
//        if(_kbhit())
//        {
//            input1 = getch();
//            game1.Input(input1, player1);
//            FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
//        }
//        player1.movePlayer();
//        system("cls");
//        std::cout<<player1._playerDirection<<std::endl;
//        board.printBoard(player1);
//        std::cout<<("Wcisnij ESC aby zamknac")<<std::endl;
//    } while (input1 != '\x1B');

