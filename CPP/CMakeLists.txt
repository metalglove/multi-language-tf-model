cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 11)

project("CPP")

if(NOT EXISTS ${CMAKE_SOURCE_DIR}/tensorflow)
    make_directory(${CMAKE_SOURCE_DIR}/tensorflow)
    make_directory(${CMAKE_SOURCE_DIR}/tensorflow/include)
    make_directory(${CMAKE_SOURCE_DIR}/tensorflow/lib)
endif()

include_directories(tensorflow/include)
find_library(TENSORFLOW_LIBRARY tensorflow HINTS tensorflow/lib)

add_executable(CPP src/main.cpp)
target_link_libraries(CPP PUBLIC ${TENSORFLOW_LIBRARY})

configure_file(tensorflow/lib/tensorflow.dll ${CMAKE_CURRENT_BINARY_DIR}/tensorflow.dll COPYONLY)