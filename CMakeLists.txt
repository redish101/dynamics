cmake_minimum_required(VERSION 4.2)

set(CMAKE_CXX_STANDARD 17)

project(dynamics)

# 统一输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)   # 可执行文件 / .app bundle
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/libs)   # 动态库 (.dylib / .so)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/libs)   # 静态库 (.a / .lib)

add_subdirectory(thirdparty)
add_subdirectory(src)