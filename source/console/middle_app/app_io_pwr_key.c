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
#include "driver_wdt.h"
#include "bike_config.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define PWRKEY_CHECK_RELEASE_COUNT	1000 /* = 1000 NOP() */

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

	TMRMDL_SetTmrChannelStart(&lptmrManage.watch.ch.powerOnCheck);			/* enable channel */
	while(GPIO_PinRead(PWR_KEY_IO_GPIO, PWR_KEY_IO_PIN) == kio_level_low) 	/* power key low active(hold) */
	{
		#if SYS_WDT_ENABLE
			WDT_Feed();	/* WDT feed */
		#endif
		if(TMRMDL_IsTmrChannelTimeout(&lptmrManage.watch.ch.powerOnCheck)) 	/* reach goal time or not */
		{
			memset(&lptmrManage.watch.ch.powerOnCheck, 0, sizeof(tmr_model_state_t)); /* clear structure info release for sharing use */
			isPwrOn = true;
			break;
		}
	}

	return isPwrOn;
}

void PWRKEY_CheckKeyReleased(void)
{
	uint32_t checkedCnt = 0;

	do
	{
		if(GPIO_PinRead(PWR_KEY_IO_GPIO, PWR_KEY_IO_PIN) == kio_level_high)	/* power key normal keep high */
		{
			checkedCnt++;
		}
		else
		{
			checkedCnt = 0;
		}
		#if SYS_WDT_ENABLE
			WDT_Feed();	/* WDT feed */
		#endif
	}while(checkedCnt < PWRKEY_CHECK_RELEASE_COUNT);
}
