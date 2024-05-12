#pragma once
#include "Brick.hpp"
#include "Slider.hpp"
#include "Ball.hpp"
#include "RenderHandler.hpp"

#include <SDL.h>
#include <iostream>
#include <memory>

enum class WindowState {
    GAME,
    MAIN_TITLE,
    GAME_OVER,
    PAUSE,
    WIN,
    LOADER_SCREEN
};



class Window {
public:
    Window();
    ~Window();

    void mainLoop();
    void gameLoop();

private:

    RenderHandler m_renderHandler;
    WindowState m_WindowState;
};