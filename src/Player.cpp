#include "Player.hpp"

void Player::update()
{
    // Player movement will go here next.
}

void Player::render(SDL_Renderer* renderer) const
{
    SDL_SetRenderDrawColor(renderer, 221, 184, 94, 255);
    SDL_RenderFillRect(renderer, &rectangle_);
}