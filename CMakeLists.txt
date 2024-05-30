cmake_minimum_required(VERSION 3.10)
project(ChatRoom)

set(CMAKE_CXX_STANDARD 17)

# Add source files
add_library(chat_room_lib STATIC chat_room.cpp)

# Add Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add the single test file
add_executable(tests test.cpp)

# Link Google Test libraries and chat_room_lib
target_link_libraries(tests gtest gtest_main chat_room_lib)

# Enable testing
enable_testing()
add_test(NAME AllTests COMMAND tests)
