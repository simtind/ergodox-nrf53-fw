/*
 * Copyright (c) 2019-2021 Nordic Semiconductor ASA.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <init.h>

#include <soc.h>


static int hvreg_set_3v3(const struct device *dev)
{
	ARG_UNUSED(dev);

	if (NRF_UICR_S->VREGHVOUT != UICR_VREGHVOUT_VREGHVOUT_3V3)
	{
		NRF_NVMC_S->CONFIG = NVMC_CONFIG_WEN_Wen;
		while(NRF_NVMC_S->READY != 1);
		NRF_UICR_S->VREGHVOUT = UICR_VREGHVOUT_VREGHVOUT_3V3;
		while(NRF_NVMC_S->READY != 1);
		NRF_NVMC_S->CONFIG = NVMC_CONFIG_WEN_Ren;
		while(NRF_NVMC_S->READY != 1);	
		NVIC_SystemReset();	
	}

	return 0;
}

SYS_INIT(hvreg_set_3v3, POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEVICE);
