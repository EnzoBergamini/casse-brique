#include "../include/Slider.hpp"
#include <iostream>

Slider::Slider(std::pair<int, int> coordinates, int width, int height) : Object(coordinates), m_width(width), m_height(height) {}

void Slider::move(Direction dir, int velocity) {
    switch (dir) {
        case Direction::LEFT:
            m_coordinates.second -= velocity;
            break;
        case Direction::RIGHT:
            m_coordinates.second += velocity;
            break;
        case Direction::MOUSE:
            m_coordinates.second += int(velocity/10);
            break;
    }
}   

void Slider::draw(SDL_Renderer *renderer) const{
    SDL_Rect rect = {
        m_coordinates.second * 20,
        m_coordinates.first * 20, 
        m_width, 
        m_height
    };

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);    
}