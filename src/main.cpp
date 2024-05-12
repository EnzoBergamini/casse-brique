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
    Window window("Breakout", 800, 600);
    window.mainLoop();

    return 0;
}