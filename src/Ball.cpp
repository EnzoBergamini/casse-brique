#include "../include/Ball.hpp"

Ball::Ball(Coordinate coordinates, int radius, Coordinate velocity) : Object(coordinates), m_radius(radius), m_velocity(velocity) {}

void Ball::move() {
    m_coordinates.setX(m_coordinates.getX() + m_velocity.getX());
    m_coordinates.setY(m_coordinates.getY() + m_velocity.getY());
}

void Ball::setVelocity(Coordinate velocity) {
    m_velocity = velocity;
}

bool Ball::ballCollide(Ball const& ball) const   {
    return (m_coordinates.getX() - ball.getCoordinates().getX()) * (m_coordinates.getX() - ball.getCoordinates().getX()) +
           (m_coordinates.getY() - ball.getCoordinates().getY()) * (m_coordinates.getY() - ball.getCoordinates().getY()) <=
           (m_radius + ball.getRadius()) * (m_radius + ball.getRadius());
}

