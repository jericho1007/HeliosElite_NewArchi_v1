/*
 * app_io_pwr_key.c
 *
 *  Created on: 2022年11月7日
 *      Author: JerichoLo
 */
#include "app_io_pwr_key.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "public.h"
#include "app_lptmr_manage.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define PWRKEY_MATCH_TIME 	2000 /* unit:ms */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void PWRKEY_PinMux(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
static void PWRKEY_PinMux(void)
{
	CLOCK_EnableClock(kCLOCK_PortC);
	PORT_SetPinMux(PWR_KEY_IO_PORT, PWR_KEY_IO_PIN, kPORT_MuxAsGpio);
}

void PWRKEY_Init(void)
{
	gpio_pin_config_t pinConfig = {.pinDirection = kGPIO_DigitalOutput, .outputLogic = kio_level_high};

	PWRKEY_PinMux();
	GPIO_PinInit(PWR_KEY_IO_GPIO, PWR_KEY_IO_PIN, &pinConfig);
}

bool PWRKEY_CheckPwrOn(void)
{
	bool isPwrOn = false;
	int delayCh;

//	LPTMRMANAGE_GetDelayAvailableChannel(&delayCh);	/* find available channel */
	delayCh = LPTMRMANAGE_SetDelayTime();
	if(delayCh >= 0)
	{
		lptmrManage.delay.chSet[delayCh].matchCnt = PWRKEY_MATCH_TIME;				/* set delay time */
		TMRMDL_SetTmrChannelStart(&lptmrManage.delay.chSet[delayCh].state);			/* enable channel */
		while(GPIO_PinRead(PWR_KEY_IO_GPIO, PWR_KEY_IO_PIN) == kio_level_low &&		/* power key active is low */
			  !TMR_IsTmrChannelTimeout(&lptmrManage.delay.chSet[delayCh].state))
		{
			/* WDT feed*/
		}
		TMRMDL_SetTmrChannelStop(&lptmrManage.delay.chSet[delayCh].state);			/* disable channel */
		if(TMR_IsTmrChannelTimeout(&lptmrManage.delay.chSet[delayCh].state))
		{
			isPwrOn = true;
		}
	}

	return isPwrOn;
}
