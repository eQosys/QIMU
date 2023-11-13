#pragma once

#include <vector>
#include <string>

class QIMU
{
public:
    QIMU() = delete;
    QIMU(std::vector<std::string> args);
    ~QIMU();

public:
    int run();
};