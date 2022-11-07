/*
 * app_io_pwr_key.h
 *
 *  Created on: 2022年11月7日
 *      Author: JerichoLo
 */

#ifndef CONSOLE_MIDDLE_APP_APP_IO_PWR_KEY_H_
#define CONSOLE_MIDDLE_APP_APP_IO_PWR_KEY_H_
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define PWR_KEY_IO_PORT		PORTC
#define PWR_KEY_IO_GPIO		GPIOC
#define PWR_KEY_IO_PIN		2

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void PWRKEY_Init(void);
bool PWRKEY_CheckPwrOn(void);

#endif /* CONSOLE_MIDDLE_APP_APP_IO_PWR_KEY_H_ */
