cmake_minimum_required(VERSION 3.13.1)

set(CONFIG_APPLICATION_DEFINED_SYSCALL true)
set(ZMK_APP_DIR ${CMAKE_CURRENT_LIST_DIR}/zmk/app)
set(ZMK_CONFIG ${CMAKE_CURRENT_LIST_DIR})

list(APPEND BOARD_ROOT ${CMAKE_CURRENT_LIST_DIR} ${ZMK_APP_DIR})
list(APPEND DTS_ROOT ${ZMK_APP_DIR})

# Add ZMK custom Zephyr module for drivers w/ syscalls, etc.
list(APPEND DTS_ROOT ${ZMK_APP_DIR}/drivers/zephyr)

list(APPEND ZEPHYR_EXTRA_MODULES ${ZMK_APP_DIR}/drivers)

include(${ZMK_APP_DIR}/cmake/zmk_config.cmake)

# Find Zephyr. This also loads Zephyr's build system.
find_package(Zephyr REQUIRED HINTS zephyr)

project(zmk)

zephyr_linker_sources(RODATA ${ZMK_APP_DIR}/include/linker/zmk-events.ld)

add_subdirectory(zmk/app)
