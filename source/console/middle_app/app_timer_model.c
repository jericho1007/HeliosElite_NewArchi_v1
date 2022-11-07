/*
 * app_timer_model.c
 *
 *  Created on: 2022年11月7日
 *      Author: JerichoLo
 */
#include "app_timer_model.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
void TMRMDL_SetTmrChannelStart(tmr_model_state_t *ch)
{
	ch->ctrl |= TMR_MODEL_BIT_START_MASK;
}

void TMRMDL_SetTmrChannelStop(tmr_model_state_t *ch)
{
	ch->ctrl &= (~TMR_MODEL_BIT_START_MASK);
}

bool TMRMDL_IsTmrChannelStart(tmr_model_state_t *ch)
{
	bool result = false;

	if((ch->ctrl & TMR_MODEL_BIT_START_MASK))
	{
		result = true;
	}

	return result;
}

bool TMR_IsTmrChannelTimeout(tmr_model_state_t *ch)
{
	bool result = false;

	if((ch->ctrl & TMR_MODEL_BIT_TIMEOUT_MASK))
	{
		result = true;
	}

	return result;
}

void TMR_SetTmrChannelTimeout(tmr_model_state_t *ch)
{
	ch->ctrl |= TMR_MODEL_BIT_TIMEOUT_MASK;
}

void TMR_ClearTmrChannelTimeout(tmr_model_state_t *ch)
{
	ch->ctrl &= (~TMR_MODEL_BIT_TIMEOUT_MASK);
}

