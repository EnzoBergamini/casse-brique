#pragma once

#include "Object.hpp"

#include <iostream>
#include <utility>
#include <vector>
#include <SDL.h>

class Brick : public Object {
public:
    Brick(int health, std::pair <int, int> coordinates, int width, int height);

    int getHealth() const;
    std::pair <int, int> getCoordinates() const;

    void draw(SDL_Renderer *renderer) const override;
private:
    int m_health;
    int m_width;
    int m_height;
};

std::ostream &operator<<(std::ostream &os, const Brick &brick);