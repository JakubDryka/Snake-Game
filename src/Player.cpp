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
        if(_snakeBody.size() <= 1)
        {
            if(_snakeBody.front().second == 1)
            {
                _snakeBody.front().second = BOARD_HEIGHT - 2;
            }
            else
            {
                _snakeBody.front().second = _snakeBody.front().second - 1;
            }
        }
        else
        {
            if(_snakeBody.front().second == 1)
            {
                _snakeBody.push_front(_snakeBody.back());
                _snakeBody.pop_back();
                _snakeBody.front().first = _snakeBody.at(1).first;
                _snakeBody.front().second = BOARD_HEIGHT - 2;
            }
            else
            {
                _snakeBody.push_front(_snakeBody.back());
                _snakeBody.pop_back();
                _snakeBody.front().first = _snakeBody.at(1).first;
                _snakeBody.front().second = _snakeBody.at(1).second - 1;
            }
        }
    }
    break;

    case 'a':
    {
        if(_snakeBody.size() <= 1)
        {
            if(_snakeBody.front().first == 1)
            {
                _snakeBody.front().first = BOARD_WIDTH - 2;
            }
            else
            {
                _snakeBody.front().first = _snakeBody.front().first - 1;
            }
        }
        else
        {
            if(_snakeBody.front().first == 1)
            {
                _snakeBody.push_front(_snakeBody.back());
                _snakeBody.pop_back();
                _snakeBody.front().second = _snakeBody.at(1).second;
                _snakeBody.front().first = BOARD_WIDTH - 2;
            }
            else
            {
                _snakeBody.push_front(_snakeBody.back());
                _snakeBody.pop_back();
                _snakeBody.front().second = _snakeBody.at(1).second;
                _snakeBody.front().first = _snakeBody.at(1).first - 1;
            }
        }

    }
    break;

    case 's':
    {
        if(_snakeBody.size() <= 1)
        {
            if(_snakeBody.front().second == BOARD_HEIGHT - 2)
            {
                _snakeBody.front().second = 1;
            }
            else
            {
                _snakeBody.front().second = _snakeBody.front().second + 1;
            }
        }
        else
        {
            if(_snakeBody.front().second == BOARD_HEIGHT - 2)
            {
                _snakeBody.push_front(_snakeBody.back());
                _snakeBody.pop_back();
                _snakeBody.front().first = _snakeBody.at(1).first;
                _snakeBody.front().second = 1;
            }
            else
            {
                _snakeBody.push_front(_snakeBody.back());
                _snakeBody.pop_back();
                _snakeBody.front().first = _snakeBody.at(1).first;
                _snakeBody.front().second = _snakeBody.at(1).second + 1;
            }
        }

    }
    break;
    case 'd':
    {
        if(_snakeBody.size() <= 1)
        {
            if(_snakeBody.front().first == BOARD_WIDTH - 2)
            {
                _snakeBody.front().first = 1;
            }
            else
            {
                _snakeBody.front().first = _snakeBody.front().first + 1;
            }
        }
        else
        {
            if(_snakeBody.front().first == BOARD_WIDTH - 2)
            {
                _snakeBody.push_front(_snakeBody.back());
                _snakeBody.pop_back();
                _snakeBody.front().second = _snakeBody.at(1).second;
                _snakeBody.front().first = 1;
            }
            else
            {
                _snakeBody.push_front(_snakeBody.back());
                _snakeBody.pop_back();
                _snakeBody.front().second = _snakeBody.at(1).second;
                _snakeBody.front().first = _snakeBody.at(1).first + 1;;
            }

        }
        break;
    }
    }
}


void Player::useInput(char inputFromPlayer)
{
    switch(inputFromPlayer)
    {
    case 'w':
    case 'W':
    case UP_ARROW:
    {
        this->_playerDirection = 'w';
    }
    break;

    case 'a':
    case 'A':
    case LEFT_ARROW:
    {
        this->_playerDirection = 'a';
    }
    break;

    case 's':
    case 'S':
    case DOWN_ARROW:
    {
        this->_playerDirection = 's';
    }
    break;

    case 'd':
    case 'D':
    case RIGHT_ARROW:
    {
        this->_playerDirection = 'd';
    }
    break;
    }
}

void Player::addNewSnakePart()
{
    std::pair<int, int> newcords;
    if(_snakeBody.size() <= 0)
    {
        newcords.first = this->_playerStartXcord;
        newcords.second = this->_playerStartYcord;
    }
    else
    {
        switch(this->_playerDirection)
        {
        case 'w':
        {
            if(_snakeBody.front().second == 1)
            {
                newcords.second = 8;
            }
            else
            {
                newcords.second = _snakeBody.front().second - 1;
            }
            newcords.first = _snakeBody.front().first;
        }
        break;

        case 'a':
        {
            if(_snakeBody.front().first == 1)
            {
                newcords.first = 18;
            }
            else
            {
                newcords.first = _snakeBody.front().first - 1;
            }
            newcords.second = _snakeBody.front().second;
        }
        break;

        case 's':
        {
            if(_snakeBody.front().second == 8)
            {
                newcords.second = 1;
            }
            else
            {
                newcords.second = _snakeBody.front().second + 1;
            }
            newcords.first = _snakeBody.front().first;
        }
        break;

        case 'd':
        {
            if(_snakeBody.front().first == 18)
            {
                newcords.first = 1;
            }
            else
            {
                newcords.first = _snakeBody.front().first + 1;
            }
            newcords.second = _snakeBody.front().second;
        }
        break;
        }
    }
    this->_snakeBody.push_front(newcords);
}

void Player::addPoints(int amount)
{
    _points++;
}

int Player::getPoints()
{
    return _points;
}

int Player::getSnakeSize()
{
    return _snakeBody.size();
}

int Player::getSnakesPartCordX(int numberOfPart)
{
    return _snakeBody.at(numberOfPart).first;
}

int Player::getSnakesPartCordY(int numberOfPart)
{
    return _snakeBody.at(numberOfPart).second;
}
