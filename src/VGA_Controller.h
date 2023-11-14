#pragma once

#include <memory>

class VGA_Controller
{
private:
    VGA_Controller();

public:
    ~VGA_Controller();

public:
    static std::shared_ptr<VGA_Controller> get();

private:
    struct SDL_Window* m_window = nullptr;
    struct SDL_Surface* m_screenSurface = nullptr;
};