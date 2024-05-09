#include "../include/Game.hpp"
#include "../include/Window.hpp"

Game::Game() : score(0) {}

void Game::loadBricks(char const *filename){
    Loader::load(filename, bricks);
}

void Game::run() {
    std::cout << "Running game..." << std::endl;

    Window window = Window("casse brique", 800, 600);

    window.init(score, bricks);

    window.waitQuit();
}