#include "GameController.h"

GameController::GameController()
{

}

void GameController::splitInput(char inputFromPlayer, Player player1, Board board1)
{
    switch(inputFromPlayer)
        {
            case UP_ARROW:
            case 'w':
            {
                //player1.move();
                board1.printBoard();
            }
            break;

            case LEFT_ARROW:
            case 'a':
            {
                board1.printBoard();
            }
            break;

            case DOWN_ARROW:
            case 's':
            {
                board1.printBoard();
            }
            break;

            case RIGHT_ARROW:
            case 'd':
            {
                board1.printBoard();
            }
            break;
        }
}
