#include "../include/Brick.hpp"

Brick::Brick(int health, Coordinate coordinates, int width, int height) : Object(coordinates), m_health(health), m_width(width), m_height(height) {}

int Brick::getHealth() const {
    return m_health;
}

void Brick::draw(SDL_Renderer *renderer) const{
    SDL_Rect rect = {
        m_coordinates.getY(),
        m_coordinates.getX(),
        m_width, 
        m_height
    };
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

std::vector<Coordinate> Brick::getHitbox() const {
    std::vector<Coordinate> hitbox;
    for (int i = 0; i < m_width; i++) {
        for (int j = 0; j < m_height; j++) {
            hitbox.push_back(Coordinate(m_coordinates.getX() + i, m_coordinates.getY() + j));
        }
    }
    return hitbox;
}

