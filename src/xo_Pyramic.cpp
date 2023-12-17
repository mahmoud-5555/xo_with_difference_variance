#include "BoardGame_Classes.hpp"
#include <iostream>
// in making the baord could be diffrane boundaries in nay rows by making defrance arrays
//in the matrix but it will be easyly has accessing out the boundaries which is segmentaion fault ERROR
/**
 * xo_Pyramic : is a constuctor that make the bourd and mack the constrane
 * after make the bourd the conustructor start prepear the baord by in initialise
 * by diffrance value -1 for empty point and -2 for not valid point
 */
xo_Pyramic::xo_Pyramic()
{
	this->winner = -1;
	this->n_cols = 5;
	this->n_rows = 3;
	//making the board
	board = new char *[3];
	for (int i = 0; i < 3; i++)
	{
		board[i] = new char[5];
	}
	//prepearing the baord -1 for empty point and -2 for not valid point
	// the board have triangler shape so will have defrance range for any row <diagonals>
	//thats why we have valid point and not valid point
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == 2)
			{
				board[i][j] = -1;
			}
			else if (i == 1)
			{
				if (j == 1 || j == 2 || j == 3)
					board[i][j] = -1;
				else
					board[i][j] = -2;
			}
			else if (i == 0)
			{
				if (j == 2)
					board[i][j] = -1;
				else
					board[i][j] = -2;
			}
		}
	}
};

/**
 * update_board -  function that check if the input is valid after that put the value
 *@x: is row value
 *@y: is column value
 *@symbol: is <symbol value> (the input that will be assaind)
 */
bool xo_Pyramic::update_board(int x, int y, char symbol)
{
	//checking if the point in the bounday and checing if the point is valid 
	//and empty:<no one play in the point>

	if (x >= 0 && x < 3)
	{
		if (y >= 0 && y < 5)
		{
			if (board[x][y] == -1)
			{
				board[x][y] = symbol;
				n_moves++;
				return true;
			}
		}
	}
	return false;
}

/**
 * is_winner - function that determen if ther is winner or not and assine the winner
 *  in <winner varible>
 * Return: bool  true if there is winner
 */
bool xo_Pyramic::is_winner()
{
	// check the digonals
	// left digonal
	if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[0][2] != -1))
	{
		winner = board[0][2];
		return (1);
	}
	// right digonal
	if ((board[0][2] == board[1][3]) && (board[1][3] == board[2][4]) && (board[0][2] != -1))
	{
		winner = board[0][2];
		return (1);
	}
	// check the third col
	if ((board[0][2] == board[1][2]) && (board[1][2] == board[2][2]) && (board[0][2] != -1))
	{
		winner = board[0][2];
		return (1);
	}
	// check the secand row
	if ((board[1][1] == board[1][2]) && (board[1][2] == board[1][3]) && (board[1][1] != -1))
	{
		winner = board[0][2];
		return (1);
	}
	// check the last row
	for (int i = 0; i < 5; i++)
	{
		if ((i + 2) < 5)
		{
			if ((board[2][i] == board[2][i + 1]) && (board[2][i + 1] == board[2][i + 2]) && (board[2][i] != -1))
			{
				winner = board[0][2];
				return (1);
			}
		}
	}
	return (0);
}

/**
 * display_board - function that print the board
 * @Return: no return value
 *
 */
void xo_Pyramic::display_board()
{
	//looping on the board and print it  in way like traingle
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] == -2)
				cout << "______";
			else if (board[i][j] == -1)
				printf("| (%i,%i)", i, j);
			else
				printf("(%i,%i) %c", i, j, board[i][j]);

			if (j > 3)
				cout << "\n________________________________________________________\n";
			else
				cout << "   ";
		}
	}
}
/**
 * game_is_over - functon that check if the geam is end or not
 * Return: bool -> true if the game is over false if the game is not over
 * the logic is so easy to understand there are 9 point valid in the board if the players use it all 
 * thats mean the game is over
 */
bool xo_Pyramic::game_is_over()
{
	return n_moves >= 9;
}
/**
 * is_draw - function that check if the game is draw or not
 * Return: bool -> trur if the game is draw false if not
 * // the logic of the function is so semple if no turn and no winner is drow
*/
bool xo_Pyramic::is_draw()
{
	return (n_moves == 9 && !is_winner());
}
//free the heap <the baord was in the heap>
xo_Pyramic::~xo_Pyramic()
{
	for (int i = 0; i < 3; i++)
	{
		delete[] board[i];
	}
	delete[] board;
}
//};
//not used
int xo_Pyramic::winnerPlayer()
{
	return 0;
}
//not used
bool xo_Pyramic::update_rule(int x, int y)
{
	return false;
}
