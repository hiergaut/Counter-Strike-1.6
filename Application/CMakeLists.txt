
cmake_minimum_required(VERSION 3.7)
project(MainApplication LANGUAGES CXX)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)


#find_package(Qt5 COMPONENTS Widgets REQUIRED)
#find_package(SDL2 REQUIRED)

#find_package(OpenGL REQUIRED)
#find_package(glfw3 3.3 REQUIRED)


file(GLOB_RECURSE sources *.cpp)
#file(GLOB_RECURSE forms *.ui)
file(GLOB_RECURSE headers *.h)

#add_library(glad include/glad/glad.h Application/glad.c)
#add_library("glad" "glad/src/glad.c")
#target_include_directories("glad" PRIVATE "glad/include/")

#add_library(GLAD "glad.c")
#add_library(GLAD ${CMAKE_SOURCE_DIR}/)

include_directories(${PROJECT_NAME}
#        ${M_BGFX_INCLUDE_DIR}
#        ${M_BX_INCLUDE_DIR}
#        ${SDL2_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/include/

)

add_executable(${PROJECT_NAME}
    ${sources}
    ${headers}
#    ${forms}
#    ${SDL2_LIBRARIES}
#    ${CMAKE_SOURCE_DIR}/include/
)

#target_include_directories(${PROJECT_NAME} PRIVATE "../glad/include/")
# target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets bgfx)
# target_link_libraries(${PROJECT_NAME} PRIVATE bgfx)
 target_link_libraries(${PROJECT_NAME} glfw bgfx GL)
