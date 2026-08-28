#pragma once

#include <SDL3/SDL.h>
#include "Player.hpp"

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

    Player player_;

    static constexpr int kWindowWidth = 1280;
    static constexpr int kWindowHeight = 720;
};