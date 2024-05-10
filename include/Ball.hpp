#pragma once

#include "Object.hpp"

#include <SDL.h>
#include <utility>

class Ball : public Object {
public:
    Ball(std::pair<int, int> coordinates, int radius, std::pair<int, int> velocity);

    void move();

    void draw(SDL_Renderer *renderer) const override;

private:
    int m_radius;
    std::pair<int, int> m_velocity;
};