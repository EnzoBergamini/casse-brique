#pragma once
#include <iostream>

class Brick {
public:
    Brick(int health, pair <int, int> coordinates);
private:
    int health;
    pair <int, int> coordinates;
}