#pragma once

#include <SDL.h>
#include <utility>

class Ball {
public:
    Ball(std::pair<int, int> coordinates, int radius, std::pair<int, int> velocity);

    void move();

    void draw(SDL_Renderer *renderer) const;

private:
    int m_radius;
    std::pair<int, int> m_coordinates;
    std::pair<int, int> m_velocity;
};