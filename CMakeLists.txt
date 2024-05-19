cmake_minimum_required(VERSION 3.10)
project(ChatRoomObserverPattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)





# Задаем опцию компилятору Google Test для отключения обработки предупреждений о неинициализированных переменных как ошибок
set(gtest_disable_werror ON CACHE BOOL "" FORCE)

# Загружаем и активируем Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.10.0.tar.gz
)
FetchContent_MakeAvailable(googletest)


# Отключаем обработку предупреждений о неинициализированных переменных как ошибок
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=maybe-uninitialized")


enable_testing()

add_executable(chat_room chat_room.cpp)
add_executable(tests tests.cpp)
target_link_libraries(tests gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
