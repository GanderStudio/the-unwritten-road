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

    constexpr int windowWidth = 1280;
    constexpr int windowHeight = 720;

    SDL_Window* window = SDL_CreateWindow(
    "The Unwritten Road",
    windowWidth,
    windowHeight,
    0
    );

    if (window == nullptr)
    {
    std::cerr << "Window could not be created: "
              << SDL_GetError() << '\n';

    SDL_Quit();
    return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

    if (renderer == nullptr)
    {
    std::cerr << "Renderer could not be created: "
              << SDL_GetError() << '\n';

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
    }

    bool running = true;

    while (running)
    {
    // ====================
    // INPUT
    // ====================

    SDL_Event event{};

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
        {
            running = false;
        }

        if (event.type == SDL_EVENT_KEY_DOWN &&
            event.key.key == SDLK_ESCAPE)
        {
            running = false;
        }
    }

    // ====================
    // UPDATE
    // ====================

    // There is no game state to update yet.

    // ====================
    // RENDER
    // ====================

    SDL_SetRenderDrawColor(renderer, 38, 34, 30, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}