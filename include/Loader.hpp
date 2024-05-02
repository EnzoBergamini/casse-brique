#pragma once
#include "Brick.hpp"

#include <iostream>
#include <vector>
#include <fstream>

class Loader {
public:
    static void load(char const *filename, std::vector<Brick> &bricks);
};