#include "Player.h"


Player::Player()
{

}

void Player::movePlayer()
{
    switch(this->_playerDirection)
    {
            case 'w':
            {
                if(this->_playerYcord == 1)
                {
                    this->_playerYcord = 8;
                }
                else
                {
                  this->_playerYcord = this->_playerYcord - 1;
                }
            }
            break;

            case 'a':
            {
                if(this->_playerXcord == 1)
                {
                    this->_playerXcord = 18;
                }
                else
                {
                  this->_playerXcord = this->_playerXcord - 1;
                }
            }
            break;

            case 's':
            {
                if(this->_playerYcord == 8)
                {
                    this->_playerYcord = 1;
                }
                else
                {
                  this->_playerYcord = this->_playerYcord + 1;
                }
            }
            break;

            case 'd':
            {
                if(this->_playerXcord == 18)
                {
                    this->_playerXcord = 1;
                }
                else
                {
                  this->_playerXcord = this->_playerXcord + 1;
                }
            }
            break;
    }
}

void Player::useInput(char inputFromPlayer)
{
    switch(inputFromPlayer)
        {
            case 'w':
            case UP_ARROW:
            {
                this->_playerDirection = 'w';
            }
            break;

            case 'a':
            case LEFT_ARROW:
            {
                this->_playerDirection = 'a';
            }
            break;

            case 's':
            case DOWN_ARROW:
            {
                this->_playerDirection = 's';
            }
            break;

            case 'd':
            case RIGHT_ARROW:
            {
                this->_playerDirection = 'd';
            }
            break;
        }
}

