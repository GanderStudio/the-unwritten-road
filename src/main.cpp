#include "Game.hpp"

#include <SDL3/SDL_main.h>

int main(int, char**)
{
    Game game;

    if (!game.initialize())
    {
        return 1;
    }

    game.run();

    return 0;
}