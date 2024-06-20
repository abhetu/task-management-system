cmake_minimum_required(VERSION 3.10)
project(TaskManagementSystem)

# Add executable
add_executable(TaskManagementSystem main.cpp Task.cpp User.cpp TaskManager.cpp UserManager.cpp Database.cpp Utils.cpp)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
