#pragma once
#include "Brick.hpp"
#include "Loader.hpp"

#include <vector>

class Game {
public:
    Game();
    void loadBricks(char const *filename);

private:
    std::vector<Brick> bricks;
    int nb_lines_bricks;
    int nb_columns_bricks;
};