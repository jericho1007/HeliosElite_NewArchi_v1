/*
 * app_timer_model.h
 *
 *  Created on: 2022年11月7日
 *      Author: JerichoLo
 */

#ifndef CONSOLE_MIDDLE_APP_APP_TIMER_MODEL_H_
#define CONSOLE_MIDDLE_APP_APP_TIMER_MODEL_H_
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define TMR_MODEL_BIT_START_MASK		0x01	/* bit 0, 1 as start, 0 as stop */
#define TMR_MODEL_BIT_TIMEOUT_MASK		0x02	/* bit 1, 1 as timeout, 0 as on going */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
typedef struct _tmr_model_state {
	uint8_t	ctrl;
	uint32_t cnt;
}tmr_model_state_t;

typedef struct _tmr_model_delay {
	tmr_model_state_t state;
	uint32_t matchCnt;
}tmr_model_delay_t;

void TMRMDL_SetTmrChannelStart(tmr_model_state_t *ch);
void TMRMDL_SetTmrChannelStop(tmr_model_state_t *ch);
bool TMRMDL_IsTmrChannelStart(tmr_model_state_t *ch);
bool TMRMDL_IsTmrChannelTimeout(tmr_model_state_t *ch);
void TMRMDL_SetTmrChannelTimeout(tmr_model_state_t *ch);
void TMRMDL_ClearTmrChannelTimeout(tmr_model_state_t *ch);

#endif /* CONSOLE_MIDDLE_APP_APP_TIMER_MODEL_H_ */
