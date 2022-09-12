cmake_minimum_required(VERSION 3.16)
project(matrix2 VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

add_library(matrix src/matrix.cpp)
target_include_directories(matrix PUBLIC include)
set_target_properties(matrix PROPERTIES VERSION ${PROJECT_VERSION})

install(TARGETS matrix DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(FILES include/matrix.h DESTINATION ${CMAKE_INSTALL_PREFIX})

add_subdirectory(test)