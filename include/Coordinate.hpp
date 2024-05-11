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

private:
    int m_x;
    int m_y;
};