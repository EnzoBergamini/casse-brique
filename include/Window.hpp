#pragma once
#include "Brick.hpp"
#include "Slider.hpp"
#include "Ball.hpp"
#include "RenderHandler.hpp"

#include <SDL.h>
#include <iostream>
#include <memory>


class Window {
public:
    Window();
    ~Window();

    void mainLoop();

    std::pair<int, int> getSize() const;

private:
    std::un
    std::unique_ptr<RenderHandler> m_renderHandler;

};