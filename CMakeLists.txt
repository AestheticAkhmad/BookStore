cmake_minimum_required(VERSION 3.21)
project(BookStore)
set(CMAKE_CXX_STANDARD 20)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_executable(BookStore main.cpp BookStore.cpp BookStore.hpp BookDataCollector.cpp BookDataCollector.hpp Book.cpp Book.hpp)

add_custom_command(TARGET BookStore PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/bookList.txt
        ${CMAKE_CURRENT_BINARY_DIR}/bookList.txt)