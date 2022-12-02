/*
 * core_task_console.c
 *
 *  Created on: 2022年11月30日
 *      Author: JerichoLo
 */
#include "core_task_console.h"
#include "FreeRTOS.h"
#include "task.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define TSKCON_DEFAULT_DELAY_TIME		5 /* unit:ms */
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void TSKCON_Init(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
core_task_console_t taskConsoleManage;

/*******************************************************************************
 * Code
 ******************************************************************************/
static void TSKCON_Init(void)
{
	memset(&taskConsoleManage, 0, sizeof(core_task_console_t));
	taskConsoleManage.taskDelayTime	= TSKCON_DEFAULT_DELAY_TIME;
}

void TSKCON_Body(void* argument)
{
	TSKCON_Init();
	while(1)
	{
		vTaskDelay(taskConsoleManage.taskDelayTime);
	}
}
