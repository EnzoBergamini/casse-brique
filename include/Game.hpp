#pragma once
#include "Brick.hpp"
#include <vector>

class Game {
public:
    Game();
    void initBricks(int n);

private:
    vector<Brick> bricks;
};