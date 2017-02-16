/*
 * @file tictactoe.cpp
 * @author Mei-Ling Laures
 * @set 1
 *
 * @brief Initialize and run Tic-Tac-Toe
 */

#include <iostream>
#include "board.hpp"
#include "game.hpp"

using namespace std;

int main()
{
	Board b;
	Game g(b);
	return g.run(1);
}
