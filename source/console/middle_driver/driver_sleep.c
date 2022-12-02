/*
 * driver_sleep.c
 *
 *  Created on: 2022年11月30日
 *      Author: JerichoLo
 */
#include "driver_sleep.h"
#include "fsl_clock.h"
#include "fsl_port.h"
#include "fsl_smc.h"
#include "fsl_rcm.h"
#include "fsl_pmc.h"
#include "fsl_dcdc.h"
#include "fsl_llwu.h"
#include "fsl_lptmr.h"
#include "clock_config.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void SLEEP_PinMux(void);
static void SLEEP_BoardConfigureDcdc(void);
static void SLEEP_FllStableDelay(void);
static void SLEEP_SetLowPowerClockConfig(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
void SLEEP_Init(void)
{
	SLEEP_PinMux();
	SMC_SetPowerModeProtection(SMC, kSMC_AllowPowerModeVlls);
	if (kRCM_SourceWakeup & RCM_GetPreviousResetSources(RCM)) /* Wakeup from VLLS. */
	{
		PMC_ClearPeriphIOIsolationFlag(PMC);
		NVIC_ClearPendingIRQ(LLWU_IRQn);
	}
	SLEEP_BoardConfigureDcdc();
	NVIC_EnableIRQ(LLWU_IRQn);
	NVIC_EnableIRQ(PORTB_PORTC_IRQn);
}

void SLEEP_EnterPowerDnMode(power_mode_t mode)
{

	switch(mode)
	{
		case kPWR_PowerModeRun:
			break;
		case kPWR_PowerModeWait:
			break;
		case kPWR_PowerModeStop:
			break;
		case kPWR_PowerModeVlpr:
			break;
		case kPWR_PowerModeVlpw:
			break;
		case kPWR_PowerModeVlps:
			break;
		case kPWR_PowerModeLls:
			break;
		case kPWR_PowerModeVlls0:
			break;
		case kPWR_PowerModeVlls1: 	// v
			SLEEP_SetLowPowerClockConfig();
			RSIM->CONTROL &= ~RSIM_CONTROL_RF_OSC_EN_MASK;
			PORT_SetPinInterruptConfig(PORTC, 2, kPORT_InterruptFallingEdge);
			LLWU_SetExternalWakeupPinMode(LLWU, 10, kLLWU_ExternalPinFallingEdge);
			NVIC_EnableIRQ(LLWU_IRQn);
			POWER_EnterPowerMode(kPWR_PowerModeVlls1);
			break;
		case kPWR_PowerModeVlls2:
			break;
		case kPWR_PowerModeVlls3:
			break;
		default:
			break;
	}
}

void PORTB_PORTC_IRQHandler(void)
{
    if ((1U << 2) & PORT_GetPinsInterruptFlags(PORTC))
    {
        /* Disable interrupt. */
        PORT_SetPinInterruptConfig(SLEEP_WAKE_UP_PORT, SLEEP_WAKE_UP_PIN, kPORT_InterruptOrDMADisabled);
        PORT_ClearPinsInterruptFlags(SLEEP_WAKE_UP_PORT, (1U << SLEEP_WAKE_UP_PIN));
    }
}

void LLWU_IRQHandler(void)
{
    /* If wakeup by LPTMR. */
    if (LLWU_GetInternalWakeupModuleFlag(LLWU, 0))
    {
        LPTMR_DisableInterrupts(LPTMR0, kLPTMR_TimerInterruptEnable);
        LPTMR_ClearStatusFlags(LPTMR0, kLPTMR_TimerCompareFlag);
        LPTMR_StopTimer(LPTMR0);
    }
    /* If wakeup by external pin. */
    if (LLWU_GetExternalWakeupPinFlag(LLWU, 10))
    {
        PORT_SetPinInterruptConfig(SLEEP_WAKE_UP_PORT, SLEEP_WAKE_UP_PIN, kPORT_InterruptOrDMADisabled);
        PORT_ClearPinsInterruptFlags(SLEEP_WAKE_UP_PORT, (1U << SLEEP_WAKE_UP_PIN));
        LLWU_ClearExternalWakeupPinFlag(LLWU, 10);
    }
}


static void SLEEP_PinMux(void)
{
	port_pin_config_t wakeUpPinConfig = {
			kPORT_PullUp,				/* Internal pull-up resistor is enabled */
			kPORT_SlowSlewRate,			/* Slow slew rate is configured */
			kPORT_PassiveFilterDisable,	/* Passive filter is disabled */
			kPORT_LowDriveStrength,		/* Low drive strength is configured */
			kPORT_MuxAsGpio				/* Pin is configured as PTC2 */
	};

	CLOCK_EnableClock(kCLOCK_PortC);
	PORT_SetPinConfig(SLEEP_WAKE_UP_PORT, 2, &wakeUpPinConfig);
}

static void SLEEP_BoardConfigureDcdc(void)
{
    CLOCK_EnableClock(kCLOCK_Dcdc0);

    dcdc_low_power_config_t dcdcLowPowerConfig;
    dcdc_loop_control_config_t dcdcLoopControlConfig;

    DCDC_GetDefaultLowPowerConfig(&dcdcLowPowerConfig);
    dcdcLowPowerConfig.enableDiffComparators = true;
    DCDC_SetLowPowerConfig(DCDC, &dcdcLowPowerConfig);

    DCDC_GetDefaultLoopControlConfig(&dcdcLoopControlConfig);
    dcdcLoopControlConfig.enableDiffHysteresis       = true;
    dcdcLoopControlConfig.enableCommonHysteresis     = true;
    dcdcLoopControlConfig.enableInvertHysteresisSign = true;
    DCDC_SetLoopControlConfig(DCDC, &dcdcLoopControlConfig);

    DCDC_LockTargetVoltage(DCDC);
    DCDC_SetBatteryVoltageDivider(DCDC, kDCDC_VBatVoltageDividerOff);

    CLOCK_DisableClock(kCLOCK_Dcdc0);
}

static void SLEEP_FllStableDelay(void)
{
    volatile uint32_t i = 30000U;
    while (i--)
    {
        __NOP();
    }
}

static void SLEEP_SetLowPowerClockConfig(void)
{
    const sim_clock_config_t simConfig = {
        .er32kSrc = SLEEP_SIM_OSC32KSEL_OSC32KCLK_CLK, /* OSC32KSEL select: OSC32KCLK clock */
        .clkdiv1  = 0x10000U,                    /* SIM_CLKDIV1 - OUTDIV1: /1, OUTDIV4: /2 */
    };

    /* ERR010224 */
    RSIM->RF_OSC_CTRL |=
        RSIM_RF_OSC_CTRL_RADIO_EXT_OSC_OVRD_EN_MASK; /* Prevent XTAL_OUT_EN from generating XTAL_OUT request */
    /* Set the system clock dividers in SIM to safe value. */
    CLOCK_SetSimSafeDivs();
    /* Set MCG to FEI mode. */
#if FSL_CLOCK_DRIVER_VERSION >= MAKE_VERSION(2, 2, 0)
    CLOCK_BootToFeiMode(kMCG_Dmx32Default, kMCG_DrsLow, SLEEP_FllStableDelay);
#else
    CLOCK_BootToFeiMode(kMCG_DrsMid, CLOCK_CONFIG_FllStableDelay);
#endif
    /* Configure the Internal Reference clock (MCGIRCLK). */
    CLOCK_SetInternalRefClkConfig(SLEEP_MCG_IRCLK_DISABLE, kMCG_IrcSlow, 0U);
    /* Set the clock configuration in SIM module. */
    CLOCK_SetSimConfig(&simConfig);
}
