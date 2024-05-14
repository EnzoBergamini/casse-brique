#include "../include/RenderHandler.hpp"

RenderHandler::RenderHandler(char const *title, int const width, int const height)
    : m_window(nullptr, SDL_DestroyWindow), m_renderer(nullptr, SDL_DestroyRenderer), m_size(std::pair<int, int>(width, height)), 
    m_brickTexture(nullptr), m_sliderTexture(nullptr), m_ballTexture(nullptr)
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

    std::cout << "SDL_CreateRenderer Success" << std::endl;

    m_ballTexture = loadTexture("assets/ball_16x16.bmp");
    m_brickTexture = loadTexture("assets/brick_256x256.bmp");
    m_sliderTexture = loadTexture("assets/slider_256x256.bmp");

}

RenderHandler::~RenderHandler()
{
    SDL_DestroyRenderer(m_renderer.get());
    SDL_DestroyWindow(m_window.get());
    SDL_Quit();
}

SDL_Texture* RenderHandler::loadTexture(char const *path)
{
    SDL_Texture* texture = nullptr;
    SDL_Surface* surface = nullptr;
    surface = SDL_LoadBMP(path);
    if (!surface) {
        printf("Erreur lors du chargement de l'image : %s\n", SDL_GetError());
        return nullptr;
    }

    texture = SDL_CreateTextureFromSurface(m_renderer.get(), surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
        return nullptr;
    }

    return texture;
}

void RenderHandler::renderGame(Game const &g)
{
    SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 0, 255);
    SDL_RenderClear(m_renderer.get());

    for( auto const &brick : g.getBricks() )
    {
        brick.draw(m_renderer.get());
    }

    g.getSlider().draw(m_renderer.get());

    for( auto const &ball : g.getBalls() )
    {
        renderBall(ball);
    }    

    SDL_RenderPresent(m_renderer.get());
    
}

void RenderHandler::renderMainTitle()
{
    std::cout << "Rendering main title" << std::endl;

    SDL_Texture* texture = loadTexture("assets/menu_main_title.bmp");
    SDL_RenderClear(m_renderer.get());

    SDL_RenderCopy(m_renderer.get(), texture, NULL, NULL);

    SDL_RenderPresent(m_renderer.get());
}

void RenderHandler::renderGameOver(int const score)
{
    std::cout << "Rendering Game Over" << std::endl;

    SDL_Texture* texture = loadTexture("assets/menu_game_over.bmp");
    SDL_RenderClear(m_renderer.get());

    SDL_RenderCopy(m_renderer.get(), texture, NULL, NULL);

    SDL_RenderPresent(m_renderer.get());
}

void RenderHandler::renderPause()
{
    std::cout << "Rendering PAUSE" << std::endl;

    SDL_Texture* texture = loadTexture("assets/menu_pause.bmp");
    SDL_RenderClear(m_renderer.get());

    SDL_RenderCopy(m_renderer.get(), texture, NULL, NULL);

    SDL_RenderPresent(m_renderer.get());
}

void RenderHandler::renderPauseAndSaved()
{
    std::cout << "Rendering PAUSE" << std::endl;

    SDL_Texture* texture = loadTexture("assets/menu_pause_and_saved.bmp");
    SDL_RenderClear(m_renderer.get());

    SDL_RenderCopy(m_renderer.get(), texture, NULL, NULL);

    SDL_RenderPresent(m_renderer.get());
}

void RenderHandler::renderWin(int const score)
{
    std::cout << "Rendering WIN" << std::endl;

    SDL_Texture* texture = loadTexture("assets/menu_win.bmp");
    SDL_RenderClear(m_renderer.get());

    SDL_RenderCopy(m_renderer.get(), texture, NULL, NULL);

    SDL_RenderPresent(m_renderer.get());
}

void RenderHandler::renderLoaderScreen()
{
    SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 0, 255);
    SDL_RenderClear(m_renderer.get());

    SDL_RenderPresent(m_renderer.get());
}

void RenderHandler::renderBrick(Brick const &brick)
{
    brick.draw(m_renderer.get());
}

void RenderHandler::renderSlider(Slider const &slider)
{
    slider.draw(m_renderer.get());
}

void RenderHandler::renderBall(Ball const &ball)
{
    SDL_Rect rectDest = {ball.getCoordinates().getX(), ball.getCoordinates().getY(), ball.getRadius(), ball.getRadius()};
    SDL_RenderCopy(m_renderer.get(), m_ballTexture, NULL, &rectDest);    

    // SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    // for (int i = 0; i < m_radius; i++) {
    //     for (int j = 0; j < m_radius; j++) {
    //         if (i * i + j * j <= m_radius * m_radius) {
    //             SDL_RenderDrawPoint(renderer, m_coordinates.getX() + i, m_coordinates.getY() + j);
    //             SDL_RenderDrawPoint(renderer, m_coordinates.getX() - i, m_coordinates.getY() + j);
    //             SDL_RenderDrawPoint(renderer, m_coordinates.getX() + i, m_coordinates.getY() - j);
    //             SDL_RenderDrawPoint(renderer, m_coordinates.getX() - i, m_coordinates.getY() - j);
    //         }
    //     }
    // }

    // Chargement de l'image BMP de la boule

}

std::pair<int, int> RenderHandler::getSize() const
{
    return m_size;
}