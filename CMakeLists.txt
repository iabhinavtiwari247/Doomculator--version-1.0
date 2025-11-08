cmake_minimum_required(VERSION 3.15)
project(Doomculator VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
set(SOURCES
    src/date_utils.cpp
    src/doomsday.cpp
    src/main.cpp
)

# Add header files
set(HEADERS
    include/date_utils.h
    include/doomsday.h
)

# Create the main executable
add_executable(doomculator ${SOURCES} ${HEADERS})
target_include_directories(doomculator PRIVATE include)

# Add test executable
enable_testing()
add_executable(doomculator_tests tests/test_cases.cpp)
target_include_directories(doomculator_tests PRIVATE include)

# Find GTest package
find_package(GTest REQUIRED)
target_link_libraries(doomculator_tests GTest::GTest GTest::Main)