#pragma once

#include "Object.hpp"

#include <SDL.h>
#include <utility>

class Ball : public Object {
public:
    Ball(Coordinate coordinates, int radius, Coordinate velocity);

    void move();
    void setVelocity(Coordinate velocity);
    bool ballCollide(Ball const& ball) const;

    inline Coordinate getVelocity() const { return m_velocity; }
    inline int getRadius() const { return m_radius; }
    inline void setRadius(int radius) { m_radius = radius; }      

protected:
    int m_radius;
    Coordinate m_velocity;
};