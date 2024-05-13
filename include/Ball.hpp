#pragma once

#include "Object.hpp"

#include <SDL.h>
#include <utility>

class Ball : public Object {
public:
    Ball(Coordinate coordinates, int radius, Coordinate velocity);

    void move();

    void setVelocity(Coordinate velocity);

    Coordinate getVelocity() const;

    void draw(SDL_Renderer *renderer) const override;

    std::vector<Coordinate> getHitbox() const override;
    inline int getRadius() const { return m_radius; }

private:
    int m_radius;
    Coordinate m_velocity;
};