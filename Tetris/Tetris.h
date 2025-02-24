#pragma once

#include "Point.h"

#define WIDTH	(12)
#define HEIGHT	(22)
#define WALL	(-1)
#define EMPTY	(0)
#define BRICK	(1)

class Tetris
{
	static Point	block[7][4][4];

	char	board[WIDTH][HEIGHT];

public:
	Tetris();
};

