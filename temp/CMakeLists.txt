cmake_minimum_required(VERSION 3.14)
project(my_project)

# Use C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Google Test
find_package(GTest REQUIRED)

# Include the project's include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# List all source files
set(SOURCES
    main.cpp
    tests/custom_test.cpp
)

# Add the executable
add_executable(app ${SOURCES})

# Link Google Test libraries
target_link_libraries(app PRIVATE GTest::GTest GTest::Main)

# Enable testing
enable_testing()
