#include <iostream>
#include <array>
#include <conio.h>
#include "Board.h"
#include "GameController.h"

int main()
{
    Player player1;
    GameController game1;
    Board board;
    board.initializeBoard(player1);
    board.printBoard();

    char exitCharacter;
    char inputFromPlayer;
    std::cout<<("Wcisnij ESC aby zamknac" );
    while(exitCharacter != '\x1B')
    {
        inputFromPlayer = getch();
        exitCharacter = inputFromPlayer;
        game1.splitInput(inputFromPlayer, player1, board);
    }
    return 0;
}
