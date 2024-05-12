#include "../include/Game.hpp"
#include "../include/Window.hpp"

#include <cmath>

Game::Game() : m_score(0), m_slider(Coordinate(300, 500), 70, 15), m_ball(Ball(Coordinate(300, 400), 10, Coordinate(-7, 7))) {}

void Game::loadBricks(char const *filename){
    Loader::load(filename, m_bricks);
}

GameState Game::update(SDL_event &e) {
    //Optimisable
    if ((m_state = handleEvent(e)) != GameState::RUNNING)
    {
        return m_state;
    }
    m_ball.move();
    if ((m_state = checkCollision()) != GameState::RUNNING)
    {
        return m_state;
    }
}

GameState Game::handleEvent(SDL_Event &e) {
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
                return GameState::PAUSE;
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
    return GameState::RUNNING;
}

GameState Game::checkCollision() {
    if (m_ball.getCoordinates().getX() < 0 || m_ball.getCoordinates().getX() > 800)
    {
        std::cout << "wall collision" << std::endl;
        m_ball.setVelocity(Coordinate(-m_ball.getVelocity().getX(), m_ball.getVelocity().getY()));
    }
    if (m_ball.getCoordinates().getY() < 0 || m_ball.getCoordinates().getY() > 600)
    {
        std::cout << "wall collision" << std::endl;
        m_ball.setVelocity(Coordinate(m_ball.getVelocity().getX(), -m_ball.getVelocity().getY()));
    }
    if (m_slider.isColliding(m_ball))
    {
        std::cout << "slider collision" << std::endl;
        m_ball.setVelocity(Coordinate(m_ball.getVelocity().getX(), -m_ball.getVelocity().getY()));
    }
    if (m_ball.getCoordinates().getY() > 600)
    {
        return GameState::GAME_OVER;
    }

    for (auto &brick : m_bricks)
    {
        if (brick.isColliding(m_ball))
        {
            std::cout << "brick collision coord : " << brick.getCoordinates().getX() << " " << brick.getCoordinates().getY() << std::endl;
            m_score++;
            m_ball.setVelocity(Coordinate(m_ball.getVelocity().getX(), -m_ball.getVelocity().getY()));
            if (brick.hit()){
                m_bricks.erase(std::remove(m_bricks.begin(), m_bricks.end(), brick), m_bricks.end());
                if (m_bricks.empty())
                {
                    return GameState::WIN;
                }
            }
        }
    }

    return GameState::RUNNING;
}