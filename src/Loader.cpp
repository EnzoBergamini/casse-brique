#include "../include/Loader.hpp"

void Loader::load(char const *filename, std::vector<Brick> &bricks) {
    std::cout << "Loading map... throught the file : " << filename << std::endl;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        exit(1);
    }

    int line = 0;
    int column = 0;

    char character;
    while (file.get(character)) {
        if (character == 'o') {
            column++;
        } else if (character >= '0' && character <= '9') {
            bricks.push_back(Brick(int(character - '0'), Coordinate(line*20, column*40), 40, 20));
            column++;
        } else if (character == '\n') {
            line++;
            column = 0;
        } else {
            std::cerr << "Invalid character in file : " << character << std::endl;
        }
    }

    file.close();
}