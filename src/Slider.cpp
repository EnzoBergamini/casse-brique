#include "../include/Slider.hpp"
#include <iostream>

Slider::Slider(Coordinate coordinates, int width, int height) : Object(coordinates), m_width(width), m_height(height) {}

void Slider::move(Direction dir, int velocity) {
    switch (dir) {
        case Direction::LEFT:
            m_coordinates.setY(m_coordinates.getY() - velocity);
            break;
        case Direction::RIGHT:
            m_coordinates.setY(m_coordinates.getY() + velocity);
            break;
        case Direction::MOUSE:
            m_coordinates.setY(m_coordinates.getY() + velocity);
            break;
    }
}   

void Slider::draw(SDL_Renderer *renderer) const{
    SDL_Rect rect = {
        m_coordinates.getY() * 20,
        m_coordinates.getX() * 20, 
        m_width, 
        m_height
    };

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);    
}