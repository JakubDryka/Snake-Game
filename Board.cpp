#include "Board.h"
#include <iostream>

Board::Board()
{
    GameBoardArray _board;
}

void Board::printBoard()
    {
        for(int i=0; i< BOARD_HEIGHT ; i++)
        {
            for(int j=0; j< BOARD_WIDTH; j++)
            {
                std::cout << this->_board[i][j];
            }
            std::cout << std::endl;
        }
    }

void Board::makeFrame()
    {
        for(int i=0; i< BOARD_HEIGHT ; i++)
        {
            _board[i][0] = '|';
            _board[i][BOARD_WIDTH-1] = '|';
        }

        for(int j=0; j< BOARD_WIDTH ; j++)
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
        for(int i=0; i< BOARD_HEIGHT ; i++)
            for(int j=0; j< BOARD_WIDTH; j++)
            {
                if(j == player1._playerXcord && i == player1._playerYcord)
                {
                    _board[i][j] = 'S';
                }
                else
                {
                    _board[i][j] = '.';
                }
            }
        makeFrame();
    }
