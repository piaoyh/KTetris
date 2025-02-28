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
	curBlock = rand() % NUM_SHAPE;
	curRot = rand() % 4;
	curPos.set_xy(WIDTH / 2, 3);
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
		char place = get_board(x, y);
		if (EMPTY != place)
		{
			curRot = rot;
			return false;
		}
	}
	curRot = rot;
	return true;
}

void Tetris::rotate()
{
	if (can_rotate())
	{
		++curRot;
		curRot &= 0b11;
	}

}

bool Tetris::can_move_left()
{
	curPos.dec_x();
	Point* brick = get_brick();
	for (int i = 0; i < NUM_BRICK; i++)
	{
		short x = curPos.get_x() + brick[i].get_x();
		short y = curPos.get_y() + brick[i].get_y();
		char place = get_board(x, y);
		if (EMPTY != place)
		{
			curPos.inc_x();
			return false;
		}
	}
	curPos.inc_x();
	return true;
}

void Tetris::move_left()
{
	if (can_move_left())
		curPos.dec_x();
}

bool Tetris::can_move_right()
{
	curPos.inc_x();
	Point* brick = get_brick();
	for (int i = 0; i < NUM_BRICK; i++)
	{
		short x = curPos.get_x() + brick[i].get_x();
		short y = curPos.get_y() + brick[i].get_y();
		char place = get_board(x, y);
		if (EMPTY != place)
		{
			curPos.dec_x();
			return false;
		}
	}
	curPos.dec_x();
	return true;
}

void Tetris::move_right()
{
	if (can_move_right())
		curPos.inc_x();
}

bool Tetris::can_move_down()
{
	curPos.inc_y();
	Point* brick = get_brick();
	for (int i = 0; i < NUM_BRICK; i++)
	{
		short x = curPos.get_x() + brick[i].get_x();
		short y = curPos.get_y() + brick[i].get_y();
		char place = get_board(x, y);
		if (EMPTY != place)
		{
			curPos.dec_y();
			return false;
		}
	}
	curPos.dec_y();
	return true;
}

void Tetris::move_down()
{
	if (can_move_down())
		curPos.inc_y();
}