/*
 * @file board.cpp
 * @author Mei-Ling Laures
 * @set 1
 *
 * @brief Board class functions
 */

#include "board.hpp"
#include <iostream>

using namespace std;

/*
 * @brief Constructs a new blank board
 */
Board::Board()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			squares[i][j] = 0;
		}
	}
}

Board::~Board()
{

}

/*
 * @brief Gets the value at the given coordinates
 *
 * @param int x is the row number
 * @param int y is the column number
 *
 * @return N/A
 */
int Board::query(int x, int y)
{
	return squares[x][y];
}

/*
 * @brief Makes a move at the given coordinates
 *
 * @param int x is the row number
 * @param int y is the column number
 * @param int p is the player
 *
 * @return N/A
 */
void Board::place(int x, int y, int p)
{
	squares[x][y] = p;
}

/*
 * @brief Checks if the winning conditions have been met
 *
 * @param int x is the row number
 * @param int y is the column number
 * @param int p is the player
 *
 * @return true if the player has won
 */
bool Board::check_win(int x, int y, int p)
{
	int count = 0;
	//horizontal
	// for a specific player, check if the 3 y in row x are the same
	for (int i = 0; i < 3; i++)
	{
		if (squares[x][i] != p)
		{
			break;
		}
		count++;
	}
	if (count == 3)
	{
		return true;
	}
	count = 0;

	//vertical
	// for a specific player, check if the 3 x in column y are the same
	for (int j = 0; j < 3; j++)
	{
		if (squares[j][y] != p)
		{
			break;
		}
		count++;
	}
	if (count == 3)
	{
		return true;
	}
	count = 0;

	//diagonal
	// for a specific player, check if the (-)3 x, y are the same
	for (int k = 0; k < 3; k++)
	{
		if (squares[k][k] != p)
		{
			break;
		}
		count++;
	}
	if (count == 3)
	{
		return true;
	}
	count = 0;

	for (int l = 0; l < 3; l++)
	{
		if (squares[(2-l)][l] != p)
		{
			break;
		}
		count++;
	}
	if (count == 3)
	{
		return true;
	}
	count = 0;

	return false;
}

/*
 * @brief Checks if there are any more moves on the game board
 *
 * @return true if the players draw
 */
bool Board::check_draw()
{
	// assume that the board is a draw to check if there are more moves
	// loop through all of the squares of the board
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// if a square is not filled with a piece
			// return that the game is not a draw
			if (squares[i][j] == 0)
			{
				return false;
			}
		}
	}

	// if the for loops complete, return that the game is a draw
	return true;
}
