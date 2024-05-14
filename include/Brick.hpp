#pragma once

#include "Object.hpp"
#include "Ball.hpp"

#include <iostream>
#include <utility>
#include <vector>
#include <SDL.h>


class Brick : public Object {
public:
    Brick(int health, Coordinate coordinates, int width, int height);

    bool ballCollide(Ball const& ball);
    bool hit();

    inline int getHealth() const { return m_health; }
    inline int getWidth() const { return m_width; }
    inline int getHeight() const { return m_height; }

    bool operator==(const Brick &brick) const;

private:
    int m_health;
    int m_width;
    int m_height;
};