cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 11)

project("CPP")

if(NOT EXISTS ${CMAKE_SOURCE_DIR}/tensorflow)
    make_directory(${CMAKE_SOURCE_DIR}/tensorflow)
    make_directory(${CMAKE_SOURCE_DIR}/tensorflow/include)
    make_directory(${CMAKE_SOURCE_DIR}/tensorflow/lib)
endif()

include_directories(tensorflow/include)
find_library(TENSORFLOW_LIBRARY tensorflow_cc tensorflow HINTS tensorflow/lib)

include_directories(tensorflow/git/tensorflow/bazel-tensorflow/external/com_google_protobuf/src)

# TODO: use vcpkg properly: https://vcpkg.io/en/getting-started.html
#include_directories(${Protobuf_INCLUDE_DIRS})
#find_package(Protobuf REQUIRED)

add_executable(CPP src/main.cpp)
target_link_libraries(CPP PUBLIC ${TENSORFLOW_LIBRARY} ${Protobuf_LIBRARIES})
configure_file(tensorflow/lib/tensorflow_cc.dll ${CMAKE_CURRENT_BINARY_DIR}/tensorflow_cc.dll COPYONLY)
configure_file(tensorflow/lib/tensorflow.dll ${CMAKE_CURRENT_BINARY_DIR}/tensorflow.dll COPYONLY)