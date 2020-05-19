#include "Board.h"
#include <iostream>

Board::Board()
{

}

void Board::printBoard(Player player1)
    {
        for(unsigned int i=0; i< BOARD_HEIGHT ; i++)
        {
            for(unsigned int j=0; j< BOARD_WIDTH; j++)
            {
                if(j == player1._playerXcord && i == player1._playerYcord)
                {
                    std::cout<< "S";
                }
                else
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
