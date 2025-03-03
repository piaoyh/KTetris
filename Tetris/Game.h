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

	bool play();
	bool generate();
	void display_board();
	void display_block();
	void delete_block();
	const char* get_board(short x, short y);
	bool rotate();
	bool move_left();
	bool move_right();
	bool move_down();
	void drop();
};

