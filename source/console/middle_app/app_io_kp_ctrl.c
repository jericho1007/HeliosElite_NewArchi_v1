/*
 * app_io_kp_ctrl.c
 *
 *  Created on: 2022年11月7日
 *      Author: JerichoLo
 */
#include "app_io_kp_ctrl.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "public.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void KPCTRL_PinMux(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
static void KPCTRL_PinMux(void)
{
	CLOCK_EnableClock(kCLOCK_PortB);
	PORT_SetPinMux(KP_CTRL_IO_PORT, KP_CTRL_IO_PIN, kPORT_MuxAsGpio);
}

void KPCTRL_Init(void)
{
	gpio_pin_config_t pinConfig = {.pinDirection = kGPIO_DigitalOutput, .outputLogic = kio_level_high};

	KPCTRL_PinMux();
	GPIO_PinInit(KP_CTRL_IO_GPIO, KP_CTRL_IO_PIN, &pinConfig);
}

