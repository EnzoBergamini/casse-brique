#include "../include/Window.hpp"

Window::Window()
    : m_renderHandler("breakout",800, 600 ), m_WindowState(WindowState::MAIN_TITLE)
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

        else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_l)
        {
            m_WindowState = WindowState::LOADER_SCREEN;
            m_renderHandler.renderLoaderScreen();
            // Ajouter la fenetre du loader et l'heuristique en plus
        }

        else if (e.type == SDL_QUIT|| (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
        {
            break;
        }
        m_renderHandler.renderMainTitle();
        SDL_WaitEvent(&e);

    }       
    std::cout << "main loop ended" << std::endl;
    return;
}

void Window::gameLoop()
{
    //Commence toujours en GAME
    game_loop_beggining :
        Game game = Game( BrickType::RECTANGLE );
        game.loadBricks("map");
        std::cout << "Game loaded" << std::endl;
        
        game_loop_running :
        SDL_Event e;    
        while (game.update(e) == GameState::RUNNING)
        {
            m_renderHandler.renderGame(game);
            SDL_Delay(50);
        }
        
    std::cout << "Game ended" << std::endl;

    switch (game.getState())
    {
    case GameState::GAME_OVER:
        m_WindowState = WindowState::GAME_OVER;
        m_renderHandler.renderGameOver(game.getScore());
        while (true){
            SDL_WaitEvent(&e);
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
            {
                m_WindowState = WindowState::GAME;
                goto game_loop_beggining;
            }

            else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
            {
                break;
            }

            else if (e.type == SDL_QUIT)
            {
                return;
            }
        }
        break;


    case GameState::WIN:
        m_WindowState = WindowState::WIN;
        m_renderHandler.renderWin(game.getScore());
        while (true){
            SDL_WaitEvent(&e);
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
            {
                m_WindowState = WindowState::GAME;
                goto game_loop_beggining;
            }

            else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
            {
                break;
            }

            else if (e.type == SDL_QUIT)
            {
                return;
            }
        }
        break;
    
    case GameState::PAUSE:
        m_WindowState = WindowState::PAUSE;
        m_renderHandler.renderPause();

        while (true){
            SDL_WaitEvent(&e);
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
            {
                m_WindowState = WindowState::GAME;
                goto game_loop_running;
            }

            else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
            {
                break;
            }

            else if (e.type == SDL_QUIT)
            {
                return;
            }

            else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_s)
            {
                m_WindowState = WindowState::PAUSE_AND_SAVED;
                m_renderHandler.renderPauseAndSaved();
            }

        }
        break;
    
    default:
        break;
    }

    m_WindowState = WindowState::MAIN_TITLE;
    return ;
}