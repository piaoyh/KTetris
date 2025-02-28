#include <stdlib.h>
#include <time.h>

#include "Game.h"
using namespace std;

int main()
{
    srand(time(NULL));
    Game    game;
    game.play();
    return 0;
}