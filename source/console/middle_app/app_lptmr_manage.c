/*
 * app_lptmr_manage.c
 *
 *  Created on: 2022年11月7日
 *      Author: JerichoLo
 */
#include "app_lptmr_manage.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
lptmr_manage_t lptmrManage;

/*******************************************************************************
 * Code
 ******************************************************************************/
void LPTMRMANAGE_Init(void)
{
	memset(&lptmrManage, 0, sizeof(lptmr_manage_t));
}

void LPTMRMANAGE_CallBack(void)
{
	uint8_t index;

	/* check delay type */
	for(index = 0; index < LPTMR_MANAGE_DELAY_TOTAL_CHANNELS; index++)
	{
		if(TMRMDL_IsTmrChannelStart(&lptmrManage.delay.chSet[index].state) &&
		   !TMR_IsTmrChannelTimeout(&lptmrManage.delay.chSet[index].state))
		{
			lptmrManage.delay.chSet[index].state.cnt += LPTMR_MANAGE_TIME_INTERVAL;
			if(lptmrManage.delay.chSet[index].state.cnt == lptmrManage.delay.chSet[index].matchCnt)
			{
				TMR_SetTmrChannelTimeout(&lptmrManage.delay.chSet[index].state);
			}
		}
	}

	/* check watch type*/
	for(index = 0; index < LPTMR_MANAGE_WATCH_TOTAL_CHANNELS; index++)
	{
		if(TMRMDL_IsTmrChannelStart(&lptmrManage.watch.chSet[index]) &&
		   !TMR_IsTmrChannelTimeout(&lptmrManage.watch.chSet[index]))
		{
			lptmrManage.watch.chSet[index].cnt += LPTMR_MANAGE_TIME_INTERVAL;
			switch(index)
			{
				case lptmr_watch_ch_sleep:
					break;
				default:
					break;
			}
		}
	}
}

void LPTMRMANAGE_GetDelayAvailableChannel(int *regCh)
{
	int index;

	*regCh = -1;
	for(index = 0; index < LPTMR_MANAGE_DELAY_TOTAL_CHANNELS; index++)
	{
		if(!TMRMDL_IsTmrChannelStart(&lptmrManage.delay.chSet[index].state))
		{
			*regCh = index;
		}
	}
}

