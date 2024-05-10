#pragma once

#include <SDL.h>
#include <utility>

class Object {
public:
    Object(std::pair<int, int> coordinates);
    std::pair<int, int> getCoordinates() const;
    void setCoordinates(std::pair<int, int> coordinates);

    virtual void draw(SDL_Renderer *renderer) const = 0;

protected:
    std::pair<int, int> m_coordinates;
};