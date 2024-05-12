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
    // Ici seuelemnt en lancement de jeu
    m_WindowState = WindowState::GAME;
    gameLoop();
    std::cout << "Game loop ended" << std::endl;
}

void Window::gameLoop()
{
    //Commence toujours en GAME
    Game game = Game();
    game.loadBricks("map");
    std::cout << "Game loaded" << std::endl;
    SDL_Event e;
    while (game.update() != GameState::RUNNING)
    {
        m_renderHandler.renderGame(game);
    }
}