cmake_minimum_required(VERSION 3.16)
project(event_dispatcher)

set(PLATFORM x86_64)
# Set default language settings
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)


add_subdirectory(src)
add_subdirectory(test)

