cmake_minimum_required(VERSION 3.16)
project(pid VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

add_library(pid src/pid.cpp)
target_include_directories(pid PUBLIC include)
set_target_properties(pid PROPERTIES VERSION ${PROJECT_VERSION})

install(TARGETS pid DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(FILES include/pid.h DESTINATION ${CMAKE_INSTALL_PREFIX})