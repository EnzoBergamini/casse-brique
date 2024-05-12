#pragma once
#include "Brick.hpp"
#include "Slider.hpp"
#include "Ball.hpp"
#include "Game.hpp"
#include "WindowState.hpp"

#include <SDL.h>
#include <iostream>
#include <memory>

class RenderHandler {
public:
    RenderHandler(char const *title, int const width, int const height);
    ~RenderHandler();

    std::pair<int, int> getSize() const;

    void renderGame(Game const &game);
    void renderMainTitle();
    void renderGameOver(int const score);
    void renderPause();
    void renderWin(int const score);
    void renderLoaderScreen();


private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;

    mutable WindowState m_WindowState;
    std::pair<int, int> m_size;
};