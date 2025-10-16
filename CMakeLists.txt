cmake_minimum_required(VERSION 3.15)
project(Server CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# مسیر هدرهای خودت و Asio
include_directories(
    ${CMAKE_SOURCE_DIR}/include            # هدرهای خودت
    ${CMAKE_SOURCE_DIR}/lib/asio/include   # هدرهای Asio
)

add_executable(server
    src/main.cpp
    src/Server.cpp
    src/Session.cpp
)

if (UNIX)
    target_link_libraries(server pthread)
endif()
