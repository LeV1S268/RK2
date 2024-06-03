# Задает минимально требуемую версию CMake - 3.10.
cmake_minimum_required(VERSION 3.10)

# Устанавливает имя проекта "ChatRoom".
project(ChatRoom)

# Устанавливает стандарт C++ на C++17.
set(CMAKE_CXX_STANDARD 17)

# Создает статическую библиотеку с именем `chat_room_lib` из исходного файла `chat_room.cpp`.
add_library(chat_room_lib STATIC chat_room.cpp)

# Включает модуль FetchContent для загрузки и использования внешних компонентов.
include(FetchContent)

# Объявляет библиотеку Google Test как внешний источник и указывает URL-адрес для загрузки.
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

# Гарантирует использование тех же настроек компилятора и компоновщика для Google Test на Windows.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Загружает и делает библиотеку Google Test доступной для использования в проекте.
FetchContent_MakeAvailable(googletest)

# Создает исполняемый файл с именем `tests` из исходного файла `test.cpp`.
add_executable(tests test.cpp)

# Связывает исполняемый файл `tests` с библиотеками Google Test и статической библиотекой `chat_room_lib`.
target_link_libraries(tests gtest gtest_main chat_room_lib)

# Включает тестирование в проекте CMake.
enable_testing()

# Добавляет тест с именем `AllTests`, который будет запускать исполняемый файл `tests`.
add_test(NAME AllTests COMMAND tests)
