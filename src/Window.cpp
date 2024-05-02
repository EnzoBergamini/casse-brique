#include "../include/Window.hpp"

Window::Window(char const *title, int const width, int const height)
    : main_window(nullptr, SDL_DestroyWindow), main_renderer(nullptr, SDL_DestroyRenderer)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    std::cout << "SDL_Init Success" << std::endl;

    main_window.reset(SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN));

    main_renderer.reset(SDL_CreateRenderer(main_window.get(), -1, SDL_RENDERER_PRESENTVSYNC));

    SDL_SetRenderDrawColor(main_renderer.get(), 255, 255, 255, 255);

    SDL_Rect rectangle = {100, 100, 200, 200};

    SDL_RenderDrawRect(main_renderer.get(), &rectangle);
    SDL_RenderPresent(main_renderer.get());

}

Window::~Window()
{
    SDL_Quit();
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
