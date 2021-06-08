cmake_minimum_required(VERSION 3.8)

project("CPP")

if(NOT EXISTS ${CMAKE_SOURCE_DIR}/tensorflow)
    make_directory(${CMAKE_SOURCE_DIR}/tensorflow)
    make_directory(${CMAKE_SOURCE_DIR}/tensorflow/include)
    make_directory(${CMAKE_SOURCE_DIR}/tensorflow/lib)
endif()

if(NOT EXISTS ${CMAKE_SOURCE_DIR}/build)
    make_directory(${CMAKE_SOURCE_DIR}/build)
endif()

include_directories(tensorflow/include)
find_library(TENSORFLOW_LIBRARY tensorflow HINTS tensorflow/lib)

add_executable(CPP src/main.cpp)
# target_link_libraries(CPP tensorflow)
target_link_libraries(CPP PUBLIC ${TENSORFLOW_LIBRARY})

configure_file(tensorflow/lib/tensorflow.dll ${CMAKE_CURRENT_BINARY_DIR}/tensorflow.dll COPYONLY)