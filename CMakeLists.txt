cmake_minimum_required(VERSION 3.14)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
set(PICO_BOARD adafruit_feather_rp2040)

# check for valid pico-sdk installation
if(DEFINED PICO_SDK_PATH)
    if(NOT EXISTS ${CMAKE_SOURCE_DIR}/pico_sdk_import.cmake)
        message("Copying ${PICO_SDK_PATH}/external/pico_sdk_import.cmake to ${CMAKE_SOURCE_DIR}")
        file(COPY ${PICO_SDK_PATH}/external/pico_sdk_import.cmake
            DESTINATION ${CMAKE_SOURCE_DIR})
    endif()
    include(pico_sdk_import.cmake)
else()
    if(EXISTS ${CMAKE_SOURCE_DIR}/lib/pico-sdk/pico_sdk_init.cmake)
        include(lib/pico-sdk/pico_sdk_init.cmake)
    else()
        message(FATAL_ERROR "Path to pico-sdk source not found. Either provide the path to CMake with\n"
        "   -DPICO_SDK_PATH=/path/to/dir\n"
        "or run\n"
        "   git submodule update --init\n"
        "   git -C lib/pico-sdk submodule update --init")
    endif()
endif()

project(motor LANGUAGES C CXX ASM)

pico_sdk_init()

add_executable(${CMAKE_PROJECT_NAME}
    src/main.c
    src/stepper.c
    )

pico_enable_stdio_usb(${CMAKE_PROJECT_NAME} 1)
pico_enable_stdio_uart(${CMAKE_PROJECT_NAME} 0)

target_link_libraries(${CMAKE_PROJECT_NAME}
    pico_stdlib
    )
