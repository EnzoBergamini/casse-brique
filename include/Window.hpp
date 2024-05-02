#pragma once
#include <SDL.h>
#include <iostream>
#include <memory>


class Window {
public:
    Window(char const *title, int const width, int const height);
    ~Window();

    void waitQuit();

private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> main_window;
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> main_renderer;
};