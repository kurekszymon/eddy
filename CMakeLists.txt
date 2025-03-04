cmake_minimum_required(VERSION 3.15)
project(eddy.sh VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Load dependencies with CMakeDeps generator
find_package(ftxui REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(Boost REQUIRED)

# Add subdirectory for source files
add_subdirectory(src)

# Specify where to find header files
include_directories(${YAMLCPP_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${Boost_INCLUDE_DIR})

target_link_libraries(eddy.sh ftxui::ftxui yaml-cpp::yaml-cpp boost::boost)

# include(InstallRequiredSystemLibraries)
# set(CPACK_RESOURCE_FILE_LICENSE, "${CMAKE_SOURCE_DIR}/license.txt")
# set(CPACK_PACKAGE_VERSION_MAJOR, "0")
# set(CPACK_PACKAGE_VERSION_MINOR, "1")
# include(CPACK)