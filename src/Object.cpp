#include "../include/Object.hpp"

Object::Object(Coordinate coordinates) : m_coordinates(coordinates) {} 

Coordinate Object::getCoordinates() const {
    return m_coordinates;
}

void Object::setCoordinates(Coordinate coordinates) {
    m_coordinates = coordinates;
}