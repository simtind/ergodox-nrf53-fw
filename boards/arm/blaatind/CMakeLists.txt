# Copyright (c) 2019 Nordic Semiconductor ASA.
# SPDX-License-Identifier: Apache-2.0


if (CONFIG_BOARD_BLAATIND_CPUAPP)
  zephyr_library()
  zephyr_library_sources(nrf5340_set_hv_out.c)
  if (CONFIG_BOARD_ENABLE_CPUNET)
    zephyr_library_sources(nrf5340_cpunet_reset.c)
  endif()
endif()
