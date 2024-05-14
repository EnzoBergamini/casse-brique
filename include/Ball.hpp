#pragma once

#include "Object.hpp"

#include <SDL.h>
#include <utility>

class Ball : public Object {
public:
    Ball(Coordinate coordinates, int radius, Coordinate velocity);

    void move();

    void draw(SDL_Renderer *renderer) const override;

    void setVelocity(Coordinate velocity);

    inline Coordinate getVelocity() const { return m_velocity; }
    inline int getRadius() const { return m_radius; }
    bool ballCollide(Ball const& ball) const;

private:
    int m_radius;
    Coordinate m_velocity;
};