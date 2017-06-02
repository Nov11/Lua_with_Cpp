cmake_minimum_required(VERSION 2.8.7)
project(embedlua)

set(CMAKE_CXX_STANDARD 11)

#set(SOURCE_FILES main.cpp)
set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Werror -Wconversion -Wold-style-cast -Wpointer-arith -Wshadow -Wno-unused-parameter -Wwrite-strings -rdynamic")

#include findlua module
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
# find lua packages first
find_package(Lua REQUIRED)
include_directories(${LUA_INCLUDE_DIRS})
set(LIBS ${LIBS} ${LUA_LIBRARIES})

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(lua-and-cpp)
add_subdirectory(simpleExamples)

#add_executable(main ${SOURCE_FILES})
#target_link_libraries(main net base)

#add_executable(macro macro.cpp)