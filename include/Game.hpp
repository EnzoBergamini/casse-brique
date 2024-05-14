#pragma once
#include "Slider.hpp"
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
    GameState update(SDL_Event &e);
    GameState handleEvent(SDL_Event &e);
    GameState checkCollision();

    inline std::vector<Brick> const &getBricks() const { return m_bricks; }
    inline Slider const &getSlider() const { return m_slider; }
    inline std::vector<Ball> const &getBalls() const { return m_balls; }
    inline int getScore() const { return m_score; }
    inline GameState getState() const { return m_state; }

private:
    std::vector<Brick> m_bricks;
    Slider m_slider;
    std::vector<Ball> m_balls;
    int m_score;
    mutable GameState m_state;
};