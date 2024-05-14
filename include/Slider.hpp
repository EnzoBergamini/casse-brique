#pragma once

#include "Direction.hpp"
#include "Object.hpp"
#include "Ball.hpp"

#include <SDL.h>
#include <utility>

class Slider : public Object {
public:
    Slider(Coordinate coordinates, int width, int height);

    void move(Direction dir = Direction::MOUSE, int velocity = 1);

    void handleEvent(SDL_Event const &e);

    inline void incrementWidth(int increment) { m_width += increment;} 
    inline int getWidth() const { return m_width; }
    inline int getHeight() const { return m_height; }



    bool ballCollide(Ball const& ball) const;

private:
    int m_width;
    int m_height;
};