/*
 * app_io_remote_pwr.c
 *
 *  Created on: 2022年11月7日
 *      Author: JerichoLo
 */
#include "app_io_remote_pwr.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "public.h"
#include "app_lptmr_manage.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void REMOTEPWR_PinMux(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
static void REMOTEPWR_PinMux(void)
{
	CLOCK_EnableClock(kCLOCK_PortB);
	PORT_SetPinMux(REMOTE_PWR_IO_PORT, REMOTE_PWR_IO_PIN, kPORT_MuxAsGpio);
}

void REMOTEPWR_Init(void)
{
	gpio_pin_config_t pinConfig = {.pinDirection = kGPIO_DigitalOutput, .outputLogic = kio_level_high};

	REMOTEPWR_PinMux();
	GPIO_PinInit(REMOTE_PWR_IO_GPIO, REMOTE_PWR_IO_PIN, &pinConfig);
}

