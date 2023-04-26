cmake_minimum_required(VERSION 3.5.1)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers_c.cmake)
project(S04-Samurai-Jack)

enable_language(C)


add_subdirectory(StarCraft StarCraft/cmake-build-debug)
add_subdirectory(WarCraft WarCraft/build)
add_subdirectory(CounterStrike CounterStrike/build)

