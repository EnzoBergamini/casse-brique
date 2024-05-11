#pragma once

#include "../include/Coordinate.hpp"

#include <SDL.h>
#include <utility>
#include <vector>

class Object {
public:
    Object(Coordinate coordinates);
    Coordinate getCoordinates() const;
    void setCoordinates(Coordinate coordinates);

    bool isColliding(Object const &other) const;

    virtual std::vector<Coordinate> getHitbox() const = 0;

    virtual void draw(SDL_Renderer *renderer) const = 0;

protected:
    Coordinate m_coordinates;
};