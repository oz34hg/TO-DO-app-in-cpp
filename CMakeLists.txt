cmake_minimum_required(VERSION 3.10)
project(TODOApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include subdirectories (optional if headers are in same folders as .cpp)
include_directories(restore store utils)

# Add the executable
add_executable(TODO
    main.cpp
    restore/restore.cpp
    store/store.cpp
    utils/utils.cpp
)

