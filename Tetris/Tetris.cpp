#include "Tetris.h"

Tetris::Tetris()
{
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			board[x][y] = EMPTY;
		}
	}

	for (int x = 0; x < WIDTH; x++)
	{
		board[x][0] = WALL;
		board[x][HEIGHT - 1] = WALL;
	}
	for (int y = 0; y < HEIGHT; y++)
	{
		board[0][y] = WALL;
		board[WIDTH-1][y] = WALL;
	}
}