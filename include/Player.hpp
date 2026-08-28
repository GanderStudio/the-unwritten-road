#pragma once

#include <SDL3/SDL.h>

class Player
{
public:
    void update();
    void render(SDL_Renderer* renderer) const;

private:
    SDL_FRect rectangle_{
        100.0F,
        100.0F,
        48.0F,
        48.0F
    };
};