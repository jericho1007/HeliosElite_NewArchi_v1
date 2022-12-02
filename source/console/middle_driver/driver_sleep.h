/*
 * driver_sleep.h
 *
 *  Created on: 2022年11月30日
 *      Author: JerichoLo
 */

#ifndef CONSOLE_MIDDLE_DRIVER_DRIVER_SLEEP_H_
#define CONSOLE_MIDDLE_DRIVER_DRIVER_SLEEP_H_
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"
#include "fsl_power.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define SLEEP_MCG_IRCLK_DISABLE                                 0U  /*!< MCGIRCLK disabled */
#define SLEEP_SIM_OSC32KSEL_OSC32KCLK_CLK                       0U  /*!< OSC32KSEL select: OSC32KCLK clock */
#define SLEEP_WAKE_UP_PORT	PORTC
#define SLEEP_WAKE_UP_GPIO	GPIOC
#define SLEEP_WAKE_UP_PIN	2

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void SLEEP_Init(void);
void SLEEP_EnterPowerDnMode(power_mode_t mode);

/*******************************************************************************
 * Variables
 ******************************************************************************/

#endif /* CONSOLE_MIDDLE_DRIVER_DRIVER_SLEEP_H_ */
