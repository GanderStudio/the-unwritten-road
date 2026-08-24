#pragma once

#include <SDL3/SDL.h>

class Game
{
public:
    Game() = default;
    ~Game();

    bool initialize();
    void run();

private:
    void input();
    void update();
    void render();
    void shutdown();

    bool running_ = false;

    SDL_Window* window_ = nullptr;
    SDL_Renderer* renderer_ = nullptr;

    SDL_FRect playerRectangle_{
        100.0F,
        100.0F,
        48.0F,
        48.0F
    };

    static constexpr int kWindowWidth = 1280;
    static constexpr int kWindowHeight = 720;
};