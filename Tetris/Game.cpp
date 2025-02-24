#include <stdlib.h>
#include <time.h>

#include "Game.h"
#include "Screen.h"

Game::Game()
{
	short x = (get_window_width() - BOARD_WIDTH) >> 1;
	short y = (get_window_height() - BOARD_HEIGHT) >> 1;
	origin = Point(x, y);
	clear();
	hide_cursor();
}

void Game::display_board()
{
	for (short y = 0; y < HEIGHT; y++)
	{
		for (short x = 0; x < WIDTH; x++)
		{
			short xx = (x << 1) + origin.get_x();
			short yy = y + origin.get_y();
			const char* brick = get_board(x, y);
			mvprint(xx, yy, brick);
		}
	}
}

void Game::display_block()
{
	short x = tetris.get_cur_pos_x();
	short y = tetris.get_cur_pos_y();
	Point* brick = tetris.get_brick();
	for (int i = 0; i < 4; i++)
	{
		short xx = (x + brick[i].get_x()) * 2 + origin.get_x();
		short yy = (y + brick[i].get_y()) + origin.get_y();
		mvprint(xx, yy, BOARD_BRICK);
	}
}

const char* Game::get_board(short x, short y)
{
	const char* brick;
	switch (tetris.get_board(x, y))
	{
	case WALL:	brick = BOARD_WALL;		break;
	case BRICK:	brick = BOARD_BRICK;	break;
	default:	brick = BOARD_EMPTY;	break;
	}
	return brick;
}