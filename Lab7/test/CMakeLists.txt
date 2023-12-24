include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# GTest library called gtest_main

add_executable(test test.cpp)

cmake_minimum_required(VERSION 3.22.1)

target_link_libraries(
  test
  GTest::gtest_main
  src_lib
)