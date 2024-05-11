#include "../include/Coordinate.hpp"

Coordinate::Coordinate() : m_x(0), m_y(0) {}

Coordinate::Coordinate(int x, int y) : m_x(x), m_y(y) {}

int Coordinate::getX() const {
    return m_x;
}

int Coordinate::getY() const {
    return m_y;
}

void Coordinate::setX(int x) {
    m_x = x;
}

void Coordinate::setY(int y) {
    m_y = y;
}
