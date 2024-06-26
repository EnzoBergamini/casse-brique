#pragma once

#include "Object.hpp"
#include "Slider.hpp"

#include <SDL.h>
#include <utility>

class Slider;

class Ball : public Object {
public:
    Ball(Coordinate coordinates, int radius, float speed, float angle);

    void move();

    inline int getRadius() const { return m_radius; }
    inline void setRadius(int radius) { m_radius = radius; }      
    inline float getSpeed() const { return m_speed; }
    inline float getAngle() const { return m_angle; }

    bool ballCollide(Ball const& ball) const;

    void bounceOnSlider(Slider const& slider);

    void bounce(Coordinate normal);

protected:
    int m_radius;
    float m_speed;
    float m_angle;
    bool m_can_bounce = true;
};