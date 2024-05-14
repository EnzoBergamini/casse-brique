#pragma once

#include <iostream>
#include <utility>

class Coordinate {
public:
    Coordinate();
    Coordinate(int x, int y);

    int getX() const;
    int getY() const;

    void setX(int x);
    void setY(int y);

    bool operator==(Coordinate const &rhs) const;

    Coordinate operator+(Coordinate const &rhs) const;
    Coordinate operator-(Coordinate const &rhs) const;
    Coordinate operator*(float scalar) const;
    Coordinate operator*(int scalar) const;

    float dot(Coordinate const &rhs) const;

private:
    int m_x;
    int m_y;
};

Coordinate operator*(int scalar, Coordinate const &coord);