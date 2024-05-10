#include "../include/Object.hpp"

Object::Object(std::pair<int, int> coordinates) : m_coordinates(coordinates) {} 

std::pair<int, int> Object::getCoordinates() const {
    return m_coordinates;
}

void Object::setCoordinates(std::pair<int, int> coordinates) {
    m_coordinates = coordinates;
}