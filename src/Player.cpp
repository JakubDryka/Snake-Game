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
                _snakeBody.front().second = 8;
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
                _snakeBody.front().second = 8;
            }
            else
            {
                _snakeBody.push_front(_snakeBody.back());
                _snakeBody.pop_back();
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
                _snakeBody.front().first = 18;
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
                _snakeBody.front().first = 18;
            }
            else
            {
                _snakeBody.push_front(_snakeBody.back());
                _snakeBody.pop_back();
                _snakeBody.front().first = _snakeBody.at(1).first - 1;
            }
        }

    }
    break;

    case 's':
    {
        if(_snakeBody.size() <= 1)
        {
            if(_snakeBody.front().second == 8)
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
            if(_snakeBody.front().second == 8)
            {
                _snakeBody.push_front(_snakeBody.back());
                _snakeBody.pop_back();
                _snakeBody.front().second = 1;
            }
            else
            {
                _snakeBody.push_front(_snakeBody.back());
                _snakeBody.pop_back();
                _snakeBody.front().second = _snakeBody.at(1).second + 1;
            }
        }

    }
    break;
    case 'd':
    {
        if(_snakeBody.size() <= 1)
        {
            if(_snakeBody.front().first == 18)
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
            if(_snakeBody.front().first == 18)
            {
                _snakeBody.push_front(_snakeBody.back());
                _snakeBody.pop_back();
                _snakeBody.front().first = 1;
            }
            else
            {
                _snakeBody.push_front(_snakeBody.back());
                _snakeBody.pop_back();
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

void Player::addNewSnakePart()
{
    std::pair<int, int> cords;
    if(_snakeBody.size() <= 0)
    {
        cords.first = this->_playerStartXcord;
        cords.second = this->_playerStartYcord;
    }
    else
    {
        switch(this->_playerDirection)
        {
        case 'w':
        {
            if(_snakeBody.front().second == 1)
            {
                cords.second = 8;
            }
            else
            {
               cords.second = _snakeBody.front().second - 1;
            }
            cords.first = _snakeBody.front().first;
        }
        break;

        case 'a':
        {
            if(_snakeBody.front().first == 1)
            {
                cords.first = 18;
            }
            else
            {
               cords.first = _snakeBody.front().first - 1;
            }
            cords.second = _snakeBody.front().second;
        }
        break;

        case 's':
        {
            if(_snakeBody.front().second == 8)
            {
                cords.second = 1;
            }
            else
            {
               cords.second = _snakeBody.front().second + 1;
            }
            cords.first = _snakeBody.front().first;
        }
        break;

        case 'd':
        {
            if(_snakeBody.front().first == 18)
            {
                cords.first = 1;
            }
            else
            {
               cords.first = _snakeBody.front().first + 1;
            }
            cords.second = _snakeBody.front().second;
        }
        break;
        }
    }
    std::cout<<"Pod koniec funkcji cords wynosza : "<<cords.first<<cords.second<<std::endl;
    this->_snakeBody.push_front(cords);
}
