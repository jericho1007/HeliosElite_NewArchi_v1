/*
 * bike_config.h
 *
 *  Created on: 2022年11月7日
 *      Author: JerichoLo
 */

#ifndef CONSOLE_CONFIG_BIKE_CONFIG_H_
#define CONSOLE_CONFIG_BIKE_CONFIG_H_
#include "stdint.h"
#include "ax_config.h"
#include "wh_config.h"

/* choice vender */
#define VENDER_SINBON		0
#define VENDER_AXMAN		0
#define VENDER_WHEELER		1

/*******************************************************************************
 * service-core function
 ******************************************************************************/
#define SYS_WDT_ENABLE		0
#define SYS_SUP_AUTO_MODE	0
#define SYS_SUP_MOTION_KEY	0

/*
 * console system firmware version
 * */
#define FW_VERSION_CONSOLE_MAIN			1	/* HW update */
#define FW_VERSION_CONSOLE_SUB			2	/* FW significant update */
#define FW_VERSION_CONSOLE_RELEASE		0
#define FW_VERSION_CONSOLE_DEBUG		35
#define FW_VERSION_CONSOLE				((uint32_t)FW_VERSION_VCU_MAIN << 24 | (uint32_t)FW_VERSION_VCU_SUB << 16 | (uint32_t)FW_VERSION_VCU_RELEASE << 8 | (uint32_t)FW_VERSION_VCU_DEBUG)

/*
 * console system protocol version
 * */
#define PROTOCOL_VERSION_MAIN			0
#define PROTOCOL_VERSION_SUB			0
#define PROTOCOL_VERSION_RELEASE		0
#define PROTOCOL_VERSION_DEBUG			35
#define PROTOCOL_VERSION_CONSOLE		((uint32_t)PROTOCOL_VERSION_MAIN << 24 | (uint32_t)PROTOCOL_VERSION_SUB << 16 | (uint32_t)PROTOCOL_VERSION_RELEASE << 8 | (uint32_t)PROTOCOL_VERSION_DEBUG)

/*
 * default bike info
 */
#if VENDER_AXMAN
/**************************************************************
 *	parameters configure
 **************************************************************/
	#define CONSOLE_MODULE_NAME		DEFAULT_CONSOLE_MODULE_NAME
	#define CONSOLE_SW_CODE			AX_CONSOLE_SW_CODE
	#define CONSOLE_SN				DEFAULT_CONSOLE_SN
	#define CONSOLE_FW_VER			DEFAULT_CONSOLE_FW_VER
	#define CONSOLE_VENDER			DEFAULT_CONSOLE_VENDER
	#define CONSOLE_PRO_VER			DEFAULT_CONSOLE_PRO_VER
	#define CONSOLE_PROD_DATE		DEFAULT_CONSOLE_PROD_DATE
	#define CONSOLE_MAC_ADR			DEFAULT_CONSOLE_MAC_ADR

	#define BIKE_MODULE_NAME		AX_BIKE_MODULE_NAME
	#define BIKE_SW_CODE			AX_BIKE_SW_CODE
	#define BIKE_SN					AX_BIKE_SN
	#define BIKE_FW_VER				AX_BIKE_FW_VER
	#define BIKE_VENDER				AX_BIKE_VENDER
	#define BIKE_PRO_VER			AX_BIKE_PRO_VER
	#define BIKE_PROD_DATE			AX_BIKE_PROD_DATE
/**************************************************************
 *	support base features
 **************************************************************/
	#define BIKE_WHEEL_DIAMETER		AX_WHEEL_DIAMETER
	#define BIKE_WHEEL_CIRCLE		AX_BIKE_WHEEL_CIRCLE
	#define BIKE_MOTOR_CURR_MAX		AX_BIKE_MOTOR_CURRENT_MAX

/**************************************************************
 *	support peripheral features
 **************************************************************/
	#define PERI_DAUL_BATTERY		AX_DAUL_BATTERY
	#define PERI_3KEY_BTNS			AX_3KEY_BTNS
	#define	PERI_5KEY_BTNS			AX_5KEY_BTNS
	#define	PERI_DIRECTION_LIGHT	AX_DIRECTION_LIGHT
	#define	PERI_HEAD_LIGHT			AX_HEAD_LIGHT
	#define	PERI_TAIL_LIGHT			AX_TAIL_LIGHT
	#define	PERI_BLIND_SPOT			AX_BLIND_SPOT
	#define	PERI_ELEC_SHIFT			AX_ELEC_SHIFT
	#define	PERI_ELEC_LOCK			AX_ELEC_LOCK
	#define	PERI_DAUL_MOTOR			AX_DAUL_MOTOR
	#define PERI_TIRE_GAGE			AX_TIRE_GAGE
/**************************************************************
 *	customize function
 **************************************************************/
#define CUSTOMIZED_FN_WALK_MODE_ON_OFF	AX_WALK_MODE_ON_OFF

/**************************************************************
 *	customize function style type
 **************************************************************/
#define DIRECTION_DISPLAY_TYPE		AX_DIRECTION_TYPE


#elif VENDER_WHEELER
/**************************************************************
 *	parameters configure
 **************************************************************/
	#define CONSOLE_MODULE_NAME		DEFAULT_CONSOLE_MODULE_NAME
	#define CONSOLE_SW_CODE			WH_CONSOLE_SW_CODE
	#define CONSOLE_SN				DEFAULT_CONSOLE_SN
	#define CONSOLE_FW_VER			DEFAULT_CONSOLE_FW_VER
	#define CONSOLE_VENDER			DEFAULT_CONSOLE_VENDER
	#define CONSOLE_PRO_VER			DEFAULT_CONSOLE_PRO_VER
	#define CONSOLE_PROD_DATE		DEFAULT_CONSOLE_PROD_DATE
	#define CONSOLE_MAC_ADR			DEFAULT_CONSOLE_MAC_ADR

	#define BIKE_MODULE_NAME		WH_BIKE_MODULE_NAME
	#define BIKE_SW_CODE			WH_BIKE_SW_CODE
	#define BIKE_SN					WH_BIKE_SN
	#define BIKE_FW_VER				WH_BIKE_FW_VER
	#define BIKE_VENDER				WH_BIKE_VENDER
	#define BIKE_PRO_VER			WH_BIKE_PRO_VER
	#define BIKE_PROD_DATE			WH_BIKE_PROD_DATE
/**************************************************************
 *	support base features
 **************************************************************/
	#define BIKE_WHEEL_DIAMETER		WH_WHEEL_DIAMETER
	#define BIKE_WHEEL_CIRCLE		WH_BIKE_WHEEL_CIRCLE
	#define BIKE_MOTOR_CURR_MAX		WH_BIKE_MOTOR_CURRENT_MAX

/**************************************************************
 *	support peripheral features
 **************************************************************/
	#define PERI_DAUL_BATTERY		WH_DAUL_BATTERY
	#define PERI_3KEY_BTNS			WH_3KEY_BTNS
	#define	PERI_5KEY_BTNS			WH_5KEY_BTNS
	#define	PERI_DIRECTION_LIGHT	WH_DIRECTION_LIGHT
	#define	PERI_HEAD_LIGHT			WH_HEAD_LIGHT
	#define	PERI_TAIL_LIGHT			WH_TAIL_LIGHT
	#define	PERI_BLIND_SPOT			WH_BLIND_SPOT
	#define	PERI_ELEC_SHIFT			WH_ELEC_SHIFT
	#define	PERI_ELEC_LOCK			WH_ELEC_LOCK
	#define	PERI_DAUL_MOTOR			WH_DAUL_MOTOR
	#define PERI_TIRE_GAGE			WH_TIRE_GAGE

/**************************************************************
 *	customize function
 **************************************************************/
#define CUSTOMIZED_FN_WALK_MODE_ON_OFF	WH_WALK_MODE_ON_OFF

/**************************************************************
 *	customize function style type
 **************************************************************/
#define DIRECTION_DISPLAY_TYPE		WH_DIRECTION_TYPE

#endif

/*
 * console profile default value
 */
#define DEFAULT_CONSOLE_MODULE_NAME		"HeliosElite"
#define DEFAULT_CONSOLE_SW_CODE			"EMPTY"
#define DEFAULT_CONSOLE_SN				"EMPTY"
#define DEFAULT_CONSOLE_FW_VER			0
#define DEFAULT_CONSOLE_VENDER			"SINBON"
#define DEFAULT_CONSOLE_PRO_VER			0
#define DEFAULT_CONSOLE_PROD_DATE		"20220331"
#define DEFAULT_CONSOLE_MAC_ADR			0

/*
 * system parameter default
 */
#define DEFAULT_SYS_BLE_PWD				"666666"
#define DEFAULT_SYS_ASS_SPEED_LIMIT_EN	1			/* 0: no limit, 1: be limit */
#define DEFAULT_SYS_ASS_SPEED_LIMIT		2500 		/* unit:0.01km/hr */
#define DEFAULT_SYS_SUP_WALK_MODE		CUSTOMIZED_FN_WALK_MODE_ON_OFF
#define DEFAULT_SYS_ST_CURR_LIMIT_LV1	20
#define DEFAULT_SYS_ST_CURR_LIMIT_LV2	20
#define DEFAULT_SYS_ST_CURR_LIMIT_LV3	20
#define DEFAULT_SYS_ST_CURR_LIMIT_LV4	20
#define DEFAULT_SYS_CURR_LIMIT_LV1		30
#define DEFAULT_SYS_CURR_LIMIT_LV2		60
#define DEFAULT_SYS_CURR_LIMIT_LV3		90
#define DEFAULT_SYS_CURR_LIMIT_LV4		120
#define DEFAULT_SYS_WALK_PWR			90
#define DEFAULT_SYS_TORQUE_TO_START		600
#define DEFAULT_SYS_SIMPLE_PWD_EN		1
#define DEFAULT_SYS_SIMPLE_PWD			0x00000000 		/* 1st(left), 2st, 3st, 4st(right) */
#define DEFAULT_SYS_HOME_PAGE_MAMBER	0xFF
#define DEFAULT_SYS_TRIP_EVENT			3
#define DEFAULT_SYS_MOTOR_MAX_CURRENT	BIKE_MOTOR_CURR_MAX
#define DEFAULT_SYS_UNIT				0
#define DEFAULT_SYS_ACCESS_KEY			"SINBON"

#endif /* CONSOLE_CONFIG_BIKE_CONFIG_H_ */
