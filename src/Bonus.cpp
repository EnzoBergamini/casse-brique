#include "../include/Bonus.hpp"
#include <random>


Bonus::Bonus(Coordinate coordinates, int radius) : Ball(coordinates, radius, 5, 75), m_type(BonusType::NONE) {

    //Choose a random bonus type
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 2);
    int random = dis(gen);
    switch (random) {
        case 0:
            m_type = BonusType::BULLET;
            break;
        case 1:
            m_type = BonusType::MULTI;
            break;
        case 2:
            m_type = BonusType::INCREASE_SLIDER;
            break;
    }

    std::cout << "Bonus TYPE" << static_cast<int>(m_type) << std::endl;
}
