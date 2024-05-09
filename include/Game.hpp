#pragma once
#include "Brick.hpp"
#include "Loader.hpp"

#include <vector>

class Game {
public:
    Game();
    void loadBricks(char const *filename);
    void run();

private:
    std::vector<Brick> bricks;
    int score;
};