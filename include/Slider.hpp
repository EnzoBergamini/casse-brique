#pragma once

#include "Direction.hpp"
#include "Object.hpp"

#include <SDL.h>
#include <utility>

class Slider : public Object {
public:
    Slider(Coordinate coordinates, int width, int height);

    void move(Direction dir = Direction::MOUSE, int velocity = 1);

    void handleEvent(SDL_Event const &e);

    void draw(SDL_Renderer *renderer) const override;

    std::vector<Coordinate> getHitbox() const override;

    int getWidth() const;

    int getHeight() const;



private:
    int m_width;
    int m_height;
};