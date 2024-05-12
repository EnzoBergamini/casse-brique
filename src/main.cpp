#include "../include/Window.hpp"
#include "../include/MainTitle.hpp"
#include "../include/Game.hpp"
#include "../include/Brick.hpp"
#include "../include/Loader.hpp"
#include <iostream>
#include <memory>
#include <SDL.h>

int main()
{
    MainTitle mainTitle = MainTitle("casse brique", 800, 600);
    mainTitle.init();

    // Game game = Game();
    // game.loadBricks("map");

    // game.run();
    return 0;
}