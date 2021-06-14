cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)

project("CPP")

if(NOT EXISTS ${CMAKE_SOURCE_DIR}/tensorflow)
    make_directory(${CMAKE_SOURCE_DIR}/tensorflow)
    make_directory(${CMAKE_SOURCE_DIR}/tensorflow/include)
    make_directory(${CMAKE_SOURCE_DIR}/tensorflow/lib)
endif()

if(NOT EXISTS ${CMAKE_SOURCE_DIR}/matplotlibcpp.h)
    file(
    DOWNLOAD
    https://raw.githubusercontent.com/metalglove/matplotlib-cpp/master/matplotlibcpp.h ${CMAKE_SOURCE_DIR}/matplotlibcpp.h
    STATUS
        status
    LOG
        log
    )
    list(GET status 0 status_code)
    list(GET status 1 status_string)
    if(NOT status_code EQUAL 0)
        message(FATAL_ERROR "error downloading matplotlibcpp.h: ${status_string}" "${log}")
    endif()
endif()

include_directories(tensorflow/include)
find_library(TENSORFLOW_LIBRARY tensorflow_cc HINTS tensorflow/lib)

include_directories(tensorflow/git/tensorflow/bazel-tensorflow/external/com_google_protobuf/src)

# TODO: use vcpkg properly: https://vcpkg.io/en/getting-started.html
#include_directories(${Protobuf_INCLUDE_DIRS})
#find_package(Protobuf REQUIRED)

find_package(Python3 COMPONENTS NumPy Development)

add_executable(CPP src/main.cpp)

target_link_libraries(CPP PUBLIC ${TENSORFLOW_LIBRARY} ${Protobuf_LIBRARIES} Python3::Python Python3::NumPy)
configure_file(tensorflow/lib/tensorflow_cc.dll ${CMAKE_CURRENT_BINARY_DIR}/tensorflow_cc.dll COPYONLY)