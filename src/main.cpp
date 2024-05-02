#include "../include/Window.hpp"
#include "../include/Game.hpp"
#include "../include/Brick.hpp"
#include "../include/Loader.hpp"
#include <iostream>
#include <memory>
#include <SDL.h>

int main()
{
    std::vector<Brick> bricks;
    Loader::load("map", bricks);

    for (auto &brick : bricks)
    {
        std::cout << brick << std::endl;
    }

    // Game game();
    // Window window("Hello World", 800, 800);
    // window.waitQuit();
    return 0;
}