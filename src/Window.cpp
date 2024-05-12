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
    //Commence toujours en MAIN_TITLE
    // Ici seuelemnt en lancement de jeu
    gameLoop();
}

void Window::gameLoop()
{
    //Commence toujours en GAME
    Game game;
    SDL_Event e;
    while (game.update() != GameState::RUNNING)
    {
        m_renderHandler.renderGame(game);
    }
}