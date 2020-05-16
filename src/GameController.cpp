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
                player1._playerDirection = 'w';
            }
            break;

            case LEFT_ARROW:
            case 'a':
            {
                player1._playerDirection = 'a';
            }
            break;

            case DOWN_ARROW:
            case 's':
            {
                player1._playerDirection = 's';
            }
            break;

            case RIGHT_ARROW:
            case 'd':
            {
                player1._playerDirection = 'd';
            }
            break;
        }
}

void GameController::movePlayer(Player player1)
{
    switch(player1._playerDirection)
    {
            case 'w':
            {
                player1._playerYcord = player1._playerYcord - 1;
            }
            break;

            case 'a':
            {
                player1._playerXcord = player1._playerYcord - 1;
            }
            break;

            case 's':
            {
                player1._playerYcord = player1._playerYcord + 1;
            }
            break;

            case 'd':
            {
                player1._playerXcord = player1._playerYcord + 1;
            }
            break;
    }
}
