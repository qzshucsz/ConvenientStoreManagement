cmake_minimum_required(VERSION 3.9)
project(FamilyMart)

set(CMAKE_CXX_STANDARD 11)

add_executable(FamilyMart main.cpp Item.cpp Item.h Warehouse.cpp Warehouse.h Shop.cpp Shop.h FamilyMart.cpp FamilyMart.h StringProcessor.cpp StringProcessor.h)