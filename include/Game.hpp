#pragma once
#include "Slider.hpp"
#include "Window.hpp"
#include "Brick.hpp"
#include "Loader.hpp"
#include "Ball.hpp"

#include <vector>
#include <algorithm>

enum class GameState {
    RUNNING,
    GAME_OVER,
    PAUSE,
    WIN
};

class Game {
public:
    Game();
    void loadBricks(char const *filename);
    GameState update(SDL_event &e);
    GameState handleEvent(SDL_Event &e);
    GameState checkCollision();

private:
    std::vector<Brick> m_bricks;
    Slider m_slider;
    Ball m_ball;
    int m_score;
    GameState m_state;
};