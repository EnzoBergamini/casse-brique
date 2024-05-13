#pragma once
#include "Brick.hpp"
#include "Slider.hpp"
#include "Ball.hpp"
#include "Game.hpp"

#include <SDL.h>
#include <iostream>
#include <memory>

class RenderHandler {
public:
    RenderHandler(char const *title, int const width, int const height);
    ~RenderHandler();

    std::pair<int, int> getSize() const;
    SDL_Texture* loadTexture(char const *path);

    void renderGame(Game const &game);
    void renderMainTitle();
    void renderGameOver(int const score);
    void renderPause();
    void renderPauseAndSaved();
    void renderWin(int const score);
    void renderLoaderScreen();


private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
    std::pair<int, int> m_size;
};