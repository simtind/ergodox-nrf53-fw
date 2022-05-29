# Copyright (c) 2022 Nordic Semiconductor ASA
# SPDX-License-Identifier: Apache-2.0


if(CONFIG_BOARD_BLAATIND_CPUAPP)
    board_runner_args(jlink "--device=nrf5340_xxaa_app" "--speed=4000")
    board_runner_args(pyocd "--target=nrf5340_cpuapp" "--frequency=4000000")
elseif(CONFIG_BOARD_BLAATIND_CPUAPP)
    board_runner_args(jlink "--device=nrf5340_xxaa_net" "--speed=4000")
    board_runner_args(jlink "--device=nrf5340_xxaa_net" "--speed=4000")
endif()


include(${ZEPHYR_BASE}/boards/common/nrfjprog.board.cmake)
include(${ZEPHYR_BASE}/boards/common/jlink.board.cmake)
include(${ZEPHYR_BASE}/boards/common/pyocd.board.cmake)
