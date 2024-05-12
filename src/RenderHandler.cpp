#include "../include/RenderHandler.hpp"

RenderHandler::RenderHandler(char const *title, int const width, int const height)
    : m_window(nullptr, SDL_DestroyWindow), m_renderer(nullptr, SDL_DestroyRenderer), m_size(std::pair<int, int>(width, height))
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    std::cout << "SDL_Init Success" << std::endl;

    m_window.reset(SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN));
    if (m_window == nullptr)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    m_renderer.reset(SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
    if (m_renderer == nullptr)
    {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

}

RenderHandler::~RenderHandler()
{
    SDL_destroyRenderer(m_renderer.get());
    SDL_destroyWindow(m_window.get());
    SDL_Quit();
}

void RenderHandler::renderGame(Game const &g)
{
    SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 0, 255);
    SDL_RenderClear(m_renderer.get());

    for( auto const &brick : g.bricks)
    {
        brick.draw(m_renderer.get());
    }

    g.slider.draw(m_renderer.get());
    g.ball.draw(m_renderer.get());
    

    SDL_RenderPresent(m_renderer.get());
}

void RenderHandler::renderMainTitle()
{
    SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 255, 255);
    SDL_RenderClear(m_renderer.get());

    SDL_RenderPresent(m_renderer.get());
}

void RenderHandler::renderGameOver(int const score)
{
    SDL_SetRenderDrawColor(m_renderer.get(), 0, 255, 0, 255);
    SDL_RenderClear(m_renderer.get());

    SDL_RenderPresent(m_renderer.get());
}

void RenderHandler::renderPause()
{
    SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 0, 255);
    SDL_RenderClear(m_renderer.get());

    SDL_RenderPresent(m_renderer.get());
}

void RenderHandler::renderWin(int const score)
{
    SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 0, 255);
    SDL_RenderClear(m_renderer.get());

    SDL_RenderPresent(m_renderer.get());
}

void RenderHandler::renderLoaderScreen()
{
    SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 0, 255);
    SDL_RenderClear(m_renderer.get());

    SDL_RenderPresent(m_renderer.get());
}

std::pair<int, int> RenderHandler::getSize() const
{
    return m_size;
}