#pragma once

#include "Direction.hpp"
#include <SDL.h>
#include <utility>

class Slider {
public:
    Slider(std::pair<int, int> coordinates, int width, int height);

    void move(Direction dir);

    void handleEvent(SDL_Event const &e);

    void draw(SDL_Renderer *renderer) const;

    std::pair<int, int> getCoordinates() const;

private:
    int m_width;
    int m_height;
    std::pair<int, int> m_coordinates;
};