/*
 * core_para_list.c
 *
 *  Created on: 2022年11月24日
 *      Author: JerichoLo
 */
#include "core_para_list.h"
#include "driver_nvm.h"
#include "bike_config.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static core_fw_state_t PLIST_CheckConsoleFwVer(void);
static void PLIST_ApplyDefaultConfig(void);
static bool PLIST_CheckKeyParaScope(void);
static void PLIST_GetBootLoaderVer(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
core_para_list_t paraList;

/*******************************************************************************
 * Code
 ******************************************************************************/
void PLIST_Init(void)
{
	memset(&paraList, 0, sizeof(core_para_list_t));
	PLIST_ReadList();
	switch(PLIST_CheckConsoleFwVer())
	{
		case kcore_fw_state_empty:
			PLIST_ApplyDefaultConfig();
		case kcore_fw_state_diff:
			paraList.cache.item.L0.console.firmwareVer[0] = FW_VERSION_CONSOLE_MAIN;
			paraList.cache.item.L0.console.firmwareVer[1] = FW_VERSION_CONSOLE_SUB;
			paraList.cache.item.L0.console.firmwareVer[2] = FW_VERSION_CONSOLE_RELEASE;
			paraList.cache.item.L0.console.firmwareVer[3] = FW_VERSION_CONSOLE_DEBUG;

			paraList.cache.item.L0.console.protocolVer[0] = PROTOCOL_VERSION_MAIN;
			paraList.cache.item.L0.console.protocolVer[1] = PROTOCOL_VERSION_SUB;
			paraList.cache.item.L0.console.protocolVer[2] = PROTOCOL_VERSION_RELEASE;
			paraList.cache.item.L0.console.protocolVer[3] = PROTOCOL_VERSION_DEBUG;
			paraList.reqRestore = true;
			break;
		default:
			break;
	}
	if(PLIST_CheckKeyParaScope() || paraList.reqRestore)
	{
		PLIST_RestoreList();
		paraList.reqRestore = false;
	}
	PLIST_GetBootLoaderVer();

}

static void PLIST_GetBootLoaderVer(void)
{
	uint8_t buff[8] = {0};

	NVM_ReadFlash(buff, (PARA_BOOT_LOADER_START_ADDR + PARA_BOOT_LOADER_FW_VER_ADDR_OFFSET), 8, false);
	paraList.consoleBootLoaderVer.main		= buff[2];
	paraList.consoleBootLoaderVer.sub		= buff[3];
	paraList.consoleBootLoaderVer.release	= buff[4];
	paraList.consoleBootLoaderVer.debug		= buff[5];
}

static bool PLIST_CheckKeyParaScope(void)
{
	uint8_t changes = 0;
	/*
	 *  only check item value's scope, because 0xFF must be checked by PLIST_CheckConsoleFwVer()
	 *  because NVM erase, write and read are operated by sector
	 * */
	if(paraList.cache.item.L1L2.sysAutoSleepTime > PARA_LIST_SCOPE_AUTO_SLEEP_MAX)
	{
		paraList.cache.item.L1L2.sysAutoSleepTime = PARA_LIST_SCOPE_AUTO_SLEEP_MAX;
		changes++;
	}

	if(paraList.cache.item.L1L2.WheelDiameter == 0)
	{
		paraList.cache.item.L1L2.WheelDiameter = BIKE_WHEEL_DIAMETER;
		changes++;
	}

	if(paraList.cache.item.L1L2.WheelCircumference == 0)
	{
		paraList.cache.item.L1L2.WheelCircumference = WH_BIKE_WHEEL_CIRCLE;
		changes++;
	}

	if(paraList.cache.item.L1L2.manualDispBright > PARA_LIST_SCOPE_BRIGHT_LV_MAX)
	{
		paraList.cache.item.L1L2.manualDispBright = PARA_LIST_SCOPE_BRIGHT_LV_MAX;
		changes++;
	}

	if(paraList.cache.item.L1L2.lastAssLv > PARA_LIST_SCOPE_BRIGHT_LV_MAX)
	{
		paraList.cache.item.L1L2.lastAssLv = PARA_LIST_SCOPE_BRIGHT_LV_MAX;
		changes++;
	}

	if(paraList.cache.item.L1L2.currentLimitLv1 > DEFAULT_SYS_CURR_LIMIT_LV1)
	{
		paraList.cache.item.L1L2.currentLimitLv1 = DEFAULT_SYS_CURR_LIMIT_LV1;
		changes++;
	}

	if(paraList.cache.item.L1L2.currentLimitLv2 > DEFAULT_SYS_CURR_LIMIT_LV2)
	{
		paraList.cache.item.L1L2.currentLimitLv2 = DEFAULT_SYS_CURR_LIMIT_LV2;
		changes++;
	}

	if(paraList.cache.item.L1L2.currentLimitLv3 > DEFAULT_SYS_CURR_LIMIT_LV3)
	{
		paraList.cache.item.L1L2.currentLimitLv3 = DEFAULT_SYS_CURR_LIMIT_LV3;
		changes++;
	}

	if(paraList.cache.item.L1L2.currentLimitLv4 > DEFAULT_SYS_CURR_LIMIT_LV4)
	{
		paraList.cache.item.L1L2.currentLimitLv4 = DEFAULT_SYS_CURR_LIMIT_LV4;
		changes++;
	}

	if(paraList.cache.item.L1L2.startCurrentLimitLv1 > DEFAULT_SYS_ST_CURR_LIMIT_LV1)
	{
		paraList.cache.item.L1L2.startCurrentLimitLv1 = DEFAULT_SYS_ST_CURR_LIMIT_LV1;
		changes++;
	}

	if(paraList.cache.item.L1L2.startCurrentLimitLv2 > DEFAULT_SYS_ST_CURR_LIMIT_LV2)
	{
		paraList.cache.item.L1L2.startCurrentLimitLv2 = DEFAULT_SYS_ST_CURR_LIMIT_LV2;
		changes++;
	}

	if(paraList.cache.item.L1L2.startCurrentLimitLv3 > DEFAULT_SYS_ST_CURR_LIMIT_LV3)
	{
		paraList.cache.item.L1L2.startCurrentLimitLv3 = DEFAULT_SYS_ST_CURR_LIMIT_LV3;
		changes++;
	}

	if(paraList.cache.item.L1L2.startCurrentLimitLv4 > DEFAULT_SYS_ST_CURR_LIMIT_LV4)
	{
		paraList.cache.item.L1L2.startCurrentLimitLv4 = DEFAULT_SYS_ST_CURR_LIMIT_LV4;
		changes++;
	}

	if(paraList.cache.item.L1L2.walkPower > PARA_LIST_SCOPE_WALK_PWR)
	{
		paraList.cache.item.L1L2.walkPower = PARA_LIST_SCOPE_WALK_PWR;
		changes++;
	}

	if(paraList.cache.item.L1L2.torqueToStart > PARA_LIST_SCOPE_TORQUE_TO_START)
	{
		paraList.cache.item.L1L2.torqueToStart = PARA_LIST_SCOPE_TORQUE_TO_START;
		changes++;
	}

	if(paraList.cache.item.L1L2.simplePWD.num0 > PARA_LIST_SCOPE_KEY_MAPPING_VALUE_MAX)
	{
		paraList.cache.item.L1L2.simplePWD.num0 = DEFAULT_SYS_SIMPLE_PWD>>24;
		paraList.cache.item.L1L2.simplePWD.num1 = DEFAULT_SYS_SIMPLE_PWD>>16;
		paraList.cache.item.L1L2.simplePWD.num2 = DEFAULT_SYS_SIMPLE_PWD>>8;
		paraList.cache.item.L1L2.simplePWD.num3 = DEFAULT_SYS_SIMPLE_PWD & 0xFF;
		changes++;
	}

	if(paraList.cache.item.L1L2.homePageMember < PARA_LIST_SCOPE_HOME_PAGE_MEM_MIN)
	{
		paraList.cache.item.L1L2.homePageMember = PARA_LIST_SCOPE_HOME_PAGE_MEM_MAX;
		changes++;
	}

	if(paraList.cache.item.L1L2.motorCurrentMax > BIKE_MOTOR_CURR_MAX)
	{
		paraList.cache.item.L1L2.motorCurrentMax = BIKE_MOTOR_CURR_MAX;
		changes++;
	}

	if(paraList.cache.item.L1L2.simplePWDFailCount > PARA_LIST_SCOPE_SIM_PWD_FAIL_CNT_MAX)
	{
		paraList.cache.item.L1L2.simplePWDFailCount = PARA_LIST_SCOPE_SIM_PWD_FAIL_CNT_MAX;
		changes++;
	}

	return (changes > 0);
}

static void PLIST_ApplyDefaultConfig(void)
{
	/* L0-console */
	memcpy(paraList.cache.item.L0.console.moduleName, 	(uint8_t*)CONSOLE_MODULE_NAME, strlen((char*)CONSOLE_MODULE_NAME));
	memcpy(paraList.cache.item.L0.console.swCode, 		(uint8_t*)CONSOLE_MODULE_NAME, strlen((char*)CONSOLE_SW_CODE));
	memcpy(paraList.cache.item.L0.console.serialNum, 	(uint8_t*)CONSOLE_MODULE_NAME, strlen((char*)CONSOLE_SN));
	memcpy(paraList.cache.item.L0.console.vender, 		(uint8_t*)CONSOLE_MODULE_NAME, strlen((char*)CONSOLE_VENDER));
	memcpy(paraList.cache.item.L0.console.productDate, 	(uint8_t*)CONSOLE_MODULE_NAME, strlen((char*)CONSOLE_PROD_DATE));

	/* L0-bike */
	memcpy(paraList.cache.item.L0.bike.moduleName, 		(uint8_t*)CONSOLE_MODULE_NAME, strlen((char*)BIKE_MODULE_NAME));
	memcpy(paraList.cache.item.L0.bike.swCode, 			(uint8_t*)CONSOLE_MODULE_NAME, strlen((char*)BIKE_SW_CODE));
	memcpy(paraList.cache.item.L0.bike.serialNum, 		(uint8_t*)CONSOLE_MODULE_NAME, strlen((char*)BIKE_SN));
	memcpy(paraList.cache.item.L0.bike.vender, 			(uint8_t*)CONSOLE_MODULE_NAME, strlen((char*)BIKE_VENDER));
	memcpy(paraList.cache.item.L0.bike.productDate, 	(uint8_t*)CONSOLE_MODULE_NAME, strlen((char*)BIKE_PROD_DATE));

	/* system parameters */
	memcpy(paraList.cache.item.L1L2.bleName, 			(uint8_t*)BIKE_MODULE_NAME, 	strlen((char*)BIKE_MODULE_NAME));
	memcpy(paraList.cache.item.L1L2.blePairCode, 		(uint8_t*)DEFAULT_SYS_BLE_PWD, 	strlen((char*)DEFAULT_SYS_BLE_PWD));
	paraList.cache.item.L1L2.assistSpeedLimitEn		= DEFAULT_SYS_ASS_SPEED_LIMIT_EN;
	paraList.cache.item.L1L2.assistSpeedLimit		= DEFAULT_SYS_ASS_SPEED_LIMIT;
	paraList.cache.item.L1L2.supWalkMode			= DEFAULT_SYS_SUP_WALK_MODE;
	paraList.cache.item.L1L2.startCurrentLimitLv1	= DEFAULT_SYS_ST_CURR_LIMIT_LV1;
	paraList.cache.item.L1L2.startCurrentLimitLv2	= DEFAULT_SYS_ST_CURR_LIMIT_LV2;
	paraList.cache.item.L1L2.startCurrentLimitLv3	= DEFAULT_SYS_ST_CURR_LIMIT_LV3;
	paraList.cache.item.L1L2.startCurrentLimitLv4	= DEFAULT_SYS_ST_CURR_LIMIT_LV4;
	paraList.cache.item.L1L2.currentLimitLv1		= DEFAULT_SYS_CURR_LIMIT_LV1;
	paraList.cache.item.L1L2.currentLimitLv2		= DEFAULT_SYS_CURR_LIMIT_LV2;
	paraList.cache.item.L1L2.currentLimitLv3		= DEFAULT_SYS_CURR_LIMIT_LV3;
	paraList.cache.item.L1L2.currentLimitLv4		= DEFAULT_SYS_CURR_LIMIT_LV4;
	paraList.cache.item.L1L2.walkPower				= DEFAULT_SYS_WALK_PWR;
	paraList.cache.item.L1L2.torqueToStart			= DEFAULT_SYS_TORQUE_TO_START;
	paraList.cache.item.L1L2.simplePWDEn			= DEFAULT_SYS_SIMPLE_PWD_EN;
	paraList.cache.item.L1L2.homePageMember			= DEFAULT_SYS_HOME_PAGE_MAMBER;
	paraList.cache.item.L1L2.tripEvent				= DEFAULT_SYS_TRIP_EVENT;
	paraList.cache.item.L1L2.motorCurrentMax		= DEFAULT_SYS_MOTOR_MAX_CURRENT;
	paraList.cache.item.L1L2.dispUnit				= DEFAULT_SYS_UNIT;
}

static core_fw_state_t PLIST_CheckConsoleFwVer(void)
{
	core_fw_state_t state = kcore_fw_state_empty;
	uint8_t index;

	for(index = 0; index < 16; index++)
	{
		if(paraList.cache.item.L0.console.firmwareVer[index] != 0xFF)
		{
			if(paraList.cache.item.L0.console.firmwareVer[0] != FW_VERSION_CONSOLE_MAIN 	||
			   paraList.cache.item.L0.console.firmwareVer[1] != FW_VERSION_CONSOLE_SUB 		||
			   paraList.cache.item.L0.console.firmwareVer[2] != FW_VERSION_CONSOLE_RELEASE 	||
			   paraList.cache.item.L0.console.firmwareVer[3] != FW_VERSION_CONSOLE_DEBUG)
			{
				state = kcore_fw_state_diff;
			}
			else
			{
				state = kcore_fw_state_same;
			}
			break;
		}
	}

	return state;
}

bool PLIST_RestoreList(void)
{
	bool result = false;

	if(NVM_EraseSector(PARA_LIST_START_ADDR, 1))
	{
		result = NVM_WriteFlash(paraList.cache.buff, PARA_LIST_START_ADDR, PARA_LIST_SIZE, true);
	}

	return result;
}

void PLIST_ReadList(void)
{
	NVM_ReadFlash(paraList.cache.buff, PARA_LIST_START_ADDR, PARA_LIST_SIZE, true);
}

