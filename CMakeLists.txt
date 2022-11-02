cmake_minimum_required(VERSION 3.22)
project(blackjackv2)

set(CMAKE_CXX_STANDARD 14)

add_executable(blackjackv2 main.cpp cards.cpp cards.h deck.cpp deck.h)
