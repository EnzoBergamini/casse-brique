#include "../include/Window.hpp"
#include "../include/Game.hpp"
#include "../include/Brick.hpp"
#include "../include/Loader.hpp"
#include <iostream>
#include <memory>
#include <SDL.h>

int main()
{
    Game game = Game();
    game.loadBricks("map");

    game.run();
    return 0;
}