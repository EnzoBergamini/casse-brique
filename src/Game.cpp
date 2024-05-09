#include "../include/Game.hpp"
#include "../include/Window.hpp"

Game::Game() : m_score(0), m_slider(std::pair<int, int>(25, 5)), m_window(Window("casse brique", 800, 600)) {}

void Game::loadBricks(char const *filename){
    Loader::load(filename, m_bricks);
}

void Game::run() {
    std::cout << "Running game..." << std::endl;
    m_window.init(m_score, m_bricks, m_slider);

    SDL_Event e;

    while (true)
    {
        if (!handleEvent(e))
        {
            break;
        }
        m_window.init(m_score, m_bricks, m_slider);
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