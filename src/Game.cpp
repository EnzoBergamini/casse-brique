#include "../include/Game.hpp"
#include "../include/Window.hpp"

Game::Game() : m_score(0), m_slider(std::pair<int, int>(25, 5), 70, 15), m_window(Window("casse brique", 800, 600)), m_ball(Ball(std::pair<int, int>(400, 300), 10, std::pair<int, int>(1, 1))) {}

void Game::loadBricks(char const *filename){
    Loader::load(filename, m_bricks);
}

void Game::run() {
    std::cout << "Running game..." << std::endl;
    m_window.init(m_score, m_bricks, m_slider, m_ball);

    SDL_Event e;

    while (true)
    {
        if (!handleEvent(e))
        {
            break;
        }
        m_window.init(m_score, m_bricks, m_slider, m_ball);
    }
    m_window.~Window();
    std::cout << "Game over" << std::endl;
}

bool Game::handleEvent(SDL_Event &e) {
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym)
            {
            case SDLK_LEFT:
                m_slider.move(Direction::LEFT);
                break;
            case SDLK_RIGHT:
                m_slider.move(Direction::RIGHT);
                break;
            case SDLK_ESCAPE:
                return false;
                break;
            default:
                break;
            }
        }
    }
    return true;
}