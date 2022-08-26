cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_C_COMPILER "/usr/local/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/local/bin/clang++")
project(CODE_C)

set(CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH}
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules
        )
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
include(basic_env)
add_subdirectory(practice)
