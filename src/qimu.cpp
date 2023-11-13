#include "qimu.h"

#include "VGA_Controller.h"
#include "Keyboard_Controller.h"

QIMU::QIMU(std::vector<std::string> args)
{
    ;
}

QIMU::~QIMU()
{
    ;
}

int QIMU::run()
{
    auto vga_ctrl = VGA_Controller::get();

    auto kbd_ctrl = Keyboard_Controller::get();

    while (!kbd_ctrl->quit())
    {
        ;
    }

    return 0;
}