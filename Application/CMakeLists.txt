
cmake_minimum_required(VERSION 3.7)
project(MainApplication LANGUAGES CXX)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)


#find_package(Qt5 COMPONENTS Widgets REQUIRED)
#find_package(SDL2 REQUIRED)



file(GLOB_RECURSE sources *.cpp)
#file(GLOB_RECURSE forms *.ui)
file(GLOB_RECURSE headers *.h)

include_directories(${PROJECT_NAME}
#        ${M_BGFX_INCLUDE_DIR}
#        ${M_BX_INCLUDE_DIR}
#        ${SDL2_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}
    ${sources}
#    ${forms}
    ${headers}
#    ${SDL2_LIBRARIES}
)

# target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets bgfx)
 target_link_libraries(${PROJECT_NAME} PRIVATE bgfx)
