#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <iostream>

int main(int, char**)
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cerr << "SDL could not initialize: "
                  << SDL_GetError() << '\n';

        return 1;
    }

    std::cout << "SDL initialized successfully.\n";

    SDL_Quit();
    return 0;
}