/*
 * @file game.cpp
 * @author Mei-Ling Laures
 * @set 1
 *
 * @brief Game class functions
 */

#include "game.hpp"
#include "board.hpp"
#include <iostream>
#include <string>

using namespace std;

/*
 * @brief Makes the game
 */
Game::Game()
{
	Board b;
	board = b;
}

/*
 * @brief Makes the game
 */
Game::Game(Board b)
{
	board = b;
}

/*
 * @brief Deletes the game
 */
Game::~Game()
{
}


/*
 * @brief Runs the game
 *
 * Make the turn for the player and check if there is a draw
 * Continue the game if not done
 *
 * @param int player is the player
 *
 * @return 0 if the game finishes
 */
int Game::run(int player)
{
	int end = 1;

	// let the player make a move and check to see if the game has ended
	// with a win. else check if there is a draw
	end = player_turn(player);
	if (end == 0)
	{
		return 0;
	}
	else if (board.check_draw())
	{
		// if there is a draw, print the final board state and end the game
		print_board();
		cout << "This game was a draw!" << endl;
		return 0;
	}
	else
	{
		//change the player
		if (player == 1)
		{
			player = 2;
		}
		else if (player == 2)
		{
			player = 1;
		}

		// id the game hasn't ended then continue the game
		return run(player);
	}
}


/*
 * @brief Makes the player's move
 *
 * Looks for input from the terminal for row and column
 * Makes a move in the correct place and then check if the player wins
 *
 * @param int p is the player
 *
 * @return 0 if the player wins
 */
int Game::player_turn (int p)
{
	// print the game state and initialize the needed variables
	print_board();
	char let;
	int x, y;

	//convert the player numbers to their sign
	if (p == 1)
	{
		let = 'X';
	}
	else if (p == 2)
	{
		let = 'O';
	}

	// look for input from the player to know where to place the piece
	cout << "Player " << let << " turn" << endl;
	cout << "Enter row" << endl;
	cin >> y;
	cout << "Enter column" << endl;
	cin >> x;
	
	//place the piece
	board.place(x, y, p);

	// check if the placed piece won the game
	if (board.check_win(x, y, p))
	{
		// if the game is won, print the last board state and end the game
		print_board();
		cout << "Player " << let << " won" << endl;
		return 0;
	}
	return 1;
}

/*
 * @brief Prints the game board in the terminal
 *
 * @return N/A
 */
void Game::print_board()
{
    //strings being used to print
    string l_top = "  0   1   2 ";
	string l_mid = "    |   |   ";
	string l_bot = " ___|___|___";
	string l1 = "0   |   |   ";
	string l2 = "1   |   |   ";
	string l3 = "2   |   |   ";

	// inserting the pieces into the print line, row 0
	// if there is a player piece in a spot, change that spot on the board to
	// the player piece
	for (int i = 0; i < 3; i++)
	{
		if (board.query(i, 0) == 0)
		{
			l1[(2 + (i * 4))] = ' ';
		}
		else if (board.query(i, 0) == 1)
		{
			l1[(2 + (i * 4))] = 'X';
		}
		else if (board.query(i, 0) == 2)
		{
			l1[(2 + (i * 4))] = 'O';
		}
	}

	// inserting the pieces into the print line, row 1
	// if there is a player piece in a spot, change that spot on the board to
	// the player piece
	for (int  j = 0; j < 3; j++)
	{
		if (board.query(j, 1) == 0)
		{
			l2[(2 + (j * 4))] = ' ';
		}
		else if (board.query(j, 1) == 1)
		{
			l2[(2 + (j * 4))] = 'X';
		}
		else if (board.query(j, 1) == 2)
		{
			l2[(2 + (j * 4))] = 'O';
		}
	}

	// inserting the pieces into the print line, row 2
	// if there is a player piece in a spot, change that spot on the board to
	// the player piece
	for (int k = 0; k < 3; k++)
	{
		if (board.query(k, 2) == 0)
		{
			l3[(2 + (k * 4))] = ' ';
		}
		else if (board.query(k, 2) == 1)
		{
			l3[(2 + (k * 4))] = 'X';
		}
		else if (board.query(k, 2) == 2)
		{
			l3[(2 + (k * 4))] = 'O';
		}
	}

	// print the board into the terminal
	cout << l_top << endl;
	cout << l_mid << endl;
	cout << l1 << endl;
	cout << l_bot << endl;
	cout << l_mid << endl;
	cout << l2 << endl;
	cout << l_bot << endl;
	cout << l_mid << endl;
	cout << l3 << endl;
	cout << l_mid << endl;

}


