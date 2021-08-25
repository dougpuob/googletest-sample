cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
 
get_filename_component(ProjectName ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectName ${ProjectName})
 
add_executable(
    ${ProjectName}
    usb_spec.h
    usb_vendors.h
    usb_device.h
    usb_device.cpp    
    usb_device_logitech_k840.h
    usb_device_logitech_k840.cpp    
    test_usb_device.h
    test_usb_device.cpp    
    test_usb_device_logitech_k840.cpp
    main.cpp)
 
target_include_directories(
    ${ProjectName} PUBLIC
    ${CMAKE_SOURCE_DIR}/submodule/googletest/googletest/include)
 
target_link_libraries(
    ${ProjectName} PUBLIC
    gtest)