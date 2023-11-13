cmake_minimum_required(VERSION 3.8)

project ("qimu")

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
    set(CMAKE_BUILD_TYPE_RELEASE)

    set (CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")

add_executable(
    qimu
    "src/main.cpp"
    "src/qimu.cpp"
    "src/qimu_error.cpp"
    "src/Keyboard_Controller.cpp"
    "src/VGA_Controller.cpp"
)

find_package(SDL2 REQUIRED)

include_directories(
    qimu
    "src/"
    ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(qimu ${SDL2_LIBRARIES})

set_property(TARGET qimu PROPERTY CXX_STANDARD 17)