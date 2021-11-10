cmake_minimum_required(VERSION 3.14)

project(gnome-mouse-magnifier VERSION 0.1.0)

add_executable(magnifier src/main.c)
target_link_libraries(magnifier X11)