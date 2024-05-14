#include "../include/Slider.hpp"
#include <iostream>

Slider::Slider(Coordinate coordinates, int width, int height) : Object(coordinates), m_width(width), m_height(height) {}

void Slider::move(Direction dir, int velocity) {
    switch (dir) {
        case Direction::LEFT:
            m_coordinates.setX(m_coordinates.getX() - velocity);
            break;
        case Direction::RIGHT:
            m_coordinates.setX(m_coordinates.getX() + velocity);
            break;
        case Direction::MOUSE:
            m_coordinates.setX(m_coordinates.getX() + velocity);
            break;
    }
}   

bool Slider::ballCollide(Ball const& ball) const {
    return   m_coordinates.getX() < ball.getCoordinates().getX() + ball.getRadius() &&
             m_coordinates.getX() + m_width > ball.getCoordinates().getX() &&
             m_coordinates.getY() < ball.getCoordinates().getY() + ball.getRadius() &&
             m_coordinates.getY() + m_height > ball.getCoordinates().getY();
}