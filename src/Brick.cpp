#include "../include/Brick.hpp"

Brick::Brick(int health, std::pair <int, int> coordinates) : health(health), coordinates(coordinates) {}

int Brick::getHealth() const {
    return health;
}

std::pair <int, int> Brick::getCoordinates() const {
    return coordinates;
}

std::ostream &operator<<(std::ostream &os, const Brick &brick) {
    os << "Brick: " << brick.getHealth() << " " << brick.getCoordinates().first << " " << brick.getCoordinates().second;
    return os;
}