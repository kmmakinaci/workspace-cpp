cmake_minimum_required(VERSION 3.22)

# Root project name
project(workspace-cpp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories for modularity
add_subdirectory(basics)
add_subdirectory(cpp_template_workspace)
add_subdirectory(featured)
