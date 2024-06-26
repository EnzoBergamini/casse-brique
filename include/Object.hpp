#pragma once

#include "../include/Coordinate.hpp"

#include <SDL.h>
#include <utility>
#include <vector>

class Object {
public:
    Object(Coordinate coordinates);

    inline Coordinate getCoordinates() const { return m_coordinates; };

    inline void setCoordinates(Coordinate coordinates) { m_coordinates = coordinates; };

protected:
    Coordinate m_coordinates;
};