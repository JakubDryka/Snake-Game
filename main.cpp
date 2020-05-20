#include <iostream>
#include <array>
#include <conio.h>
#include "Board.h"
#include <cstdlib>
#include <windows.h>
#include <ctime>

int main()
{
    srand( time( NULL ) );
    Player player1;
    player1.addNewSnakePart();

    Board board;
    board.initializeBoard(player1);
    board.printBoard(player1);
    board.generateFood(player1);

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
        board.checkIfPlayerAteFood(player1);
        board.checkIfPlayerHitHimself(player1);
        board.printBoard(player1);

        std::cout<<"Aktualny kierunek playera to "<<player1._playerDirection<<std::endl;
        std::cout<<"koordynaty food to "<<board._foodXcord<<" i "<<board._foodYcord<<std::endl;
        std::cout<<"Glowa weza znajduje sie na "<<player1._snakeBody.front().first<<", "<<player1._snakeBody.front().second<<std::endl;
        std::cout<<"Rozmiar weza to "<<player1._snakeBody.size()<<std::endl;
        std::cout<<"Wcisnij ESC aby zamknac"<<std::endl;
        std::cout<<"Liczba zdobytych punktow: "<<player1._points<<std::endl;
    } while (input1 != '\x1B' && board.gameEnded == false);
    board.gameEnd(player1);



    return 0;
}

