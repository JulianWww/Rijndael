cmake_minimum_required(VERSION 3.0.0)
project(Rijndael VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

FILE(GLOB_RECURSE source src/*)

add_executable(Rijndael main.cpp ${source})
target_include_directories(Rijndael PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
