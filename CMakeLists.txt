cmake_minimum_required(VERSION 3.10)
project(ChatRoomObserver)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление исходных файлов
add_executable(ChatRoomObserver chat_room.cpp)
