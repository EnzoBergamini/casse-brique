#pragma once
#include "Slider.hpp"
#include "Window.hpp"
#include "Brick.hpp"
#include "Loader.hpp"

#include <vector>

class Game {
public:
    Game();
    void loadBricks(char const *filename);
    void run();
    bool handleEvent(SDL_Event &e);

private:
    std::vector<Brick> m_bricks;
    Slider m_slider;
    Window m_window;
    int m_score;
};