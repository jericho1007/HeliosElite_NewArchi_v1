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
#define LPTMR_WATCH_GOAL_PWR_ON_CHECK	1500	/*ms*/
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
	bool watchTimeout = false;

	/* check delay type */
	for(index = 0; index < LPTMR_MANAGE_DELAY_TOTAL_CHANNELS; index++)
	{
		if(TMRMDL_IsTmrChannelStart(&lptmrManage.delay.chSet[index].state) &&
		   !TMRMDL_IsTmrChannelTimeout(&lptmrManage.delay.chSet[index].state))
		{
			lptmrManage.delay.chSet[index].state.cnt += LPTMR_MANAGE_TIME_INTERVAL;
			if(lptmrManage.delay.chSet[index].state.cnt == lptmrManage.delay.chSet[index].matchCnt)
			{
				TMRMDL_SetTmrChannelTimeout(&lptmrManage.delay.chSet[index].state);
			}
		}
	}

	/* check watch type*/
	for(index = 0; index < LPTMR_MANAGE_WATCH_TOTAL_CHANNELS; index++)
	{
		watchTimeout = false;
		if(TMRMDL_IsTmrChannelStart(&lptmrManage.watch.chSet[index]) &&
		   !TMRMDL_IsTmrChannelTimeout(&lptmrManage.watch.chSet[index]))
		{
			lptmrManage.watch.chSet[index].cnt += LPTMR_MANAGE_TIME_INTERVAL;
			switch(index)
			{
				case lptmr_watch_ch_sleep:
					watchTimeout = (lptmrManage.watch.chSet[index].cnt >= LPTMR_WATCH_GOAL_PWR_ON_CHECK);
					break;
				default:
					break;
			}
			if(watchTimeout)
			{
				TMRMDL_SetTmrChannelTimeout(&lptmrManage.watch.chSet[index]);
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

int LPTMRMANAGE_SetDelayTime(uint32_t time)
{
	int channel = -1;

	LPTMRMANAGE_GetDelayAvailableChannel(&channel);	/* find available channel */
	if(channel)
	{
		lptmrManage.delay.chSet[channel].matchCnt = time;	/* set delay time */
	}

	return channel;
}

