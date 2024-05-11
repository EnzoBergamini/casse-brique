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

void Slider::draw(SDL_Renderer *renderer) const{
    SDL_Rect rect = {
        m_coordinates.getX(),
        m_coordinates.getY(),
        m_width, 
        m_height
    };

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);    
}

int Slider::getWidth() const {
    return m_width;
}

int Slider::getHeight() const {
    return m_height;
}

std::vector<Coordinate> Slider::getHitbox() const {
    std::vector<Coordinate> hitbox;
    for (int i = 0; i < m_width; i++) {
        for (int j = 0; j < m_height; j++) {
            hitbox.push_back(Coordinate(m_coordinates.getX() + i, m_coordinates.getY() + j));
        }
    }
    return hitbox;
}