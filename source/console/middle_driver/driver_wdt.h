/*
 * driver_wdt.h
 *
 *  Created on: 2022年11月23日
 *      Author: JerichoLo
 */

#ifndef CONSOLE_MIDDLE_DRIVER_DRIVER_WDT_H_
#define CONSOLE_MIDDLE_DRIVER_DRIVER_WDT_H_
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void WDT_Init(void);
void WDT_Feed(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

#endif /* CONSOLE_MIDDLE_DRIVER_DRIVER_WDT_H_ */
