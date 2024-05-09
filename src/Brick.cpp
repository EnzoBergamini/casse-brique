#include "../include/Brick.hpp"

Brick::Brick(int health, std::pair <int, int> coordinates, int width, int height) : m_health(health), m_coordinates(coordinates), m_width(width), m_height(height) {}

int Brick::getHealth() const {
    return m_health;
}

void Brick::draw(SDL_Renderer *renderer) const {
    SDL_Rect rect = {
        m_coordinates.second * m_width,
        m_coordinates.first * m_height,
        m_width, 
        m_height
    };
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

std::pair <int, int> Brick::getCoordinates() const {
    return m_coordinates;
}

std::ostream &operator<<(std::ostream &os, const Brick &brick) {
    os << "Brick: health(" << brick.getHealth() << "), line(" << brick.getCoordinates().first << "), column(" << brick.getCoordinates().second << ")";
    return os;
}