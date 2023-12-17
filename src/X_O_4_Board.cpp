#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
using namespace std;
#include "BoardGame_Classes.hpp"

// Initiolize the bord to empty spaces
X_O_4_Board::X_O_4_Board()
{
    n_rows = 6;
    n_cols = 7;
    board = new char *[n_rows];

    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
        {
            board[i][j] = ' ';
        }
    }
};

bool X_O_4_Board ::update_board(int x, int y, char mark)
{

    if (board[x][y] == ' ' && (y >= 0 && y < 7) && ((n_moves > 0 && (x >= 0 && x < 6) || (n_moves == 0 && x == 5))) // first move must be placed in the last row only
        && (update_rule(x, y))                                                                                      // Making suer a rule is applied
    )
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
    {
        return false;
    }
}

// function to check if the next placement in the game is in the lowest square of the chosen column
bool X_O_4_Board::update_rule(int x, int y)
{
    bool ans;
    // if it is already at the bottom of the column
    if (x == 5)
    {
        return true;
    }
    // For any other row either than the last one then we need to make sure that at that column this is the last square
    else
    {
        for (int i = 5; i > x; i--)
        { // start looping from the bottom of the column ( i = 5 )
            // decrementing by one till we reach the square before the wanted one
            // checking if it is full or not if so then we check the one before it, if not return false
            if (board[i][y] != ' ')
            {
                ans = true;
            }
            else
            {
                return false;
            }
        }
        return ans;
    }
}

void X_O_4_Board::display_board()
{
    for (int i = 0; i < 6; i++)
    {
        cout << "\n| ";
        for (int j = 0; j < 7; j++)
        {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n------------------------------------------------------------------";
    }
    cout << endl;
}

bool X_O_4_Board ::is_winner()
{
    for (int i = 0; i + 3 < 6; i++)
    {
        for (int j = 0; j + 3 < 7; j++)
        {
            // making suer fisrt that its not an empty square
            if ((board[i][j] != ' ') &&

                // Four in a rwo (horizontally)
                (
                    ((j < 4) && (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3])) ||

                    // Four in a row (vertically)
                    ((i < 3) && (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j])) ||

                    // Four in a row (diagonally)
                    ((board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3]))))
            {

                return true;
            }
        }
    }

    return false;
};

bool X_O_4_Board ::is_draw()
{
    if (n_moves == 42 && !is_winner())
        return true;
    else
        return false;
};

bool X_O_4_Board ::game_is_over()
{
    return n_moves >= 42;
};

int X_O_4_Board::winnerPlayer()
{
    return 0;
}
