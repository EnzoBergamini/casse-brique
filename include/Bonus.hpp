#pragma once

#include "Ball.hpp"

#include <SDL.h>
#include <utility>

// Bonus are special balls that can be collected by the player
// They can have different effects, GOOD or BAD
enum class BonusType {
    NONE,
    BULLET,
    ADD_BALL,
    INCREASE_SLIDER,
    DEATH,
    LIFE,
    LITTLE_BALLS
};

class Bonus : public Ball {
public:
    Bonus(Coordinate coordinates, int radius);

    inline BonusType getType() const { return m_type; }

private:
    BonusType m_type;
};