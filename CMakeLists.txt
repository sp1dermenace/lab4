cmake_minimum_required(VERSION 3.16)
project(lab3_queue LANGUAGES CXX)

# googletest 1.18 требует C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(gtest)    
add_subdirectory(queue)    
add_subdirectory(tests)    