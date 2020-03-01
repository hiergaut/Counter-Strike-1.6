cmake_minimum_required (VERSION 3.5)

project (Counter-Strike-1.6 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -Wall -pedantic -Wextra -O0 -g -Wfatal-errors")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -Wall -DNDEBUG")



set (M_BGFX_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/Modules/bgfx.cmake/bgfx/include/)
set (M_BX_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/Modules/bgfx.cmake/bx/include/)


add_subdirectory(Modules/bgfx.cmake)
add_subdirectory(Application)
