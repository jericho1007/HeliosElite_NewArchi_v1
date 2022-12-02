/*
 * ax_config.h
 *
 *  Created on: 2022年11月25日
 *      Author: JerichoLo
 */

#ifndef CONSOLE_CONFIG_CUSTOMER_AX_CONFIG_H_
#define CONSOLE_CONFIG_CUSTOMER_AX_CONFIG_H_

/**************************************************************
 *	select bike model
 **************************************************************/
#define AX_ROAD_HE_E3_AXTW01	1	/* red, double battery */
#define AX_CITY_HE_E3_AXTW02	0	/* blue, single battery */
#if((AX_ROAD_HE_E3_AXTW01 == 0) && (AX_CITY_HE_E3_AXTW02 == 0)) || ((AX_ROAD_HE_E3_AXTW01) && (AX_CITY_HE_E3_AXTW02))
	#define AX_ROAD_HE_E3_AXTW01	0
	#define AX_CITY_HE_E3_AXTW02	1
#endif

/**************************************************************
 *	parameters default configure
 **************************************************************/
#if AX_ROAD_HE_E3_AXTW01
	#define AX_DEFAULT_BIKE_MODULE_NAME	"Axman Road"
#elif AX_CITY_HE_E3_AXTW02
	#define AX_DEFAULT_BIKE_MODULE_NAME	"Axman City"
#endif
#define AX_DEFAULT_BIKE_SW_CODE			"EMPTY"
#define AX_DEFAULT_BIKE_SN				"EMPTY"
#define AX_DEFAULT_BIKE_FW_VER			0
#define AX_DEFAULT_BIKE_VENDER			"AXMAN"
#define AX_DEFAULT_BIKE_PRO_VER			0
#define AX_DEFAULT_BIKE_PROD_DATE		"20220331"

/**************************************************************
*	parameters configure
**************************************************************/
#if AX_ROAD_HE_E3_AXTW01
	#define AX_CONSOLE_SW_CODE			"HE-E3-AXTW01"
	#define AX_BIKE_MODULE_NAME			AX_DEFAULT_BIKE_MODULE_NAME
	#define AX_BIKE_SW_CODE				AX_DEFAULT_BIKE_SW_CODE
#elif AX_CITY_HE_E3_AXTW02
	#define AX_CONSOLE_SW_CODE			"HE-E3-AXTW02"
	#define AX_BIKE_MODULE_NAME			AX_DEFAULT_BIKE_MODULE_NAME
	#define AX_BIKE_SW_CODE				AX_DEFAULT_BIKE_SW_CODE
#endif
	#define AX_BIKE_SN					AX_DEFAULT_BIKE_SN
	#define AX_BIKE_FW_VER				AX_DEFAULT_BIKE_FW_VER
	#define AX_BIKE_VENDER				AX_DEFAULT_BIKE_VENDER
	#define AX_BIKE_PRO_VER				AX_DEFAULT_BIKE_PRO_VER
	#define AX_BIKE_PROD_DATE			AX_DEFAULT_BIKE_PROD_DATE

/**************************************************************
*	support base features
**************************************************************/
#define AX_WHEEL_DIAMETER				660		/* unit:mm */
#define AX_BIKE_WHEEL_CIRCLE			2136 	/* unit:mm */
#define AX_BIKE_MOTOR_CURRENT_MAX		15   	/* unit:A */

/**************************************************************
*	support option features
**************************************************************/
#if AX_ROAD_HE_E3_AXTW01
	#define AX_DAUL_BATTERY				1
#elif AX_CITY_HE_E3_AXTW02
	#define AX_DAUL_BATTERY				0
#endif
#define AX_3KEY_BTNS				1
#define	AX_5KEY_BTNS				0
#define	AX_DIRECTION_LIGHT			0
#define	AX_HEAD_LIGHT				1
#define	AX_TAIL_LIGHT				0
#define	AX_BLIND_SPOT				0
#define	AX_ELEC_SHIFT				0
#define	AX_ELEC_LOCK				0
#define	AX_DAUL_MOTOR				0
#define AX_TIRE_GAGE				0

/**************************************************************
 *	customize function
 **************************************************************/
#define AX_WALK_MODE_ON_OFF			1

/**************************************************************
 *	customize function style type
 **************************************************************/
/*
 * 0: independent page
 * 1: in front page
 * */
#define AX_DIRECTION_TYPE			0

#endif /* CONSOLE_CONFIG_CUSTOMER_AX_CONFIG_H_ */
