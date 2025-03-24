#pragma once

#include "Point.h"

#define WIDTH		(13)	// including walls
#define HEIGHT		(22)	// including walls
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
	void init();
	bool generate();
	inline char get_board(short x, short y)	{ return board[x][y]; }
	inline void set_board(short x, short y, char brick = BRICK) { board[x][y] = brick; }
	inline char get_cur_block()		{ return curBlock; }
	inline Point get_cur_pos()		{ return curPos; }
	inline short get_cur_pos_x()	{ return curPos.get_x(); }
	inline short get_cur_pos_y()	{ return curPos.get_y(); }
	Point* get_brick()				{ return block[curBlock][curRot]; }

	bool can_rotate();
	bool can_move_left();
	bool can_move_right();
	bool can_move_down();
	bool rotate();	
	bool move_left();
	bool move_right();
	bool move_down();
	bool is_filled(short line);
	bool is_empty(short line);
	bool clear(short line);
	short push_lines_down(short line);
	void push_lines_down();
	void drop();
	void stack();
};

