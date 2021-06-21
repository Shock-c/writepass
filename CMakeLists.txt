cmake_minimum_required(VERSION 3.19)
project(writepass)

set(LLVM_DIR /home/shock/myfile/ollvm/llvm-project-11.0.0/llvm/cmake-build-debug/lib/cmake/llvm/)
find_package(LLVM REQUIRED CONFIG)

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)

separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
include_directories(${LLVM_INCLUDE_DIRS})
include_directories(ollvm/include)
add_subdirectory(ollvm)