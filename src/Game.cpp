#include "../include/Game.hpp"
#include "../include/Window.hpp"

#include <cmath>

Game::Game() : m_score(0), m_slider(Coordinate(300, 500), 70, 15), m_window(Window("casse brique", 800, 600)), m_ball(Ball(Coordinate(300, 400), 10, Coordinate(-5, 5))) {}

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
        SDL_Delay(30);
        m_ball.move();
        if (checkCollision())
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
                m_slider.move(Direction::LEFT, 20);
                break;
            case SDLK_RIGHT:
                m_slider.move(Direction::RIGHT, 20);
                break;
            case SDLK_ESCAPE:
                return false;
                break;
            default:
                break;
            }
        }else if (e.type == SDL_MOUSEMOTION)
        {
            if (e.motion.xrel > 0){
                std::cout << "Mouse motion right : " << sqrt(e.motion.xrel) + 1 << std::endl;
                m_slider.move(Direction::MOUSE, sqrt(e.motion.xrel) + 1);
            } else {
                std::cout << "Mouse motion left : " << -log(-e.motion.xrel) - 1 << std::endl;
                m_slider.move(Direction::MOUSE, -sqrt(-e.motion.xrel) - 1);
            }
            
        }
    }
    return true;
}

bool Game::checkCollision() {
    if (m_ball.getCoordinates().getX() < 0 || m_ball.getCoordinates().getX() > 800)
    {
        std::cout << "ball position : " << m_ball.getCoordinates().getX() << " , " << m_ball.getCoordinates().getY() << std::endl;
        m_ball.setVelocity(Coordinate(-m_ball.getVelocity().getX(), m_ball.getVelocity().getY()));
    }
    if (m_ball.getCoordinates().getY() < 0 || m_ball.getCoordinates().getY() > 600)
    {
        std::cout << "ball position : " << m_ball.getCoordinates().getX() << " , " << m_ball.getCoordinates().getY() << std::endl;
        m_ball.setVelocity(Coordinate(m_ball.getVelocity().getX(), -m_ball.getVelocity().getY()));
    }

    return false;
}