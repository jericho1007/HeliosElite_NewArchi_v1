/*
 * core_dictionary.c
 *
 *  Created on: 2022年11月28日
 *      Author: JerichoLo
 */
#include "core_dictionary.h"
#include "core_para_list.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
core_dictionary_t sysDictionary;

/*******************************************************************************
 * Code
 ******************************************************************************/
void CORE_InitDictionary(void)
{
	memset(&sysDictionary, 0, sizeof(core_dictionary_t));

	sysDictionary.console.id_0201.speedLimit 			= paraList.cache.item.L1L2.assistSpeedLimit;
	sysDictionary.console.id_0202.tripODO 				= paraList.cache.item.L1L2.tripODO;
	sysDictionary.console.id_0202.tripTime 				= paraList.cache.item.L1L2.tripTime;
	sysDictionary.console.id_0203.wheelDia 				= paraList.cache.item.L1L2.WheelDiameter;
	sysDictionary.console.id_0203.wheelCircumference 	= paraList.cache.item.L1L2.WheelCircumference;

	sysDictionary.console.id_0300.nowAssLv				= paraList.cache.item.L1L2.lastAssLv;
	sysDictionary.console.id_0300.tripEvent				= paraList.cache.item.L1L2.tripEvent;
	sysDictionary.console.id_0301.maintODO		 		= paraList.cache.item.L1L2.maintODO;
	sysDictionary.console.id_0301.tripID 				= paraList.cache.item.L1L2.tripID;

	sysDictionary.console.id_0302.totalODO 				= paraList.cache.item.L1L2.totalODO;
	sysDictionary.console.id_0302.totalTime 			= paraList.cache.item.L1L2.totalTime;

//	strcpy((char*)&sysDictionary.console.id_0305.accessKey0, (char*)DEFAULT_SYS_ACCESS_KEY);
}

void CORE_LinkBikeInfoToDictionary(void)
{
	sysDictionary.console.id_0201.controllerOutputCurrent = sysDictionary.controller.id_0200.realTimeCurrent;
}
