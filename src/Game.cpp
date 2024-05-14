#include "../include/Game.hpp"
#include "../include/Window.hpp"

#include <cmath>

Game::Game(BrickType brickType) 
: m_brickType(brickType), m_score(0), m_slider(Coordinate(300, 500), 70, 15), m_state(GameState::RUNNING),
    m_balls(std::vector<Ball>()), m_bonuses(std::vector<Bonus>()), m_bullets(std::vector<Ball>()),
    m_lives(3) 

{
    m_balls.push_back(Ball(Coordinate(200, 300), 20, Coordinate(1, -2)));
    m_balls.push_back(Ball(Coordinate(300, 300), 20, Coordinate(-1, -2)));
    m_balls.push_back(Ball(Coordinate(400, 350), 20, Coordinate(1, -2)));
}

void Game::loadBricks(char const *filename){
    Loader::load(filename, m_bricks);
}

GameState Game::update(SDL_Event &e) {  
    //Optimisable

    if ((m_state = handleEvent(e)) != GameState::RUNNING)
    {
        return m_state;
    }

    for (auto &ball : m_balls)
    {
        ball.move();
    }

    for (auto &bonus : m_bonuses)
    {
        bonus.move();
    }
    
    for (auto &bullet : m_bullets)
    {
        bullet.move();
    }

    if ((m_state = checkCollision()) != GameState::RUNNING)
    {
        return m_state;
    }
    return GameState::RUNNING;
}

GameState Game::handleEvent(SDL_Event &e) {
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym)
            {
            case SDLK_LEFT:
                m_slider.move(Direction::LEFT, 5);
                break;
            case SDLK_RIGHT:
                m_slider.move(Direction::RIGHT, 5);
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

    if ((m_state = checkBallsCollision()) != GameState::RUNNING)
    {
        return m_state;
    }

    if ((m_state = checkBonusesCollision()) != GameState::RUNNING)
    {
        return m_state;
    }

    if ((m_state = checkBulletCollision()) != GameState::RUNNING)
    {
        return m_state;
    }

    return GameState::RUNNING;
}

GameState Game::checkBallsCollision() {
    for (auto &ball : m_balls)
    {

        int ballx = ball.getCoordinates().getX();
        int bally = ball.getCoordinates().getY();

        if (ballx < 0 || ballx > 800)
        {
            std::cout << "wall collision" << std::endl;
            ball.setVelocity(Coordinate(-ball.getVelocity().getX(), ball.getVelocity().getY()));
        }
        if (bally < 0 || bally > 600)
        {
            std::cout << "wall collision" << std::endl;
            ball.setVelocity(Coordinate(ball.getVelocity().getX(), -ball.getVelocity().getY()));
        }
        if (m_slider.ballCollide(ball))
        {
            std::cout << "slider collision" << std::endl;
            ball.setVelocity(Coordinate(ball.getVelocity().getX(), -ball.getVelocity().getY()));
        }
        if (bally > 600)
        {
            m_lives--;
            std::cout << "lives : " << m_lives << std::endl;

            if (m_lives == 0)
            {
                return GameState::GAME_OVER;
            }
        }
        
        // Check collision with bricks
        for (auto &brick : m_bricks)
        {
            if (brick.ballCollide(ball))
            {
                std::cout << "brick collision coord : " << brick.getCoordinates().getX() << " " << brick.getCoordinates().getY() << std::endl;
                m_score++;
                ball.setVelocity(Coordinate(ball.getVelocity().getX(), -ball.getVelocity().getY()));
                if (brick.hit()){
                    m_bricks.erase(std::remove(m_bricks.begin(), m_bricks.end(), brick), m_bricks.end());
                    if (m_bricks.empty())
                    {
                        return GameState::WIN;
                    }
                    // Add bonus
                    if (true)
                    {
                        m_bonuses.push_back(Bonus(Coordinate(brick.getCoordinates().getX(), brick.getCoordinates().getY()), 16));
                    }
                }
            }
        }
        // Check collision with other balls
        // Do not check the first balls that have already been checked
        for (auto &otherBall : m_balls)
        {
            if (&ball != &otherBall && ball.ballCollide(otherBall))
            {
                std::cout << "ball collision" << std::endl;
                ball.setVelocity(Coordinate(ball.getVelocity().getX(), -ball.getVelocity().getY()));
            }
        }
    }
    return GameState::RUNNING;
}

GameState Game::checkBonusesCollision() {
    
    m_bonuses.erase(std::remove_if(m_bonuses.begin(), m_bonuses.end(), [&](Bonus &bonus){
        if (m_slider.ballCollide(bonus))
        {
            applyBonus(bonus);
            return true;
        }
        return false;
    }), m_bonuses.end());
    return GameState::RUNNING;
}

GameState Game::checkBulletCollision() {
    for (auto &bullet : m_bullets)
    {
        for (auto &brick : m_bricks)
        {
            if (brick.ballCollide(bullet))
            {
                std::cout << "brick collision coord : " << brick.getCoordinates().getX() << " " << brick.getCoordinates().getY() << std::endl;
                m_score++;
                if (brick.hit()){
                    m_bricks.erase(std::remove(m_bricks.begin(), m_bricks.end(), brick), m_bricks.end());
                    if (m_bricks.empty())
                    {
                        return GameState::WIN;
                    }
                    // No bonus for bullet
                }
            }
        }
    }
    return GameState::RUNNING;
}

GameState Game::applyBonus(Bonus const &bonus) {
    switch (bonus.getType())
    {
    case BonusType::NONE:
        break;

    case BonusType::ADD_BALL:
        m_balls.push_back(Ball(Coordinate(400, 300), 10, Coordinate(1, 2)));
        break;

    case BonusType::BULLET:
        m_bullets.push_back(Ball(Coordinate(m_slider.getCoordinates().getX(), m_slider.getCoordinates().getY()), 5, Coordinate(0, -5)));
        m_bullets.push_back(Ball(Coordinate(m_slider.getCoordinates().getX() + m_slider.getWidth(), m_slider.getCoordinates().getY()), 5, Coordinate(0, -5)));

        break;
    
    case BonusType::INCREASE_BALLS:
        for(auto &ball : m_balls){
            ball.setRadius(ball.getRadius() + 5);
        }
        break;

    case BonusType::INCREASE_SLIDER:
        m_slider.incrementWidth(5);
        break;
    
    case BonusType::LIFE:
        m_lives++;
        std::cout << "lives : " << m_lives << std::endl;
        break;
    
    case BonusType::LITTLE_BALLS:
        for(auto &ball : m_balls){
            ball.setRadius(5);
        }
    }
    return GameState::RUNNING;
}