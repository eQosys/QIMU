#pragma once

#include <memory>
#include <thread>
#include <atomic>

class Keyboard_Controller
{
private:
    Keyboard_Controller();

public:
    ~Keyboard_Controller();

public:
    bool quit() const { return m_quit; }

public:
    static std::shared_ptr<Keyboard_Controller> get();

private:
    std::thread m_thread;
    std::atomic_bool m_quit = false;
};