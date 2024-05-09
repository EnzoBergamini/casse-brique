#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <SDL.h>

class Brick {
public:
    Brick(int health, std::pair <int, int> coordinates, int width, int height);

    int getHealth() const;
    std::pair <int, int> getCoordinates() const;

    void draw(SDL_Renderer *renderer) const;
private:
    int m_health;
    int m_width;
    int m_height;
    std::pair <int, int> m_coordinates;
};

std::ostream &operator<<(std::ostream &os, const Brick &brick);