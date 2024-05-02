#include "../include/Game.hpp"

void Game::initBricks(char const *filename)
{
    Loader::load(filename, bricks);
}