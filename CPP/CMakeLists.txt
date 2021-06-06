cmake_minimum_required(VERSION 3.8)

project("CPP")

if(NOT EXISTS ${CMAKE_SOURCE_DIR}/tensorflow)
    make_directory(${CMAKE_SOURCE_DIR}/tensorflow)
endif()

if(NOT EXISTS ${CMAKE_SOURCE_DIR}/build)
    make_directory(${CMAKE_SOURCE_DIR}/build)
endif()

if(UNIX AND NOT APPLE)
    if(NOT EXISTS ${CMAKE_SOURCE_DIR}/tensorflow/lib/libtensorflow.so)
        file(
        DOWNLOAD
            https://storage.googleapis.com/tensorflow/libtensorflow/libtensorflow-gpu-linux-x86_64-2.5.0.tar.gz ${CMAKE_SOURCE_DIR}/tensorflow/linux.tar.gz
        STATUS
            status
        LOG
            log
        )
        list(GET status 0 status_code)
        list(GET status 1 status_string)
        if(NOT status_code EQUAL 0)
            message(FATAL_ERROR "error downloading tensorflow lib: ${status_string}" "${log}")
        endif()

        execute_process(COMMAND ${CMAKE_COMMAND} -E tar xvzf ${CMAKE_SOURCE_DIR}/tensorflow/linux.tar.gz WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/tensorflow)
        file(REMOVE ${CMAKE_SOURCE_DIR}/tensorflow/linux.tar.gz)
    endif()
elseif(WIN32)
    if(NOT EXISTS ${CMAKE_SOURCE_DIR}/tensorflow/lib/tensorflow.dll)
        file(
        DOWNLOAD
        https://storage.googleapis.com/tensorflow/libtensorflow/libtensorflow-gpu-windows-x86_64-2.5.0.zip ${CMAKE_SOURCE_DIR}/tensorflow/windows.zip
        STATUS
            status
        LOG
            log
        )
        list(GET status 0 status_code)
        list(GET status 1 status_string)
        if(NOT status_code EQUAL 0)
            message(FATAL_ERROR "error downloading tensorflow lib: ${status_string}" "${log}")
        endif()

        execute_process(COMMAND ${CMAKE_COMMAND} -E tar xvzf ${CMAKE_SOURCE_DIR}/tensorflow/windows.zip WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/tensorflow)
        file(REMOVE ${CMAKE_SOURCE_DIR}/tensorflow/windows.zip)
    endif()
    configure_file(tensorflow/lib/tensorflow.dll ${CMAKE_CURRENT_BINARY_DIR}/tensorflow.dll COPYONLY)
    configure_file(tensorflow/lib/tensorflow.dll ${CMAKE_CURRENT_BINARY_DIR}/test/tensorflow.dll COPYONLY)
endif()

include_directories(tensorflow/include)
link_directories(tensorflow/lib)

add_executable (CPP src/CPP.cpp src/CPP.h)
target_link_libraries(CPP tensorflow)