#include "GameController.h"

GameController::GameController()
{

}

void GameController::Input(char inputFromPlayer, Player player1)
{
    switch(inputFromPlayer)
        {
            case UP_ARROW:
            case 'w':
            {
                player1._playerDirection = UP_ARROW;
            }
            break;

            case LEFT_ARROW:
            case 'a':
            {
                player1._playerDirection = LEFT_ARROW;
            }
            break;

            case DOWN_ARROW:
            case 's':
            {
                player1._playerDirection = DOWN_ARROW;
            }
            break;

            case RIGHT_ARROW:
            case 'd':
            {
                player1._playerDirection = RIGHT_ARROW;
            }
            break;
        }
}

void GameController::movePlayer(Player player1)
{
    switch(player1._playerDirection)
    {
            case UP_ARROW:
            {
                player1._playerYcord -= 1;
            }
            break;

            case LEFT_ARROW:
            {
                player1._playerXcord -= 1;
            }
            break;

            case DOWN_ARROW:
            {
                player1._playerYcord += 1;
            }
            break;

            case RIGHT_ARROW:
            {
                player1._playerXcord += 1;
            }
            break;
    }
}
