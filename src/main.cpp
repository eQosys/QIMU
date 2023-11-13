#include <SDL.h>
#include <iostream>
#include <memory>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 960

#include "qimu.h"

int main(int argc, char* argv[])
{
    std::vector<std::string> args;
    args.reserve(argc - 1);
    for (int i = 1; i < argc; ++i)
        args.push_back(std::string(argv[i]));
    
    auto qimu = std::make_unique<QIMU>(args);

    return qimu->run();
}