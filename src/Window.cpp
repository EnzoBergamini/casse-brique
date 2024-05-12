#include "../include/Window.hpp"

Window::Window()
    : m_renderHandler(std::make_unique<RenderHandler>(m_window, m_renderer, m_size))


Window::~Window()
{
}

void Window::mainLoop()
{
    SDL_Event e;
    while (true)
    {
        
        if (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                break;
            }
        }
    }
}

std::pair<int, int> Window::getSize() const
{
    return m_size;
}