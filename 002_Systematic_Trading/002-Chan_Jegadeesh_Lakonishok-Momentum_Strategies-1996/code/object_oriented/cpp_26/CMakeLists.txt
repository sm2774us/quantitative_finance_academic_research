cmake_minimum_required(VERSION 3.30)
project(MomentumCpp26)

# Set the C++ standard to C++26
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable and the source files
add_executable(momentum src/momentum_calculator.cpp)
