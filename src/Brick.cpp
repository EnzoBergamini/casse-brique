#include "../include/Brick.hpp"

Brick::Brick(int health, std::pair <int, int> coordinates) : health(health), coordinates(coordinates) {}

int Brick::getHealth() const {
    return health;
}

void Brick::draw(SDL_Renderer *renderer) const {
    SDL_Rect rect = {
        coordinates.second * 40,
        coordinates.first * 20,
        40, 
        20
    };
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

std::pair <int, int> Brick::getCoordinates() const {
    return coordinates;
}

std::ostream &operator<<(std::ostream &os, const Brick &brick) {
    os << "Brick: health(" << brick.getHealth() << "), line(" << brick.getCoordinates().first << "), column(" << brick.getCoordinates().second << ")";
    return os;
}