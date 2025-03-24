#include <stdlib.h>
#include <time.h>

#include "Game.h"

using namespace std;

int main()
{
    srand(time(NULL));
    Game().play();
    return 0;
}