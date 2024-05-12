#include "../include/Window.hpp"

Window::Window()
    : m_renderHandler("breakout", 800, 600 ), m_WindowState(WindowState::MAIN_TITLE)
{
}

Window::~Window()
{
}

void Window::mainLoop()
{   
    std::cout << "Main loop started" << std::endl;

    //Commence toujours en MAIN_TITLE
    m_renderHandler.renderMainTitle();
    //Check si on pressse sur baree espace pour lancer le jeu
    SDL_Event e;
    SDL_WaitEvent(&e);

    while (true)
    {
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
        {
            m_WindowState = WindowState::GAME;
            gameLoop();
        }

        else if (e.type == SDL_QUIT|| (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
        {
            return;
        }
        
        SDL_WaitEvent(&e);
    }

    
    std::cout << "main loop ended" << std::endl;
    return;
}

void Window::gameLoop()
{
    //Commence toujours en GAME
    Game game = Game();
    game.loadBricks("map");
    std::cout << "Game loaded" << std::endl;
    SDL_Event e;    
    while (game.update(e) == GameState::RUNNING)
    {
        m_renderHandler.renderGame(game);
    }
    std::cout << "Game ended" << std::endl;

    switch (game.getState())
    {
    case GameState::GAME_OVER:
        m_renderHandler.renderGameOver(game.getScore());
        break;

    case GameState::WIN:
        m_renderHandler.renderWin(game.getScore());
        break;
    
    case GameState::PAUSE:
        m_renderHandler.renderPause();
        break;
    
    default:
        break;
    }
    return ;
}