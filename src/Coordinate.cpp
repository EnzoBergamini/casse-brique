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

bool Coordinate::operator==(Coordinate const &other) const {
    return m_x == other.m_x && m_y == other.m_y;
}

Coordinate Coordinate::operator+(Coordinate const &other) const {
    return Coordinate(m_x + other.m_x, m_y + other.m_y);
}

Coordinate Coordinate::operator-(Coordinate const &other) const {
    return Coordinate(m_x - other.m_x, m_y - other.m_y);
}

Coordinate Coordinate::operator*(float scalar) const {
    return Coordinate(m_x * scalar, m_y * scalar);
}

Coordinate Coordinate::operator*(int scalar) const {
    return Coordinate(m_x * scalar, m_y * scalar);
}

Coordinate operator*(int scalar, Coordinate const &coord) {
    return Coordinate(coord.getX() * scalar, coord.getY() * scalar);
}

float Coordinate::dot(Coordinate const &other) const {
    return m_x * other.m_x + m_y * other.m_y;
}