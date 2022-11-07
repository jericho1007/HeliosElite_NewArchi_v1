/*
 * app_io_remote_pwr.h
 *
 *  Created on: 2022年11月7日
 *      Author: JerichoLo
 */

#ifndef CONSOLE_MIDDLE_APP_APP_IO_REMOTE_PWR_H_
#define CONSOLE_MIDDLE_APP_APP_IO_REMOTE_PWR_H_
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define REMOTE_PWR_IO_PORT		PORTA
#define REMOTE_PWR_IO_GPIO		GPIOA
#define REMOTE_PWR_IO_PIN		16

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void REMOTEPWR_Init(void);


#endif /* CONSOLE_MIDDLE_APP_APP_IO_REMOTE_PWR_H_ */
