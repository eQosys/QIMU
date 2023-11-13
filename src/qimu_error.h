#pragma once

#include <stdexcept>

class QIMU_Error : public std::runtime_error
{
public:
    QIMU_Error(const std::string& msg);

    virtual ~QIMU_Error();

    virtual const char* what() const noexcept override;
};