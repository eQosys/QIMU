#include "Keyboard_Controller.h"

#include <SDL.h>

#include "qimu_error.h"

Keyboard_Controller::Keyboard_Controller()
{
    if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
    {
        throw QIMU_Error("Could not initialize SDL events subsystem!");
    }

    m_thread = std::thread([this]()
    {
        SDL_Event e;
        while (!m_quit)
        {
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT)
                {
                    m_quit = true;
                }
            }
        }
    });
}

Keyboard_Controller::~Keyboard_Controller()
{
    SDL_QuitSubSystem(SDL_INIT_EVENTS);

    m_thread.join();
}

std::shared_ptr<Keyboard_Controller> Keyboard_Controller::get()
{
    static std::shared_ptr<Keyboard_Controller> singleton(new Keyboard_Controller());

    return singleton;
}