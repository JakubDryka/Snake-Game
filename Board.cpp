#include "Board.h"
#include <iostream>

Board::Board()
{
    GameBoardArray _board;
}

void printBoard()
    {
        for(int i=0; i< BOARD_HEIGHT ; i++)
        {
            for(int j=0; j< BOARD_WIDTH; j++)
            {
                std::cout << _board[i][j];
            }
            std::cout << std::endl;
        }
    }

void makeFrame()
    {
        for(int i=0; i< BOARD_HEIGHT ; i++)
        {
            _board[i][0] = '#';
            _board[i][BOARD_WIDTH-1] = '#';
        }

        for(int j=0; j< BOARD_WIDTH ; j++)
        {
            _board[0][j] = '#';
            _board[BOARD_HEIGHT-1][j] = '#';
        }
    }

void initializeBoard()
    {
        for(int i=0; i< BOARD_HEIGHT ; i++)
            for(int j=0; j< BOARD_WIDTH; j++)
            {
                _board[i][j] = ' ';
            }
        makeFrame();
    }
