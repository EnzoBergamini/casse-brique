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

    // Chargement des textures
    m_ballTexture = loadTexture("assets/ball_16x16.bmp");
    m_brickTexture = loadTexture("assets/brick_256x256.bmp");
    m_sliderTexture = loadTexture("assets/slider_256x256.bmp");
    m_bulletTexture = loadTexture("assets/bullet_16x16.bmp");

    m_bonus_add_ballTexture = loadTexture("assets/bonus_add_ball16x16.bmp");
    m_bonus_bulletTexture = loadTexture("assets/bonus_bullet16x16.bmp");
    m_bonus_increase_sliderTexture = loadTexture("assets/bonus_increase_slider16x16.bmp");
    m_bonus_increase_ballsTexture = loadTexture("assets/bonus_increase_balls16x16.bmp");
    m_bonus_lifeTexture = loadTexture("assets/bonus_life16x16.bmp");
    m_bonus_little_ballsTexture = loadTexture("assets/bonus_little_balls16x16.bmp");

    std::cout << "Textures loaded" << std::endl;


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
        renderBrick(brick);
    }

    renderSlider(g.getSlider());

    for( auto const &ball : g.getBalls() )
    {
        renderBall(ball);
    }    

    for( auto const &bonus : g.getBonuses() )
    {
        renderBonus(bonus);
    }

    for( auto const &bullet : g.getBullets() )
    {
        renderBullet(bullet);
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
    SDL_Rect rect = {
        brick.getCoordinates().getX(),
        brick.getCoordinates().getY(),
        brick.getWidth(), 
        brick.getHeight()   
    };
    SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 255, 255);
    SDL_RenderFillRect(m_renderer.get(), &rect);
}

void RenderHandler::renderSlider(Slider const &slider)
{
    SDL_Rect rect = {
        slider.getCoordinates().getX(),
        slider.getCoordinates().getY(),
        slider.getWidth(), 
        slider.getHeight()
    };

    SDL_SetRenderDrawColor(m_renderer.get(), 255, 0, 0, 255);
    SDL_RenderFillRect(m_renderer.get(), &rect);
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

void RenderHandler::renderBullet(Ball const &bullet)
{
    SDL_Rect rectDest = {bullet.getCoordinates().getX(), bullet.getCoordinates().getY(), bullet.getRadius(), bullet.getRadius()};
    SDL_RenderCopy(m_renderer.get(), m_bulletTexture, NULL, &rectDest);
}

void RenderHandler::renderBonus(Bonus const &bonus)
{
    SDL_Rect rectDest = {bonus.getCoordinates().getX(), bonus.getCoordinates().getY(), bonus.getRadius(), bonus.getRadius()};
    switch (bonus.getType())
    {
    case BonusType::NONE:
        break;
    
    case BonusType::ADD_BALL:
        SDL_RenderCopy(m_renderer.get(), m_bonus_add_ballTexture, NULL, &rectDest);
        break;
    
    case BonusType::BULLET:
        SDL_RenderCopy(m_renderer.get(), m_bonus_bulletTexture, NULL, &rectDest);
        break;

    case BonusType::INCREASE_SLIDER:
        SDL_RenderCopy(m_renderer.get(), m_bonus_increase_sliderTexture, NULL, &rectDest);
        break;
    
    case BonusType::INCREASE_BALLS:
        SDL_RenderCopy(m_renderer.get(), m_bonus_increase_ballsTexture, NULL, &rectDest);
        break;
    
    case BonusType::LIFE:
        SDL_RenderCopy(m_renderer.get(), m_bonus_lifeTexture, NULL, &rectDest);
        break;

    case BonusType::LITTLE_BALLS:
        SDL_RenderCopy(m_renderer.get(), m_bonus_little_ballsTexture, NULL, &rectDest);
        break;
    default:
        break;
    }
}