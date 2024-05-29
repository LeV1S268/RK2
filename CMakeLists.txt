cmake_minimum_required(VERSION 3.10)
project(ChatRoomObserverPattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz
)
# Для Windows: Предотвращаем переопределение параметров компилятора/линкера родительского проекта
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Основной исполняемый файл
add_executable(chat_room main.cpp)
target_link_libraries(chat_room pthread)

# Тесты
add_executable(test1 test1.cpp)
target_link_libraries(test1 gtest pthread)

add_executable(test2 test2.cpp)
target_link_libraries(test2 gtest pthread)

add_executable(test3 test3.cpp)
target_link_libraries(test3 gtest pthread)

include(GoogleTest)
gtest_discover_tests(test1)
gtest_discover_tests(test2)
gtest_discover_tests(test3)
