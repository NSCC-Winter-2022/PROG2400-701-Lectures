cmake_minimum_required(VERSION 3.21)
project(PROG2400_701_Lectures)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(echo echo/main.cpp)
add_executable(commandline commandline/main.cpp)
add_executable(stringstream stringstream/main.cpp)
add_executable(dynamic_arrays dynamic_arrays/main.cpp)
add_executable(craptor dynamic_arrays/craptor.cpp)
add_executable(linkedlist linkedlist/main.cpp linkedlist/linkedlist.cpp linkedlist/linkedlist.h)
add_executable(queues queues/main.cpp)
add_executable(stacks stacks/main.cpp stacks/stack.cpp stacks/grade.cpp)