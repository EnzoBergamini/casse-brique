#include "../include/Ball.hpp"

Ball::Ball(std::pair<int, int> coordinates, int radius, std::pair<int, int> velocity) : Object(coordinates), m_radius(radius), m_velocity(velocity) {}

void Ball::move() {
    m_coordinates.first += m_velocity.first;
    m_coordinates.second += m_velocity.second;
}

void Ball::draw(SDL_Renderer *renderer) const{
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (int i = 0; i < m_radius; i++) {
        for (int j = 0; j < m_radius; j++) {
            if (i * i + j * j <= m_radius * m_radius) {
                SDL_RenderDrawPoint(renderer, m_coordinates.second + i, m_coordinates.first + j);
                SDL_RenderDrawPoint(renderer, m_coordinates.second - i, m_coordinates.first + j);
                SDL_RenderDrawPoint(renderer, m_coordinates.second + i, m_coordinates.first - j);
                SDL_RenderDrawPoint(renderer, m_coordinates.second - i, m_coordinates.first - j);
            }
        }
    }
}

