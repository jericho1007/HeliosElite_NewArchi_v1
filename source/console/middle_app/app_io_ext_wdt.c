/*
 * app_io_ext_wdt.c
 *
 *  Created on: 2022年11月7日
 *      Author: JerichoLo
 */
#include "app_io_ext_wdt.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "public.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void EXTWDT_PinMux(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
static void EXTWDT_PinMux(void)
{
	CLOCK_EnableClock(kCLOCK_PortB);
	PORT_SetPinMux(KP_CTRL_IO_PORT, KP_CTRL_IO_PIN, kPORT_MuxAsGpio);
}

void EXTWDT_Init(void)
{
	gpio_pin_config_t pinConfig = {.pinDirection = kGPIO_DigitalOutput, .outputLogic = kio_level_low};

	EXTWDT_PinMux();
	GPIO_PinInit(KP_CTRL_IO_GPIO, KP_CTRL_IO_PIN, &pinConfig);
}
