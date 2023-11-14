#include <SDL.h>
#include <iostream>
#include <memory>

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