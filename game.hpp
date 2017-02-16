/*
 * @file game.hpp
 * @author Mei-Ling Laures
 * @set 1
 *
 * @brief A new game of Tic-Tac-Toe
 */

#pragma once

#include "board.hpp"

class Game
{
	// game data includes whose turn it is and the board being played on
	private:
		Board board;
		int turn;

	// class functions includes initializing an instance of the class and
	// the function for running the game (other functions to run the game
	// have been made as well
	public:
		Game();
		Game(Board b);
		~Game();
		int run(int p);
		int player_turn(int p);
                void print_board();
};