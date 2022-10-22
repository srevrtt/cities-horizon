cmake_minimum_required(VERSION 3.23)
project(CitiesHorizon VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(SRCS src/main.cc src/window.cc)

add_subdirectory(dependencies/SDL)
add_subdirectory(dependencies/SDL_image)

include_directories(dependencies/SDL/include)
include_directories(dependencies/SDL_image)

add_executable(CitiesHorizon ${SRCS})
target_link_libraries(CitiesHorizon SDL2 SDL2main SDL2_image)
