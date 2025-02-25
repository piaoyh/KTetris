#pragma once

#include "Point.h"
#include "Tetris.h"

#define BOARD_WIDTH		(WIDTH * 2)
#define BOARD_HEIGHT	(HEIGHT)
#define BOARD_WALL		"##"
#define BOARD_EMPTY		"  "
#define BOARD_BRICK		"@@"

class Game
{
	Tetris	tetris;
	Point	origin;

public:
	Game();

	void display_board();
	void display_block();
	void delete_block();
	const char* get_board(short x, short y);
	void rotate();
	void move_left();
	void move_right();
};

