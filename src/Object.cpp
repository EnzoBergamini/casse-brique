#include "../include/Object.hpp"

Object::Object(Coordinate coordinates) : m_coordinates(coordinates) {} 

Coordinate Object::getCoordinates() const {
    return m_coordinates;
}

void Object::setCoordinates(Coordinate coordinates) {
    m_coordinates = coordinates;
}

bool Object::isColliding(Object const &other) const {
    std::vector<Coordinate> hitbox = getHitbox();
    std::vector<Coordinate> otherHitbox = other.getHitbox();
    for (Coordinate const &coordinate : hitbox) {
        for (Coordinate const &otherCoordinate : otherHitbox) {
            if (coordinate == otherCoordinate) {
                return true;
            }
        }
    }
    return false;
}