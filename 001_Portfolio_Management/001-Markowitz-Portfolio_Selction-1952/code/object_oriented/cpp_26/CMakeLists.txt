cmake_minimum_required(VERSION 3.30)
project(MarkowitzCpp26)

# Set the C++ standard to C++26
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the Eigen3 package
find_package(eigen3_cmake_module REQUIRED)
find_package(Eigen3 REQUIRED NO_MODULE)
if (EIGEN3_FOUND)
	message("Found Eigen version ${EIGEN3_VERSION_STRING} at: ${EIGEN3_INCLUDE_DIRS}")
    include_directories(${EIGEN3_INCLUDE_DIR})
endif()

FIND_LIBRARY(NLOPT nlopt)
if(NOT NLOPT)
  message(FATAL_ERROR "nlopt library not found")
else()
  message("Found nlopt")
endif()

## Find NLopt, otherwise download it
#FetchContent_Declare(NLopt
#  URL https://github.com/stevengj/nlopt/archive/refs/tags/v2.10.0.tar.gz
#  URL_HASH SHA256=506f83a9e778ad4f204446e99509cb2bdf5539de8beccc260a014bd560237be1
#  EXCLUDE_FROM_ALL
#  FIND_PACKAGE_ARGS
#)

set(PROJ_MODULES
    module/markowitz.ixx)

target_sources(${PROJECT_NAME} PUBLIC FILE_SET CXX_MODULES FILES ${PROJ_MODULES})

# Add the executable and the source files
add_executable(markowitz src/main.cpp src/markowitz.cpp)

# Link Eigen3 to the target executable
target_link_libraries(markowitz ${NLOPT} Eigen3::Eigen)

# Ensure Eigen3 include directories are properly set
target_include_directories(markowitz PRIVATE ${EIGEN3_INCLUDE_DIR})
