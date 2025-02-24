#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Game.h"
using namespace std;

int main()
{
    srand(time(NULL));
    Game    game;
    game.display_board();
    game.display_block();
    _getch();
    return 0;
}