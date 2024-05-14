#pragma once
#include "Brick.hpp"
#include "Slider.hpp"
#include "Ball.hpp"
#include "RenderHandler.hpp"

#include <SDL.h>
#include <iostream>
#include <memory>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

enum class WindowState {
    GAME,
    MAIN_TITLE,
    GAME_OVER,
    PAUSE,
    PAUSE_AND_SAVED,
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