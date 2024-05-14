#pragma once
#include "Game.hpp"

#include <SDL.h>
#include <iostream>
#include <memory>

class RenderHandler {
public:
    RenderHandler(char const *title, int const width, int const height);
    ~RenderHandler();

    inline std::pair<int, int> getSize() const { return m_size; }
    SDL_Texture* loadTexture(char const *path, bool const transparancy = false);

    void renderGame(Game const &game);
    void renderMainTitle();
    void renderGameOver(int const score);
    void renderPause();
    void renderPauseAndSaved();
    void renderWin(int const score);
    void renderLoaderScreen();

    void renderBrick(Brick const &brick);
    void renderSlider(Slider const &slider);
    void renderBall(Ball const &ball);
    void renderBonus(Bonus const &bonus);
    void renderBullet(Ball const &bullet);

private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
    std::pair<int, int> m_size;

    SDL_Texture* m_brickTexture;
    SDL_Texture* m_sliderTexture;
    SDL_Texture* m_ballTexture;
    SDL_Texture* m_bulletTexture;

    SDL_Texture* m_bonus_add_ballTexture;
    SDL_Texture* m_bonus_bulletTexture;
    SDL_Texture* m_bonus_increase_sliderTexture;
    SDL_Texture* m_bonus_increase_ballsTexture;
    SDL_Texture* m_bonus_lifeTexture;
    SDL_Texture* m_bonus_little_ballsTexture;
    


};