#pragma once

#include "../include/Coordinate.hpp"

#include <SDL.h>
#include <utility>

class Object {
public:
    Object(Coordinate coordinates);
    Coordinate getCoordinates() const;
    void setCoordinates(Coordinate coordinates);

    virtual void draw(SDL_Renderer *renderer) const = 0;

protected:
    Coordinate m_coordinates;
};