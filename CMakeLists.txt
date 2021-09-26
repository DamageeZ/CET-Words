cmake_minimum_required(VERSION 3.19)
project(CET)

set(CMAKE_CXX_STANDARD 14)

add_executable(CET main.cpp DAO.cpp DAO.h User.cpp User.h Word.cpp Word.h Recitation.cpp Recitation.h )