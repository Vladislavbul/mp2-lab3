cmake_minimum_required(VERSION 3.16)

project(RPN)

include(cmake/function.cmake)

add_subdirectory(library)
add_subdirectory(main)

option(BTEST "build test?" OFF)

if(BTEST)
    add_subdirectory(gtest)
    add_subdirectory(test)

endif()
