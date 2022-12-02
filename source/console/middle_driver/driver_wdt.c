/*
 * driver_wdt.c
 *
 *  Created on: 2022年11月23日
 *      Author: JerichoLo
 */
#include "driver_wdt.h"
#include "MKW38A4.h"
#include "fsl_cop.h"
#include "fsl_rcm.h"
#include "portmacro.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
void WDT_Init(void)
{
	cop_config_t stConfigCop;
	COP_GetDefaultConfig(&stConfigCop);
	stConfigCop.timeoutMode = kCOP_ShortTimeoutMode;
	COP_Init(SIM, &stConfigCop);
}

void WDT_Feed(void)
{
	COP_Refresh(SIM);
}
