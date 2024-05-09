#include "../include/Slider.hpp"

Slider::Slider(std::pair<int, int> coordinates) : m_coordinates(coordinates) {}

void Slider::move(Direction dir) {
    switch (dir) {
        case Direction::LEFT:
            m_coordinates.second--;
            break;
        case Direction::RIGHT:
            m_coordinates.second++;
            break;
    }
}   

void Slider::draw(SDL_Renderer *renderer) const {
    SDL_Rect rect = {
        m_coordinates.second * 40,
        m_coordinates.first * 20, 
        70, 
        15
    };

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);    
}

void Slider::handleEvent(SDL_Event const &e) {
    if (e.type == SDL_KEYDOWN) { // for the keybord
        switch (e.key.keysym.sym) {
            case SDLK_LEFT:
                move(Direction::LEFT);
                break;
            case SDLK_RIGHT:
                move(Direction::RIGHT);
                break;
        }
    } else if (e.type == SDL_MOUSEMOTION) { // for the mouse
        m_coordinates.second = e.motion.x;
    }
}

std::pair<int, int> Slider::getCoordinates() const {
    return m_coordinates;
}