#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Game.h"
#include "Screen.h"
#include "ScanCode.h"

using namespace std;

Game::Game()
{
	short x = (get_window_width() - BOARD_WIDTH) >> 1;
	short y = (get_window_height() - BOARD_HEIGHT) >> 1;
	origin = Point(x, y);
	clear();
	hide_cursor();
}

bool Game::play()
{
	unsigned int    period = 100;
	unsigned int    tick = 0;

	display_board();
	display_block();
	bool    bCon = true;
	while (bCon)
	{
		int ch = _kbhit();
		if (ch)
		{
			ch = _getch();
			if (KEY_SPEC == ch || KEY_FUNC == ch)
			{
				ch = _getch();
				switch (ch)
				{
				case KEY_RIGHT: move_right();  break;
				case KEY_LEFT:  move_left();   break;
				case KEY_UP:    rotate();      break;
				case KEY_DOWN:  move_down();   break;
				}
			}
			else
			{
				switch (ch)
				{
				case ' ':	drop();			break;
				case 'q':
				case 27:	bCon = false;	break;
				}
			}
		}
		if (tick > period)
		{
			tick = 0;
			if (!move_down())
			{
				tetris.stack();
				if (!generate())
				{
					mvprint(0, 0, "Game Over");
					mvprint(0, 1, "Play again?");
					char answer = 0;
					cin >> answer;
					if (('y' == answer) || ('Y' == answer))
					{
						mvprint(0, 0, "         ");
						mvprint(0, 1, "           ");
						mvprint(0, 2, ' ');

						tetris.init();
						display_board();
						generate();
						display_block();
					}
					else
					{
						bCon = false;
					}
				}
				continue;
			}
		}
		tick++;
		Sleep(10);
	}
	return true;
}

bool Game::generate()
{
	bool generated = tetris.generate();
	if (generated)
		display_board();
	return generated;
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
	delete_block();
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

void Game::delete_block()
{
	short x = tetris.get_cur_pos_x();
	short y = tetris.get_cur_pos_y();
	Point* brick = tetris.get_brick();
	for (int i = 0; i < 4; i++)
	{
		short xx = (x + brick[i].get_x()) * 2 + origin.get_x();
		short yy = (y + brick[i].get_y()) + origin.get_y();
		mvprint(xx, yy, BOARD_EMPTY);
	}
}

bool Game::rotate()
{
	delete_block();
	bool rotated = tetris.rotate();
	display_block();
	return rotated;
}

bool Game::move_left()
{
	delete_block();
	bool moved = tetris.move_left();
	display_block();
	return moved;
}

bool Game::move_right()
{
	delete_block();
	bool moved = tetris.move_right();
	display_block();
	return moved;
}

bool Game::move_down()
{
	delete_block();
	bool moved = tetris.move_down();
	display_block();
	return moved;
}

void Game::drop()
{
	while (move_down());
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