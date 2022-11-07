/*
 * driver_timer.h
 *
 *  Created on: 2022年11月7日
 *      Author: JerichoLo
 */

#ifndef CONSOLE_MIDDLE_DRIVER_DRIVER_TIMER_H_
#define CONSOLE_MIDDLE_DRIVER_DRIVER_TIMER_H_
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"
#include "fsl_lptmr.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void TIMER_Init(void *lpTmrCb, void *tpmTmrCb);

/*******************************************************************************
 * Variables
 ******************************************************************************/


#endif /* CONSOLE_MIDDLE_DRIVER_DRIVER_TIMER_H_ */
