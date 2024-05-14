#include "../include/Loader.hpp"

void Loader::load(char const *filename, std::vector<Brick> &bricks, int width, int height) {
    std::cout << "Loading map... throught the file : " << filename << std::endl;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        exit(1);
    }
    int nbLines;
    int nbColumns;
    int typeBlock;

    file >> nbColumns;
    file >> nbLines;
    file >> typeBlock;

    int blockWidth = width / nbColumns;
    int blockHeight = (height / 3) / nbLines;

    int line = 0;
    int column = 0;

    char character;
    // Lit la première ligne où il y a 3 nombres : nb de lignes, nb de colonnes, type de brique
    

    std::cout << "Number of lines : " << line << std::endl;
    std::cout << "Number of columns : " << column << std::endl;
    std::cout << "Type of bricks : " << character << std::endl;

    while (file.get(character)) {
        if (character == 'o') {
            column++;
        } else if (character >= '0' && character <= '9') {
            bricks.push_back(Brick(int(character - '0'), Coordinate(column* blockWidth, line*blockHeight), blockWidth, blockHeight));
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