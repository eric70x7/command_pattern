cmake_minimum_required(VERSION 3.0.0)
project(command VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()

add_library(command
            command.cpp
            nullCommand.cpp)

add_library(concreteCommands
            simpleCommandA.cpp
            simpleCommandB.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(GTest REQUIRED)

add_executable(test_command test_command.cpp)

# Tester includes
target_include_directories(
    test_command
    PUBLIC ${GTEST_INCLUDE_DIRS}
)

# Tester libraries
target_link_libraries(
    test_command
    command
    concreteCommands
    ${GTEST_LIBRARIES}
)

add_test(NAME test_command
         COMMAND test_command)
