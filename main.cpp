#include <iostream>
#include <array>
#include <conio.h>
#include "Board.h"

int main()
{
    Player player1;
    Board board;
    board.initializeBoard(player1);
    board.printBoard();

    char inputFromPlayer;
    {
        inputFromPlayer = getch();

        std::puts( "Wcisnij ESC aby zamknac" );
    } while( getch() != '\x1B' );
    return 0;
}
