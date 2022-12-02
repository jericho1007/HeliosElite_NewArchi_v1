/*
 * app_io_kp_ctrl.h
 *
 *  Created on: 2022年11月7日
 *      Author: JerichoLo
 */

#ifndef CONSOLE_MIDDLE_APP_APP_IO_KP_CTRL_H_
#define CONSOLE_MIDDLE_APP_APP_IO_KP_CTRL_H_
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define KP_CTRL_IO_PORT		PORTB
#define KP_CTRL_IO_GPIO		GPIOB
#define KP_CTRL_IO_PIN		18

typedef enum _kp_state {
	kkpstate_on = 0,
	kp_state_off
}kp_state_t;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void KPCTRL_Init(void);
void KPCTRL_SetKPState(kp_state_t state);

#endif /* CONSOLE_MIDDLE_APP_APP_IO_KP_CTRL_H_ */
