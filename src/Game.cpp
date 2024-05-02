#include "../include/Game.hpp"

Game::initBricks(int n) {
    for (int i = 0; i < n; i++) {
        bricks.push_back(Brick(1, make_pair(0, 0)));
    }
}