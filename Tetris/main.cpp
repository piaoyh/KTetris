#include <conio.h>

#include "Game.h"
#include "screen.h"

using namespace std;

int main()
{
    Game    game;
    game.display_board();
    _getch();
    return 0;
}
