#include <stdlib.h>
#include <time.h>

#include "Tetris.h"

Point	Tetris::block[NUM_SHAPE][4][NUM_BRICK] = {
	// I-shape
	{
		{ {0, 0}, {-1, 0}, {1, 0}, {2, 0} },
		{ {0, 0}, {0, -1}, {0, 1}, {0, 2} },
		{ {0, 0}, {-1, 0}, {1, 0}, {-2, 0} },
		{ {0, 0}, {0, -1}, {0, 1}, {0, -2} }
	},

	// J-shape
	{
		{ {0, 0}, {-1, 0}, {1, 0}, {-1, -1} },
		{ {0, 0}, {0, -1}, {0, 1}, {1, -1} },
		{ {0, 0}, {-1, 0}, {1, 0}, {1, 1} },
		{ {0, 0}, {0, -1}, {0, 1}, {-1, 1} },
	},

	// L-shape
	{
		{ {0, 0}, {-1, 0}, {1, 0}, {1, -1} },
		{ {0, 0}, {0, -1}, {0, 1}, {1, 1} },
		{ {0, 0}, {-1, 0}, {1, 0}, {-1, 1} },
		{ {0, 0}, {0, -1}, {0, 1}, {-1, -1} }
	},

	// Z-shape
	{
		{ {0, 0}, {-1, 0}, {0, 1}, {1, 1} },
		{ {0, 0}, {0, -1}, {-1, 0}, {-1, 1} },
		{ {0, 0}, {0, -1}, {-1, -1}, {1, 0} },
		{ {0, 0}, {1, 0}, {1, -1}, {0, 1} },
	},

	// S-shape
	{
		{ {0, 0}, {1, 0}, {0, 1}, {-1, 1} },
		{ {0, 0}, {-1, 0}, {-1, -1}, {0, 1} },
		{ {0, 0}, {-1, 0}, {0, -1}, {1, -1} },
		{ {0, 0}, {0, -1}, {1, 0}, {1, 1} }
	},

	// T-shape
	{
		{ {0, 0}, {-1, 0}, {1, 0}, {0, 1} },
		{ {0, 0}, {0, -1}, {0, 1}, {-1, 0} },
		{ {0, 0}, {-1, 0}, {1, 0}, {0, -1} },
		{ {0, 0}, {0, -1}, {0, 1}, {1, 0} }
	},

	// O-shape
	{
		{ {0, 0}, {1, 0}, {0, 1}, {1, 1} },
		{ {0, 0}, {1, 0}, {0, 1}, {1, 1} },
		{ {0, 0}, {1, 0}, {0, 1}, {1, 1} },
		{ {0, 0}, {1, 0}, {0, 1}, {1, 1} }
	}
};



Tetris::Tetris()
{
	generate();
	init();
}

void Tetris::init()
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
		board[WIDTH - 1][y] = WALL;
	}
}

bool Tetris::generate()
{
	curBlock = rand() % NUM_SHAPE;
	curRot = rand() % 4;
	curPos.set_xy(WIDTH / 2, 3);
	Point* brick = get_brick();
	for (int i = 0; i < NUM_BRICK; i++)
	{
		short x = curPos.get_x() + brick[i].get_x();
		short y = curPos.get_y() + brick[i].get_y();
		if (get_board(x, y) != EMPTY)
			return false;
	}
	return true;
}

bool Tetris::can_rotate()
{
	char rot = curRot;
	++curRot;
	curRot &= 0b11;
	Point* brick = get_brick();
	for (int i = 0; i < NUM_BRICK; i++)
	{
		short x = curPos.get_x() + brick[i].get_x();
		short y = curPos.get_y() + brick[i].get_y();
		if (get_board(x, y) != EMPTY)
		{
			curRot = rot;
			return false;
		}
	}
	curRot = rot;
	return true;
}

bool Tetris::can_move_left()
{
	curPos.dec_x();
	Point* brick = get_brick();
	for (int i = 0; i < NUM_BRICK; i++)
	{
		short x = curPos.get_x() + brick[i].get_x();
		short y = curPos.get_y() + brick[i].get_y();
		if (get_board(x, y) != EMPTY)
		{
			curPos.inc_x();
			return false;
		}
	}
	curPos.set_x(curPos.get_x() + 1);
	return true;
}

bool Tetris::can_move_right()
{
	curPos.inc_x();
	Point* brick = get_brick();
	for (int i = 0; i < NUM_BRICK; i++)
	{
		short x = curPos.get_x() + brick[i].get_x();
		short y = curPos.get_y() + brick[i].get_y();
		if (get_board(x, y) != EMPTY)
		{
			curPos.dec_x();
			return false;
		}
	}
	curPos.set_x(curPos.get_x() - 1);
	return true;
}

bool Tetris::can_move_down()
{
	curPos.inc_y();
	Point* brick = get_brick();
	for (int i = 0; i < NUM_BRICK; i++)
	{
		short x = curPos.get_x() + brick[i].get_x();
		short y = curPos.get_y() + brick[i].get_y();
		if (get_board(x, y) != EMPTY)
		{
			curPos.dec_y();
			return false;
		}
	}
	curPos.set_y(curPos.get_y() - 1);
	return true;
}

bool Tetris::rotate()
{
	bool rotated = can_rotate();
	if (rotated)
	{
		++curRot;
		curRot &= 0b11;
	}
	return rotated;
}

bool Tetris::move_left()
{
	bool moved = can_move_left();
	if (moved)
		curPos.dec_x();
	return moved;
}

bool Tetris::move_right()
{
	bool moved = can_move_right();
	if (can_move_right())
		curPos.inc_x();
	return moved;
}

bool Tetris::move_down()
{
	bool moved = can_move_down();
	if (moved)
		curPos.inc_y();
	return moved;
}

void Tetris::drop()
{
	while (move_down());
}

void Tetris::stack()
{
	Point* brick = get_brick();
	for (int i = 0; i < NUM_BRICK; i++)
	{
		short x = curPos.get_x() + brick[i].get_x();
		short y = curPos.get_y() + brick[i].get_y();
		set_board(x, y);
	}
}