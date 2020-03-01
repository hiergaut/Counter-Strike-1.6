
cmake_minimum_required(VERSION 3.5)
project(MainApplication LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS Widgets REQUIRED)



file(GLOB_RECURSE sources *.cpp)
file(GLOB_RECURSE forms *.ui)
file(GLOB_RECURSE headers *.h)

include_directories(
        ${M_BGFX_INCLUDE_DIR}
        ${M_BX_INCLUDE_DIR}
)

add_executable(${PROJECT_NAME}
    ${sources}
    ${forms}
    ${headers}
)

 target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets bgfx)
