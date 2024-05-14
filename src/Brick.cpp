#include "../include/Brick.hpp"

Brick::Brick(int health, Coordinate coordinates, int width, int height) 
    : Object(coordinates), m_health(health), m_width(width), m_height(height) {}

bool Brick::ballCollide(Ball const& ball) {
    return  (m_coordinates.getX() < ball.getCoordinates().getX() + ball.getRadius() &&
             m_coordinates.getX() + m_width > ball.getCoordinates().getX() &&
             m_coordinates.getY() < ball.getCoordinates().getY() + ball.getRadius() &&
             m_coordinates.getY() + m_height > ball.getCoordinates().getY());
}


bool Brick::hit() {
    if (m_health <= 1){
        m_health--;
        return true;
    }
    m_health--;
    return false;
}

bool Brick::operator==(const Brick &brick) const {
    return m_coordinates == brick.getCoordinates();
}

