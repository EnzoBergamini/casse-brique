#pragma once
#include "Brick.hpp"
#include "Slider.hpp"
#include "Ball.hpp"

#include <SDL.h>
#include <iostream>
#include <memory>


class Window {
public:
    Window(char const *title, int const width, int const height);
    ~Window();

    void init(int const score, std::vector<Brick> const &bricks, Slider const &slider, Ball const &ball);
    void drawBricks(std::vector<Brick> const &bricks);
    void drawSlider();

    void waitQuit();

private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
};