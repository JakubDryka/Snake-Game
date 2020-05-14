#include <iostream>
#include <array>

const unsigned BOARD_HEIGHT = 10;
const unsigned BOARD_WIDTH = 20;
typedef std::array<std::array<char, BOARD_WIDTH>, BOARD_HEIGHT> GameBoardArray;

class Board
{
public:
    void printBoard()
    {
        for(int i=0; i< BOARD_HEIGHT ; i++)
        {
            for(int j=0; j< BOARD_WIDTH; j++)
            {
                std::cout << board[i][j];
            }
            std::cout << std::endl;
        }
    }


    void makeFrame()
    {
        for(int i=0; i< BOARD_HEIGHT ; i++)
        {
            board[i][0] = '#';
            board[i][BOARD_WIDTH-1] = '#';
        }

        for(int j=0; j< BOARD_WIDTH ; j++)
        {
            board[0][j] = '#';
            board[BOARD_HEIGHT-1][j] = '#';
        }
    }


    void initializeBoard()
    {
        for(int i=0; i< BOARD_HEIGHT ; i++)
            for(int j=0; j< BOARD_WIDTH; j++)
            {
                board[i][j] = ' ';
            }
        makeFrame();
    }

GameBoardArray board;
};


int main()
{
    Board board;
    board.initializeBoard();
    board.printBoard();
}
