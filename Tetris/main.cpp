#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ScanCode.h"
#include "screen.h"
#include "Game.h"
using namespace std;

int main()
{
    srand(time(NULL));
    Game    game;
    game.display_board();
    game.display_block();
    bool    bCon = true;
    while (bCon)
    {
        int ch = _kbhit();
        if (!ch)
            continue;
        ch = _getch();
        if (KEY_SPEC == ch || KEY_FUNC == ch)
        {
            ch = _getch();
            switch (ch)
            {
            case KEY_RIGHT: game.move_right();  break;
            case KEY_LEFT:  game.move_left();   break;
            case KEY_UP:    game.rotate();      break;
            case KEY_DOWN:  game.move_down();   break;
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
    return 0;
}