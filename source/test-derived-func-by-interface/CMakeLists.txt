cmake_minimum_required(VERSION 3.10)
 
get_filename_component(ProjectName ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectName ${ProjectName})
 
add_executable(
    ${ProjectName}
    binary_search.h
    binary_search_loop.h
    binary_search_recursive.h
    main.cpp)
 
target_include_directories(
    ${ProjectName} PUBLIC
    ${CMAKE_SOURCE_DIR}/submodule/googletest/googletest/include)
 
target_link_libraries(
    ${ProjectName} PUBLIC
    gtest)