#include "Game.hpp"

#include <iostream>

Game::~Game()
{
    shutdown();
}

bool Game::initialize()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cerr << "SDL could not initialize: "
                  << SDL_GetError() << '\n';

        return false;
    }

    window_ = SDL_CreateWindow(
        "The Unwritten Road",
        kWindowWidth,
        kWindowHeight,
        0
    );

    if (window_ == nullptr)
    {
        std::cerr << "Window could not be created: "
                  << SDL_GetError() << '\n';

        return false;
    }

    renderer_ = SDL_CreateRenderer(window_, nullptr);

    if (renderer_ == nullptr)
    {
        std::cerr << "Renderer could not be created: "
                  << SDL_GetError() << '\n';

        return false;
    }

    SDL_SetRenderVSync(renderer_, 1);

    running_ = true;
    return true;
}

void Game::run()
{
    while (running_)
    {
        input();
        update();
        render();
    }
}

void Game::input()
{
    SDL_Event event{};

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
        {
            running_ = false;
        }

        if (event.type == SDL_EVENT_KEY_DOWN &&
            event.key.key == SDLK_ESCAPE)
        {
            running_ = false;
        }
    }
}

void Game::update()
{
    // There is no game state to update yet.
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer_, 38, 34, 30, 255);
    SDL_RenderClear(renderer_);

    SDL_SetRenderDrawColor(renderer_, 221, 184, 94, 255);
    SDL_RenderFillRect(renderer_, &playerRectangle_);

    SDL_RenderPresent(renderer_);
}

void Game::shutdown()
{
    running_ = false;

    if (renderer_ != nullptr)
    {
        SDL_DestroyRenderer(renderer_);
        renderer_ = nullptr;
    }

    if (window_ != nullptr)
    {
        SDL_DestroyWindow(window_);
        window_ = nullptr;
    }

    SDL_Quit();
}