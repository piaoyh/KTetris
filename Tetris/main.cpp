#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>

#include "ScanCode.h"
#include "screen.h"
#include "Tetris.h"
#include "Game.h"
using namespace std;

int main()
{
    Game    game;
    game.display_board();

    _getch();
    return 0;
}





/*
bool    bCon = true;
int     ch;
short   x = get_window_width() / 2;
short   y = get_window_height() / 2;

move_cursor(x, y);
hide_cursor();
_putch('@');
while (bCon)
{
    ch = _kbhit();
    if (!ch)
        continue;
    ch = _getch();
    if (KEY_SPEC == ch || KEY_FUNC == ch)
    {
        ch = _getch();
        switch(ch)
        {
        case KEY_RIGHT:
            if (get_window_width() - 1 == x)
                break;
            mvprint(x, y, ' ');
            x += 1;
            mvprint(x, y, '@');
            break;
        case KEY_LEFT:
            if (0 == x)
                break;
            mvprint(x, y, ' ');
            x -= 1;
            mvprint(x, y, '@');
            break;
        case KEY_UP:
            if (0 == y)
                break;
            mvprint(x, y, ' ');
            y -= 1;
            mvprint(x, y, '@');
            break;
        case KEY_DOWN:
            if (get_window_height() - 1 == y)
                break;
            mvprint(x, y, ' ');
            y += 1;
            mvprint(x, y, '@');
            break;
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
*/