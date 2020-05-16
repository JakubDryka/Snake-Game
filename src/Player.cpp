#include "Player.h"

Player::Player()
{

}

void Player::movePlayer()
{
    switch(_playerDirection)
    {
            case UP_ARROW:
            {
                this->_playerYcord -= 1;
            }
            break;

            case LEFT_ARROW:
            {
                this->_playerXcord -= 1;
            }
            break;

            case DOWN_ARROW:
            {
                this->_playerYcord += 1;
            }
            break;

            case RIGHT_ARROW:
            {
                this->_playerXcord += 1;
            }
            break;
    }
}

void Player::setDirection(char newDirection)
{
    _playerDirection = newDirection;
}

char Player::getDirection()
{
    return _playerDirection;
}
