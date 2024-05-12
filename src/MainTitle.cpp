#include "../include/MainTitle.hpp"

MainTitle::MainTitle(char const *title, int const width, int const height)
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

MainTitle::~MainTitle()
{
    SDL_Quit();
}

void MainTitle::init()
{
    SDL_SetRenderDrawColor(m_renderer.get(), 255, 0, 0, 255);
    SDL_Rect rect = {100, 100, 100, 100};
    SDL_RenderFillRect(m_renderer.get(), &rect); 
    SDL_RenderPresent(m_renderer.get());

    SDL_Event e;
    while (true)
    {
        if (!handleEvent(e))
        {
            break;
        }
    }
}

bool MainTitle::handleEvent(SDL_Event &e) {
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                return false;
                break;
            default:
                break;
            }
        }
        //detecte un clisck 
        else if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            std::cout << "Mouse click" << std::endl;
            //recupere les coordonées du click
            int x = e.button.x;
            int y = e.button.y;
            std::cout << "x : " << x << " y : " << y << std::endl;
        }
    }
    return true;
}

std::pair<int, int> MainTitle::getSize() const
{
    return m_size;
}