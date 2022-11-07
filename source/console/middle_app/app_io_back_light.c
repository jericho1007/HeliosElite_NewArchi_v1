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
	gpio_pin_config_t pinConfig = {.pinDirection = kGPIO_DigitalOutput, .outputLogic = kio_level_high};

	BKLIGHT_PinMux();
	GPIO_PinInit(BACK_LIGHT_IO_GPIO, BACK_LIGHTL_IO_PIN, &pinConfig);
}


