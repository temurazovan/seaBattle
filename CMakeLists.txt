cmake_minimum_required(VERSION 3.25)
project(seaBattle)

set(CMAKE_CXX_STANDARD 17)


add_executable(seaBattle main.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()
add_executable(test_main test_main.cpp)

target_link_libraries(
        test_main
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_main)
