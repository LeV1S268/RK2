cmake_minimum_required(VERSION 3.10)
project(ChatRoomObserverPattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.10.0.tar.gz
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Отключаем обработку предупреждений о неинициализированных переменных как ошибок
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=maybe-uninitialized")

enable_testing()

# Добавляем исполняемые файлы для тестов
add_executable(test1 test1.cpp)
target_link_libraries(test1 gtest_main)

add_executable(test2 test2.cpp)
target_link_libraries(test2 gtest_main)

add_executable(test3 test3.cpp)
target_link_libraries(test3 gtest_main)

include(GoogleTest)
gtest_discover_tests(test1)
gtest_discover_tests(test2)
gtest_discover_tests(test3)
