cmake_minimum_required (VERSION 3.5)

project (Counter-Strike-1.6 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_subdirectory(Modules/bgfx.cmake)
add_subdirectory(Application)
