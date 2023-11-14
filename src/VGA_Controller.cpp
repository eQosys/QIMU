#include "VGA_Controller.h"

#include <SDL.h>

#include "qimu_error.h"

constexpr int SCREEN_WIDTH = 1280;
constexpr int SCREEN_HEIGHT = 960;

VGA_Controller::VGA_Controller()
{
    if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
    {
        throw QIMU_Error("Could not initialize SDL video subsystem!");
    }

    m_window = SDL_CreateWindow("QIMU", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (m_window == nullptr)
    {
        throw QIMU_Error("Could not create SDL window!");
    }

    m_screenSurface = SDL_GetWindowSurface(m_window);

    SDL_FillRect(m_screenSurface, nullptr, SDL_MapRGB(m_screenSurface->format, 0x00, 0x00, 0x00));

    SDL_UpdateWindowSurface(m_window);
}

VGA_Controller::~VGA_Controller()
{
    SDL_DestroyWindow(m_window);

    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

std::shared_ptr<VGA_Controller> VGA_Controller::get()
{
    static std::shared_ptr<VGA_Controller> singleton(new VGA_Controller());

    return singleton;
}