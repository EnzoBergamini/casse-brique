#pragma once

#include "Object.hpp"

#include <iostream>
#include <utility>
#include <vector>
#include <SDL.h>

class Brick : public Object {
public:
    Brick(int health, Coordinate coordinates, int width, int height);

    int getHealth() const;

    void draw(SDL_Renderer *renderer) const override;
private:
    int m_health;
    int m_width;
    int m_height;
};