cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(NONE)

if (CONFIG_BOOTLOADER_MCUBOOT)
   add_child_image(
     NAME mcuboot
     SOURCE_DIR ${MCUBOOT_DIR}/boot/zephyr
     )
endif()

add_child_image(
  NAME zmk
  SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/xmk/app
)

add_child_image(
    NAME hci_rpmsg
    SOURCE_DIR ${ZEPHYR_BASE}/samples/bluetooth/hci_rpmsg
    DOMAIN CPUNET
    )