cmake_minimum_required(VERSION 3.29)
project(Lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab3 Currency.h DrachmaCurrency.h main.cpp
        LinkNode.h
        SinglyLinkedList.h "Stack.h" "Queue.h")
