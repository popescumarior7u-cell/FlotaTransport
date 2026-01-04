cmake_minimum_required(VERSION 3.10)
project(ProjectPoo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(Project main.cpp Resources/RS.cpp Flota.cpp Flota.h Vehicul.cpp Vehicul.h Autobuz.h Autobuz.cpp Tren.h Tren.cpp Avion.h Avion.cpp)
