cmake_minimum_required(VERSION 3.0.0)
project(BankQueueSystem VERSION 0.1.0)

set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-Wall -Wextra -fexec-charset=GBK")

set(MYSQL_INC ${PROJECT_SOURCE_DIR}/thirdparty/MySQL/include)
set(MYSQL_LIB ${PROJECT_SOURCE_DIR}/thirdparty/MySQL/lib)

# add_custom_command(
#             COMMAND copy ${MYSQL_LIB}/libmysql.dll ${PROJECT_BINARY_DIR})

IF (CMAKE_BUILD_TYPE STREQUAL Debug) 
    ADD_DEFINITIONS(-DDEBUG)
ENDIF()

file(GLOB_RECURSE SRCS "src/*.c")

link_directories(${MYSQL_LIB})
add_executable(BankQueueSystem ${SRCS})
include_directories(${PROJECT_SOURCE_DIR}/include ${MYSQL_INC})
target_link_libraries(BankQueueSystem libmysql.lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
