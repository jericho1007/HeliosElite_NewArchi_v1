/*
 * driver_timer.c
 *
 *  Created on: 2022年11月7日
 *      Author: JerichoLo
 */
#include "driver_timer.h"
#include "fsl_port.h"
#include "public.h"
#include "fsl_lptmr.h"
#include "fsl_tpm.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define CONSOLE_LPTMR_BASE				LPTMR0
#define CONSOLE_LPTMR_IRQ				LPTMR0_IRQn
#define CONSOLE_LPTMR_INTERVAL_TIME		10 /* unit:10ms */
#define CONSOLE_TPMTMR_BASE				TPM2
#define CONSOLE_TPMTMR_IRQ				TPM2_IRQn

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void TIMER_InitLptmr(void *cb);
static void TIMER_InitTpmtmr(void *cb);
void (*LP_TMR_CB)(void);
void (*TPM_TMR_CB)(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
static void TIMER_InitLptmr(void *cb)
{
	lptmr_config_t lptmrConfig;

	LPTMR_GetDefaultConfig(&lptmrConfig);			/* Configure LPTMR */
	LPTMR_Init(CONSOLE_LPTMR_BASE, &lptmrConfig);	/* Initialize the LPTMR */
	LPTMR_SetTimerPeriod(CONSOLE_LPTMR_BASE, USEC_TO_COUNT(CONSOLE_LPTMR_INTERVAL_TIME, CLOCK_GetFreq(kCLOCK_LpoClk)));	/* Set timer period */
	LPTMR_EnableInterrupts(CONSOLE_LPTMR_BASE, kLPTMR_TimerInterruptEnable);	/* Enable timer interrupt */
	EnableIRQ(CONSOLE_LPTMR_IRQ);			/* Enable at the NVIC */
	LPTMR_StartTimer(CONSOLE_LPTMR_BASE);	/* Start base0 counting */
	LP_TMR_CB = cb;
}

static void TIMER_InitTpmtmr(void *cb)
{
	tpm_config_t tpmInfo;

	TPM_GetDefaultConfig(&tpmInfo);
	tpmInfo.prescale = kTPM_Prescale_Divide_128;	/* TPM clock divide by TPM_PRESCALER */
	TPM_Init(CONSOLE_TPMTMR_BASE, &tpmInfo);					/* Initialize TPM module */
	TPM_SetTimerPeriod(CONSOLE_TPMTMR_BASE, 246600);
	TPM_EnableInterrupts(CONSOLE_TPMTMR_BASE, kTPM_TimeOverflowInterruptEnable);
	EnableIRQ(CONSOLE_TPMTMR_IRQ);
	TPM_StartTimer(CONSOLE_TPMTMR_BASE, kTPM_SystemClock);
	TPM_TMR_CB = cb;
}

void TIMER_Init(void *lpTmrCb, void *tpmTmrCb)
{
	TIMER_InitLptmr(lpTmrCb);
	TIMER_InitTpmtmr(tpmTmrCb);
}

void LPTMR0_IRQHandler(void)
{
	LPTMR_ClearStatusFlags(CONSOLE_LPTMR_BASE, kLPTMR_TimerCompareFlag);	/* Clear interrupt flag */
	LP_TMR_CB();
}

void TPM2_IRQHandler(void)
{
	TPM_ClearStatusFlags(CONSOLE_TPMTMR_BASE, kTPM_TimeOverflowFlag);	/* Clear interrupt flag */
	TPM_TMR_CB();
}
