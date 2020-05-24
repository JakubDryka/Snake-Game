#include "Board.h"
#include <iostream>

Board::Board()
{

}

void Board::printBoard(Player player1)
{
    system("cls");
    for(unsigned int i=0; i< BOARD_HEIGHT ; i++)
    {
        for(unsigned int j=0; j< BOARD_WIDTH; j++)
        {
            bool havePrinted = false;
            for(unsigned int z=0; z< player1.getSnakeSize(); z++)
            {
                if(j == player1.getSnakesPartCordX(z) && i == player1.getSnakesPartCordY(z))
                {
                    havePrinted = true;
                    std::cout<< "S";
                    break;
                }
            }
            if(j ==_foodXcord && i == _foodYcord)
            {
                std::cout<< "X";
                havePrinted = true;
            }
            if(!havePrinted)
            {
                std::cout << this->_board[i][j];
            }
        }
        std::cout << std::endl;
    }
}



void Board::makeFrame()
{
    for(unsigned int i=0; i < BOARD_HEIGHT ; i++)
    {
        _board[i][0] = '|';
        _board[i][BOARD_WIDTH-1] = '|';
    }

    for(unsigned int j=0; j < BOARD_WIDTH ; j++)
    {
        _board[0][j] = '-';
        _board[BOARD_HEIGHT-1][j] = '-';
    }
    _board[0][0] = '+';
    _board[0][BOARD_WIDTH - 1] = '+';
    _board[BOARD_HEIGHT - 1][BOARD_WIDTH - 1] = '+';
    _board[BOARD_HEIGHT - 1][0] = '+';
}

void Board::initializeBoard(Player player1)
{
    for(unsigned int i=0; i< BOARD_HEIGHT ; i++)
        for(unsigned int j=0; j< BOARD_WIDTH; j++)
        {
            {
                _board[i][j] = '.';
            }
        }
    makeFrame();
}

void Board::generateFood(Player player1)
{
    bool isInPlayer = false;
    do
    {
        isInPlayer = false;
        this->_foodXcord = ( std::rand() % 17 ) + 1;
        this->_foodYcord = ( std::rand() % 7 ) + 1;
        for(int q = 0; q < player1.getSnakeSize(); q++)
        {
            if(this->_foodXcord == player1.getSnakesPartCordX(q) && this->_foodYcord == player1.getSnakesPartCordY(q))
            {
                isInPlayer = true;
            }
        }
    }
    while(isInPlayer);

}

void Board::checkIfPlayerAteFood(Player &player1)
{
    if(_foodXcord == player1.getSnakesPartCordX(0) && _foodYcord == player1.getSnakesPartCordY(0))
    {
        player1.addNewSnakePart();
        player1.addPoints(1);
        this->generateFood(player1);
    }
}

void Board::gameEnd(Player player1)
{
    system("cls");
    if(player1.getPoints() == 1)
    {
        std::cout<< "Gratulacje, uzyskales "<<player1.getPoints()<<" punkt.";
    }
    else if(player1.getPoints() >= 2 && player1.getPoints() <= 4)
    {
        std::cout<< "Gratulacje, uzyskales "<<player1.getPoints()<<" punkty.";
    }
    else
    {
        std::cout<< "Gratulacje, uzyskales "<<player1.getPoints()<<" punktow.";
    }
    Sleep(5000);
}

void Board::checkIfPlayerHitHimself(Player &player1)
{
    for(unsigned int h = 1; h < player1.getSnakeSize(); h++)
    {
        if(player1.getSnakesPartCordX(0) == player1.getSnakesPartCordX(h) && player1.getSnakesPartCordY(0) == player1.getSnakesPartCordY(h))
        {
            this->gameEnded = true;
            gameEnd(player1);
        }
    }
    std::cout<<"Sprawdzono, nie dosz³o do kolizji";
}

void Board::printStartMenu()
{
    std::cout<<std::endl;
    std::cout<<"Welcome in crazy game called Snake."<<std::endl;
    std::cout<<std::endl;
    std::cout<<"If you want to play, just click 'p' button"<<std::endl;
    std::cout<<"You can play my game using WASD or if you want keyboard arrows"<<std::endl;
    std::cout<<"Collect food to grow your Snake"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"If u want to exit just press ESC button"<<std::endl;
    std::cout<<"Have fun!"<<std::endl;
}
