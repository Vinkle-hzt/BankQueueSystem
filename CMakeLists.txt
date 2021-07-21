cmake_minimum_required(VERSION 3.0.0)
project(BankQueueSystem VERSION 0.1.0)

file(GLOB_RECURSE SRCS "src/*.c")

add_executable(BankQueueSystem ${SRCS})
include_directories(${PROJECT_SOURCE_DIR}/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
