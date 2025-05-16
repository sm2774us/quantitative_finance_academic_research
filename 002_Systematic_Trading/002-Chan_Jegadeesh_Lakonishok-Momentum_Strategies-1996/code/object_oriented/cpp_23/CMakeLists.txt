cmake_minimum_required(VERSION 3.22)
project(MomentumCpp23)

# Set the C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_COMPILER g++-13)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable and the source files
add_executable(momentum src/momentum_calculator.cpp)
