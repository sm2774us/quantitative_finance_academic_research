cmake_minimum_required(VERSION 3.20)
project(FamaFrenchCpp23)

# Set the C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the Eigen3 package
find_package(eigen3_cmake_module REQUIRED)
find_package(Eigen3 REQUIRED NO_MODULE)
if (EIGEN3_FOUND)
	message("Found Eigen version ${EIGEN3_VERSION_STRING} at: ${EIGEN3_INCLUDE_DIRS}")
    include_directories(${EIGEN3_INCLUDE_DIR})
endif()

# Add the executable and the source files
add_executable(fama_french src/main.cpp src/fama_french.cpp)

# Link Eigen3 to the target executable
target_link_libraries(fama_french Eigen3::Eigen)

# Ensure Eigen3 include directories are properly set
target_include_directories(fama_french PRIVATE ${EIGEN3_INCLUDE_DIR})
