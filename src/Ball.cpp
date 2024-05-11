#include "../include/Ball.hpp"

Ball::Ball(Coordinate coordinates, int radius, Coordinate velocity) : Object(coordinates), m_radius(radius), m_velocity(velocity) {}

void Ball::move() {
    m_coordinates.setX(m_coordinates.getX() + m_velocity.getX());
    m_coordinates.setY(m_coordinates.getY() + m_velocity.getY());
}

void Ball::draw(SDL_Renderer *renderer) const{
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (int i = 0; i < m_radius; i++) {
        for (int j = 0; j < m_radius; j++) {
            if (i * i + j * j <= m_radius * m_radius) {
                SDL_RenderDrawPoint(renderer, m_coordinates.getX() + i, m_coordinates.getY() + j);
                SDL_RenderDrawPoint(renderer, m_coordinates.getX() - i, m_coordinates.getY() + j);
                SDL_RenderDrawPoint(renderer, m_coordinates.getX() + i, m_coordinates.getY() - j);
                SDL_RenderDrawPoint(renderer, m_coordinates.getX() - i, m_coordinates.getY() - j);
            }
        }
    }
}

void Ball::setVelocity(Coordinate velocity) {
    m_velocity = velocity;
}

Coordinate Ball::getVelocity() const {
    return m_velocity;
}

