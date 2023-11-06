cmake_minimum_required(VERSION 3.14)
project(spaceship-operator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(geometry 
  src/Point.cpp 
  src/Line.cpp
)
include_directories(include)

# Test
add_executable(spaceship-test test/spaceship-test.cpp)
target_link_libraries(spaceship-test PUBLIC
  geometry
  GTest::gtest_main
)
target_include_directories(spaceship-test PUBLIC include)
include(GoogleTest)
gtest_discover_tests(spaceship-test)
