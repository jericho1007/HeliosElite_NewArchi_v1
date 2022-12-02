/*
 * wh_config.h
 *
 *  Created on: 2022年11月25日
 *      Author: JerichoLo
 */

#ifndef CONSOLE_CONFIG_CUSTOMER_WH_CONFIG_H_
#define CONSOLE_CONFIG_CUSTOMER_WH_CONFIG_H_

/**************************************************************
 *	select bike model
 **************************************************************/
#define WH_HE_E5_WHEU01				0
#define WH_HE_E5_WHEU01_DB_BS		1

/**************************************************************
 *	parameters default configure
 **************************************************************/
#if WH_HE_E5_WHEU01
	#define WH_DEFAULT_BIKE_MODULE_NAME	"Wheeler Bike"
#else
	#define WH_DEFAULT_BIKE_MODULE_NAME	"Wheeler Bike"
#endif
#define WH_DEFAULT_BIKE_SW_CODE			"EMPTY"
#define WH_DEFAULT_BIKE_SN				"EMPTY"
#define WH_DEFAULT_BIKE_FW_VER			0
#define WH_DEFAULT_BIKE_VENDER			"WHEELER"
#define WH_DEFAULT_BIKE_PRO_VER			0
#define WH_DEFAULT_BIKE_PROD_DATE		"20220331"

/**************************************************************
*	parameters configure
**************************************************************/
#define WH_CONSOLE_SW_CODE			"HE-E5-WHEU01"
#define WH_BIKE_MODULE_NAME			WH_DEFAULT_BIKE_MODULE_NAME
#define WH_BIKE_SW_CODE				WH_DEFAULT_BIKE_SW_CODE
#define WH_BIKE_SN					WH_DEFAULT_BIKE_SN
#define WH_BIKE_FW_VER				WH_DEFAULT_BIKE_FW_VER
#define WH_BIKE_VENDER				WH_DEFAULT_BIKE_VENDER
#define WH_BIKE_PRO_VER				WH_DEFAULT_BIKE_PRO_VER
#define WH_BIKE_PROD_DATE			WH_DEFAULT_BIKE_PROD_DATE

/**************************************************************
*	support base features
**************************************************************/
#define WH_WHEEL_DIAMETER			660		/* unit:mm */
#define WH_BIKE_WHEEL_CIRCLE		2215 	/* unit:mm */
#define WH_BIKE_MOTOR_CURRENT_MAX	16   	/* unit:A */

/**************************************************************
*	support option features
**************************************************************/
#if WH_HE_E5_WHEU01
	#define WH_DAUL_BATTERY				0
#else
	#define WH_DAUL_BATTERY				1
#endif
#define WH_3KEY_BTNS				0
#define	WH_5KEY_BTNS				1
#define	WH_DIRECTION_LIGHT			1
#define	WH_HEAD_LIGHT				1
#define	WH_TAIL_LIGHT				1
#define	WH_BLIND_SPOT				1
#define	WH_ELEC_SHIFT				0
#define	WH_ELEC_LOCK				0
#define	WH_DAUL_MOTOR				0
#define WH_TIRE_GAGE				0

/**************************************************************
 *	customize function
 **************************************************************/
#define WH_WALK_MODE_ON_OFF			1

/**************************************************************
 *	customize function style type
 **************************************************************/
/*
 * 0: independent page
 * 1: in front page
 * */
#define WH_DIRECTION_TYPE			1

#endif /* CONSOLE_CONFIG_CUSTOMER_WH_CONFIG_H_ */
