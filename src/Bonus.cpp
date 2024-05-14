#include "../include/Bonus.hpp"
#include <random>


Bonus::Bonus(Coordinate coordinates, int radius) : Ball(coordinates, radius, Coordinate(0,5)), m_type(BonusType::NONE) {

    //Choose a random bonus type
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 5);
    int random = dis(gen);
    switch (random) {
        case 0:
            m_type = BonusType::BULLET;
            std::cout << "Bonus TYPE BULLET" << std::endl;
            break;
            
        case 1:
            m_type = BonusType::ADD_BALL;
            std::cout << "Bonus TYPE ADD_BALL" << std::endl;
            break;
        case 2:
            m_type = BonusType::INCREASE_SLIDER;
            std::cout << "Bonus TYPE INCREASE_SLIDER" << std::endl;
            break;
        case 3:
            m_type = BonusType::INCREASE_BALLS;
            std::cout << "Bonus TYPE INCREASE_BALL" << std::endl;
            break;
        case 4:
            m_type = BonusType::LIFE;
            std::cout << "Bonus TYPE LIFE" << std::endl;
            break;
        case 5:
            m_type = BonusType::LITTLE_BALLS;
            std::cout << "Bonus TYPE LITTLE_BALLS" << std::endl;
            break;
        default:
            m_type = BonusType::NONE;
            std::cout << "Bonus TYPE NONE" << std::endl;
            break;
    }
}
