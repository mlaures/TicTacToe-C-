#pragma once

 /*
 * @file board.hpp
 * @author Mei-Ling Laures
 * @set 1
 *
 * @brief Tic-Tac-Toe board
 */

class Board
{
	// board data includes the grid of arrays that the pieces will be placed
	// into
    private:
        int squares[3][3];

    // board functions include initializing the board, finding the contents of
    // a square in the grid, placing a piece in the grid, checking if a player
    // has won and if the game is a draw
    public:
    	Board();
    	~Board();
    	int query(int x, int y);
    	void place(int x, int y, int p);
    	bool check_win(int x, int y, int p);
    	bool check_draw();
};