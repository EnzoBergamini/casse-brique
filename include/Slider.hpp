#pragma once

#include "Direction.hpp"
#include "Object.hpp"

#include <SDL.h>
#include <utility>

class Slider : public Object {
public:
    Slider(std::pair<int, int> coordinates, int width, int height);

    void move(Direction dir);

    void handleEvent(SDL_Event const &e);

    void draw(SDL_Renderer *renderer) const override;


private:
    int m_width;
    int m_height;
};