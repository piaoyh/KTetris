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

void Tetris::rotate()
{
	char rot = curRot;
	++curRot;
	curRot &= 0b11;
	Point* brick = get_brick();
	for (int i = 0; i < NUM_BRICK; i++)
	{
		short x = curPos.get_x() + brick[i].get_x();
		if (x < 1)
		{
			curRot = rot;
			return;
		}
			return;
	}
}

void Tetris::move_left()
{
	Point* brick = get_brick();
	for (int i = 0; i < NUM_BRICK; i++)
	{
		short x = curPos.get_x() + brick[i].get_x();
		if (x < 2)
			return;
	}
	curPos.set_x(curPos.get_x() - 1);
}

void Tetris::move_right()
{
	Point* brick = get_brick();
	for (int i = 0; i < NUM_BRICK; i++)
	{
		short x = curPos.get_x() + brick[i].get_x();
		if (x > WIDTH - 3)
			return;
	}
	curPos.set_x(curPos.get_x() + 1);
}
