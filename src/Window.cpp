#include "../include/Window.hpp"

Window::Window(char const *title, int const width, int const height)
    : m_window(nullptr, SDL_DestroyWindow), m_renderer(nullptr, SDL_DestroyRenderer)
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

Window::~Window()
{
    SDL_Quit();
}

void Window::init(int const score, std::vector<Brick> const &bricks)
{
    SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 0, 255);
    SDL_RenderClear(m_renderer.get());

    SDL_SetRenderDrawColor(m_renderer.get(), 255, 255, 255, 255);
    SDL_RenderDrawPoint(m_renderer.get(), 400, 300);

    drawBricks(bricks);

    SDL_RenderPresent(m_renderer.get());
    
}

void Window::drawBricks(std::vector<Brick> const &bricks)
{
    for (auto const &brick : bricks)
    {
        SDL_Rect rect;
        rect.x = brick.getCoordinates().second * 40;
        rect.y = brick.getCoordinates().first * 20;
        rect.w = 40;
        rect.h = 20;

        SDL_SetRenderDrawColor(m_renderer.get(), 255, 255, 255, 255);
        SDL_RenderFillRect(m_renderer.get(), &rect);
    }
}

void Window::waitQuit()
{
    SDL_Event e;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
            {
                quit = true;
            }
        }
    }
    Window::~Window();
}
