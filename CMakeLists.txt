cmake_minimum_required(VERSION 3.17)
# Pull in pico sdk
include(pico_sdk_import.cmake)

project(love_box C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall)

pico_sdk_init()

# Add e-paper libs
if (DEFINED ENV{LIB_DIR} AND (NOT LIB_DIR))
    set(LIB_DIR $ENV{LIB_DIR})
else ()
    set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
endif ()
add_subdirectory(${LIB_DIR}/Config)
add_subdirectory(${LIB_DIR}/e-Paper)
add_subdirectory(${LIB_DIR}/Fonts)
add_subdirectory(${LIB_DIR}/GUI)
include_directories(${LIB_DIR}/Config)
include_directories(${LIB_DIR}/GUI)
include_directories(${LIB_DIR}/e-Paper)
include_directories(${LIB_DIR}/Fonts)
message("Using e-Paper libraries from ${LIB_DIR}")

## Generate quotes source file
add_custom_command(
        PRE_BUILD
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/quotes.o
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND ${CMAKE_OBJCOPY} --input binary --output elf32-littlearm quotes.txt quotes.o
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/quotes.txt
)

add_executable(love_box main.cpp quotes.o quote_sampler.cpp quote_sampler.hpp display_manager.cpp display_manager.hpp)

# use pico usb instead of uart
pico_enable_stdio_usb(love_box 1)
pico_enable_stdio_uart(love_box 0)

target_link_libraries(love_box ePaper GUI Fonts Config pico_stdlib hardware_spi)

# create map/bin/hex file etc.
pico_add_extra_outputs(love_box)

