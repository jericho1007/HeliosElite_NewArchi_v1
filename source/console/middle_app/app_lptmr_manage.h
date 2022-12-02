/*
 * app_lptmr_manage.h
 *
 *  Created on: 2022年11月7日
 *      Author: JerichoLo
 */

#ifndef CONSOLE_MIDDLE_APP_APP_LPTMR_MANAGE_H_
#define CONSOLE_MIDDLE_APP_APP_LPTMR_MANAGE_H_
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"
#include "app_timer_model.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define LPTMR_MANAGE_DELAY_TOTAL_CHANNELS		1
#define LPTMR_MANAGE_WATCH_TOTAL_CHANNELS		10
#define LPTMR_MANAGE_TIME_INTERVAL				10 /* unit:10ms, must match low power base driver config */

#define LPTMR_MANAGE_WATCH_PWR_ON_CHECK_CH		0

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
typedef enum _lptmr_delay_ch {
	klptmr_ch_delay = 0,
}_lptmr_delay_ch_t;

typedef enum _lptmr_watch_ch {
	lptmr_watch_ch_sleep = 0,	/* share with power on check */
}lptmr_watch_ch_t;

typedef struct _lptmr_manage {
	union {
		struct {
			tmr_model_delay_t delay;
		}ch;
		tmr_model_delay_t chSet[LPTMR_MANAGE_DELAY_TOTAL_CHANNELS];
	}delay;

	union {
		struct {
			union {
				tmr_model_state_t sleep;
				tmr_model_state_t powerOnCheck;
			};
		}ch;
		tmr_model_state_t chSet[LPTMR_MANAGE_WATCH_TOTAL_CHANNELS];
	}watch;
}lptmr_manage_t;

void LPTMRMANAGE_Init(void);
void LPTMRMANAGE_CallBack(void);
void LPTMRMANAGE_GetDelayAvailableChannel(int *regCh);
int LPTMRMANAGE_SetDelayTime(uint32_t time);

/*******************************************************************************
 * Variables
 ******************************************************************************/
extern lptmr_manage_t lptmrManage;

#endif /* CONSOLE_MIDDLE_APP_APP_LPTMR_MANAGE_H_ */
