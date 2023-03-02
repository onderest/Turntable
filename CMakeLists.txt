#minimum req version
cmake_minimum_required(VERSION 3.12)

#include build functon from pico sdk
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# namnet på prjektet (PROJEKT NAME) och c/c++ standard
project(turntable C CXX ASM)
#set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

#skapa pico-sdk subdirektory för biblotek
pico_sdk_init()

# sourcefiles location
add_executable(${PROJECT_NAME}
    #definitions.h 
    #header.h   
    main.c
    pwm.c
    #pwm.h
    setup.c
)

# create map/bin/hex/uf2 files
pico_add_extra_outputs(${PROJECT_NAME})

# link to pico_Sstdlib(gpio.,, time, etc)
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    pico_time
    hardware_irq
    hardware_pwm
    hardware_timer
)

# Enable usb output, disable uart output
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)