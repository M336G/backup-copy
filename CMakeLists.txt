set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_minimum_required(VERSION 3.10.0)
project(backup-copy VERSION 1.0.0 LANGUAGES C CXX)

add_executable(backup-copy src/main.cpp)

set_target_properties(backup-copy PROPERTIES WIN32_EXECUTABLE TRUE)