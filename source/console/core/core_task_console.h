/*
 * core_task_console.h
 *
 *  Created on: 2022年11月30日
 *      Author: JerichoLo
 */

#ifndef CONSOLE_CORE_CORE_TASK_CONSOLE_H_
#define CONSOLE_CORE_CORE_TASK_CONSOLE_H_
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef struct _core_task_console {
	uint8_t taskDelayTime;
}core_task_console_t;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void TSKCON_Body(void* argument);

/*******************************************************************************
 * Variables
 ******************************************************************************/
extern core_task_console_t taskConsoleManage;

#endif /* CONSOLE_CORE_CORE_TASK_CONSOLE_H_ */
