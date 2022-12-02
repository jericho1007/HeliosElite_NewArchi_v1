/*
 * app_io_back_light.h
 *
 *  Created on: 2022年11月7日
 *      Author: JerichoLo
 */

#ifndef CONSOLE_MIDDLE_APP_APP_IO_BACK_LIGHT_H_
#define CONSOLE_MIDDLE_APP_APP_IO_BACK_LIGHT_H_
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BACK_LIGHT_IO_PORT		PORTB
#define BACK_LIGHT_IO_GPIO		GPIOB
#define BACK_LIGHTL_IO_PIN		2

typedef enum _backlight_power {
	kbacklight_power_off = 0,
	kbacklight_power_on
}backlight_state_t;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void BKLIGHT_Init(void);
void BKLIGHT_SetPwr(backlight_state_t state);

/*******************************************************************************
 * Variables
 ******************************************************************************/


#endif /* CONSOLE_MIDDLE_APP_APP_IO_BACK_LIGHT_H_ */
