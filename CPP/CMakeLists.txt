cmake_minimum_required(VERSION 3.8)

project("CPP")

if(NOT EXISTS ${CMAKE_SOURCE_DIR}/tensorflow)
    make_directory(${CMAKE_SOURCE_DIR}/tensorflow)
endif()

if(NOT EXISTS ${CMAKE_SOURCE_DIR}/build)
    make_directory(${CMAKE_SOURCE_DIR}/build)
endif()

include_directories(tensorflow/include)
link_directories(tensorflow/lib)

add_executable (CPP src/main.cpp)
target_link_libraries(CPP tensorflow)

configure_file(tensorflow/lib/tensorflow.dll ${CMAKE_CURRENT_BINARY_DIR}/tensorflow.dll COPYONLY)