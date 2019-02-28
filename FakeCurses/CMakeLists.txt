cmake_minimum_required(VERSION 3.13)
project(FakeCurses LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)

add_library(FakeCurses STATIC
        FakeCurses.cpp FakeCurses.h
        FakeCursesWindow.cpp FakeCursesWindow.h
        FakeCursesCell.cpp FakeCursesCell.h
        ncurses.h)

target_include_directories(FakeCurses PUBLIC .)
target_link_libraries(FakeCurses PUBLIC CursesWrapper)
target_compile_definitions(CursesWrapper PRIVATE USE_REAL_CURSES)
