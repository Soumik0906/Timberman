cmake_minimum_required(VERSION 3.30)
project(Timberman)

set(CMAKE_CXX_STANDARD 23)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Timberman main.cpp)

target_link_libraries(Timberman sfml-graphics sfml-audio)