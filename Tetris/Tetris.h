#pragma once

#include "Point.h"

#define WIDTH		(13)
#define HEIGHT		(22)
#define NUM_BRICK	(4)
#define NUM_SHAPE	(7)
#define WALL		(-1)
#define EMPTY		(0)
#define BRICK		(1)

class Tetris
{
	static Point	block[NUM_SHAPE][4][NUM_BRICK];

	char	board[WIDTH][HEIGHT];
	char	curBlock;
	char	curRot;
	Point	curPos;

public:
	Tetris();

	inline char get_board(short x, short y)	{ return board[x][y]; }
	inline char get_cur_block()		{ return curBlock; }
	inline Point get_cur_pos()		{ return curPos; }
	inline short get_cur_pos_x()	{ return curPos.get_x(); }
	inline short get_cur_pos_y()	{ return curPos.get_y(); }
	Point* get_brick()				{ return block[curBlock][curRot]; }

	void rotate();	
	void move_left();
	void move_right();
};

