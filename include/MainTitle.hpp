#pragma once
#include <SDL.h>
#include <iostream>
#include <memory>


class MainTitle {
public:
    MainTitle(char const *title, int const width, int const height);
    ~MainTitle();

    std::pair<int, int> getSize() const;

    void init();
    bool handleEvent(SDL_Event &e);

private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;

    std::pair<int, int> m_size;
};