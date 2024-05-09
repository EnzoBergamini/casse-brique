#include "../include/Game.hpp"
#include "../include/Window.hpp"

Game::Game() : m_score(0), m_slider(std::pair<int, int>(25, 5)), m_window(Window("casse brique", 800, 600)) {}

void Game::loadBricks(char const *filename){
    Loader::load(filename, m_bricks);
}

void Game::run() {
    std::cout << "Running game..." << std::endl;
    m_window.init(m_score, m_bricks, m_slider);

    m_window.waitQuit();
}