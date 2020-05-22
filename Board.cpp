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
            for(unsigned int z=0; z< player1._snakeBody.size(); z++)
            {
                if(j == player1._snakeBody.at(z).first && i == player1._snakeBody.at(z).second)
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
        this->_foodXcord = ( std::rand() % 17 ) + 1;
        this->_foodYcord = ( std::rand() % 7 ) + 1;
        for(int q = 0; q < player1._snakeBody.size(); q++)
        {
            if(this->_foodXcord == player1._snakeBody.at(q).first && this->_foodYcord == player1._snakeBody.at(q).second)
            {
                isInPlayer = true;
            }
        }
    }
    while(isInPlayer);

}

void Board::checkIfPlayerAteFood(Player &player1)
{
    if(_foodXcord == player1._snakeBody.front().first && _foodYcord == player1._snakeBody.front().second)
    {
        player1.addNewSnakePart();
        player1._points += 1;
        this->generateFood(player1);
    }
}

void Board::gameEnd(Player player1)
{
    system("cls");
    std::cout<< "Gratulacje, uzyskales "<<player1._points<<" punktow.";
    Sleep(5000);
}

void Board::checkIfPlayerHitHimself(Player &player1)
{
    for(unsigned int o = 1; o < player1._snakeBody.size(); o++)
    {
        if(player1._snakeBody.front().first == player1._snakeBody.at(o).first && player1._snakeBody.front().second == player1._snakeBody.at(o).second)
        {
            this->gameEnded = true;
            gameEnd(player1);
        }
    }
    std::cout<<"Sprawdzono, nie dosz³o do kolizji";
}

void Board::printData(Board board, Player player1)
{
    std::cout<<"Aktualny kierunek playera to "<<player1._playerDirection<<std::endl;
    std::cout<<"koordynaty food to "<<board._foodXcord<<" i "<<board._foodYcord<<std::endl;
    std::cout<<"Glowa weza znajduje sie na "<<player1._snakeBody.front().first<<", "<<player1._snakeBody.front().second<<std::endl;
    std::cout<<"Rozmiar weza to "<<player1._snakeBody.size()<<std::endl;
    std::cout<<"Wcisnij ESC aby zamknac"<<std::endl;
    std::cout<<"Liczba zdobytych punktow: "<<player1._points<<std::endl;
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
