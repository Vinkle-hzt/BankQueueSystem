cmake_minimum_required(VERSION 3.0.0)
project(BankQueueSystem VERSION 0.1.0)

set (CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 11)

set(COMPILE_FLAGS -Wall -Wextra)

IF (CMAKE_BUILD_TYPE STREQUAL Debug) 
    ADD_DEFINITIONS(-DDEBUG)
ENDIF()

file(GLOB_RECURSE SRCS "src/*.c")

add_executable(BankQueueSystem ${SRCS})
include_directories(${PROJECT_SOURCE_DIR}/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
