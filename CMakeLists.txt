cmake_minimum_required(VERSION 3.10)
project(ChatRoom)

set(CMAKE_CXX_STANDARD 17)

# Add Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add test files
add_executable(chat_room_tests tests.cpp)

# Link Google Test libraries
target_link_libraries(chat_room_tests gtest gtest_main)

# Enable testing
enable_testing()
add_test(NAME ChatRoomTest COMMAND chat_room_tests)
