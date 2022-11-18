#include <stdio.h>
#include "Game.h"

int main( int argc, char** argv) {
    Game::GetInstance().run();

    return 0;
}