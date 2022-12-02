/*
 * app_io_back_light.c
 *
 *  Created on: 2022年11月7日
 *      Author: JerichoLo
 */
#include "app_io_back_light.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "public.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void BKLIGHT_PinMux(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
static void BKLIGHT_PinMux(void)
{
	CLOCK_EnableClock(kCLOCK_PortB);
	PORT_SetPinMux(BACK_LIGHT_IO_PORT, BACK_LIGHTL_IO_PIN, kPORT_MuxAsGpio);
}

void BKLIGHT_Init(void)
{
	gpio_pin_config_t pinConfig = {.pinDirection = kGPIO_DigitalOutput, .outputLogic = kio_level_low};

	BKLIGHT_PinMux();
	GPIO_PinInit(BACK_LIGHT_IO_GPIO, BACK_LIGHTL_IO_PIN, &pinConfig);
}

void BKLIGHT_SetPwr(backlight_state_t state)
{
	/* KP pin is low active */
	io_level_t lv = kio_level_low;
	if(state == kbacklight_power_on)
	{
		lv = kio_level_high;
	}
	GPIO_PinWrite(BACK_LIGHT_IO_GPIO, BACK_LIGHTL_IO_PIN, lv);
}


