#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>

#include "ScanCode.h"
#include "screen.h"
#include "Game.h"

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
	char tt[10];
	display_board();
	display_block();
	bool bCon	= true;
	long t		= 0L;
	long limit	= 150L;
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
				case 'q':
				case 27:
					bCon = false;
					break;
				}
			}
		}
		if (t > limit)
		{
			if (!tetris.can_move_down())
			{
				tetris.put_block(BRICK);
				tetris.generate_block();
			}	
			else
			{
				tetris.move_down();
			}	
			display_board();
			display_block();
			t = 0;
		}
		t++;
		Sleep(10);
		mvprint(0, 0, _itoa(t, tt, 10));
	}
	return false;
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

void Game::rotate()
{
	if (tetris.can_rotate())
	{
		delete_block();
		tetris.rotate();
		display_block();
	}
}

void Game::move_left()
{
	if (tetris.can_move_left())
	{
		delete_block();
		tetris.move_left();
		display_block();
	}
}

void Game::move_right()
{
	if (tetris.can_move_right())
	{
		delete_block();
		tetris.move_right();
		display_block();
	}
}

void Game::move_down()
{
	if (tetris.can_move_down())
	{
		delete_block();
		tetris.move_down();
		display_block();
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