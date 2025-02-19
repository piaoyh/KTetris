#pragma once

#include "Point.h"

#define WIDTH	(12)
#define HEIGHT	(22)
#define WALL	(-1)
#define EMPTY	(0)
#define BRICK	(1)

enum Block { I, J, L, Z, S, T, O };
class Tetris
{
	static Point	block[7][4][4];

	char	board[WIDTH][HEIGHT];
	Point	curLoc;
	Block	curBlock;
	short	curTurn;

public:
	Tetris();
	inline Point get_cur_loc()		{ return curLoc; }
	inline Block get_cur_block()	{ return curBlock; }
	inline short get_cur_turn()		{ return turn; }
	inline char get_board(short x, short y)	{ return board[x][y]; }
};

