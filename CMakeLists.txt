cmake_minimum_required(VERSION 3.24)
project(BlackJack_Group_1_CSC_175)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(BlackJack_Group_1_CSC_175
        blackjack.cpp deck.cpp)
