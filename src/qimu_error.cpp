#include "qimu_error.h"

QIMU_Error::QIMU_Error(const std::string& msg)
    : std::runtime_error(msg)
{
    ;
}

QIMU_Error::~QIMU_Error()
{
    ;
}

const char* QIMU_Error::what() const noexcept
{
    return std::runtime_error::what();
}