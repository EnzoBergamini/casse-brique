#pragma once
#include <iostream>
#include <utility>
#include <vector>

class Brick {
public:
    Brick(int health, std::pair <int, int> coordinates);

    int getHealth() const;
    std::pair <int, int> getCoordinates() const;
private:
    int health;
    std::pair <int, int> coordinates;
};

std::ostream &operator<<(std::ostream &os, const Brick &brick);