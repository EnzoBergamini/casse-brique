#pragma once

#include "Ball.hpp"

#include <SDL.h>
#include <utility>

enum class BonusType {
    BULLET,
    MULTI,
    INCREASE_SLIDER,
    NONE
};

class Bonus : public Ball {
public:
    Bonus(Coordinate coordinates, int radius);

    inline BonusType getType() const { return m_type; }

private:
    BonusType m_type;
};