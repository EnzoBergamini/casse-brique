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

    std::vector<Coordinate> getHitbox() const override;

    bool hit();

    bool operator==(const Brick &brick) const;
private:
    int m_health;
    int m_width;
    int m_height;
};