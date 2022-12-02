/*
 * core_para_list.h
 *
 *  Created on: 2022年11月24日
 *      Author: JerichoLo
 */

#ifndef CONSOLE_CORE_CORE_PARA_LIST_H_
#define CONSOLE_CORE_CORE_PARA_LIST_H_
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define PARA_BOOT_LOADER_START_ADDR			0x7D000
#define PARA_BOOT_LOADER_FW_VER_ADDR_OFFSET	4
#define PARA_LIST_SIZE						1024
#define PARA_LIST_START_ADDR				0x7C800
#define PARA_LIST_L0_RESERVE_SIZE			296
#define PARA_LIST_L1L2_RESERVE_SIZE			380
#define PARA_LIST_SCOPE_AUTO_SLEEP_MAX		600		/* unit:s */

/* system parameter scope */
#define PARA_LIST_SCOPE_BRIGHT_LV_MAX				8
#if SYS_SUP_AUTO_MODE
	#define PARA_LIST_SCOPE_ASS_LV_MAX			5
#else
	#define PARA_LIST_SCOPE_ASS_LV_MAX			4
#endif
#define PARA_LIST_SCOPE_WALK_PWR					640
#define PARA_LIST_SCOPE_TORQUE_TO_START				1100
#if SYS_SUP_MOTION_KEY
	#define PARA_LIST_SCOPE_KEY_MAPPING_VALUE_MAX	0x0E
#else
	#define PARA_LIST_SCOPE_KEY_MAPPING_VALUE_MAX	9
#endif
#define PARA_LIST_SCOPE_HOME_PAGE_MEM_MIN			0x01
#define PARA_LIST_SCOPE_HOME_PAGE_MEM_MAX			0xFF
#define PARA_LIST_SCOPE_SIM_PWD_FAIL_CNT_MAX		3

typedef enum _core_fw_state {
	kcore_fw_state_none = 0,
	kcore_fw_state_empty,
	kcore_fw_state_same,
	kcore_fw_state_diff
}core_fw_state_t;

typedef struct _core_firmware_format {
	uint8_t main;
	uint8_t sub;
	uint8_t release;
	uint8_t debug;
	uint32_t commit;
}core_firmware_format_t;

typedef struct _core_profile_format {
	char moduleName[16];
	char swCode[16];
	char serialNum[16];
	uint8_t firmwareVer[16];
	char vender[16];
	uint8_t protocolVer[16];
	char productDate[8];
}core_profile_format_t;

typedef struct _core_para_list {
	bool reqRestore;
	core_firmware_format_t consoleBootLoaderVer;
	struct {
		union {
			struct {
				struct {
					core_profile_format_t console;
					core_profile_format_t bike;
					uint8_t bleMACAddr[8];
					uint8_t reserved[PARA_LIST_L0_RESERVE_SIZE];
				}L0;
				struct {
					char bleName[16];
					char blePairCode[8];
					uint16_t sysAutoSleepTime;
					uint16_t lcdAutoSleepTime;
					uint16_t WheelDiameter;
					uint16_t WheelCircumference;
					uint32_t totalODO;
					uint32_t totalTime;
					uint32_t maintODO;
					uint32_t tripODO;
					uint32_t tripTime;
					uint16_t assistSpeedLimit;
					uint8_t assistSpeedLimitEn;
					uint8_t supWalkMode;
					uint32_t tripStartODO;
					uint32_t tripStartTime;
					uint8_t manualDispBright;
					uint8_t autoDispBrightEn;
					uint8_t autoDispBrightPct1;
					uint8_t autoDispBrightPct2;
					uint16_t autoDispBrightTime1;
					uint16_t autoDispBrightTime2;
					uint8_t storeLastAssLvEn;
					uint8_t lastAssLv;
					uint8_t storeLastHeadLightEn;
					uint8_t lastHeadLightState;
					uint8_t lastAssMode;
					uint8_t smartBoosting;
					uint8_t dispUnit;
					uint8_t torqueRatioLv1;
					uint8_t torqueRatioLv2;
					uint8_t torqueRatioLv3;
					uint8_t torqueRatioLv4;
					uint8_t speedRatioLv1;
					uint8_t speedRatioLv2;
					uint8_t speedRatioLv3;
					uint8_t speedRatioLv4;
					uint8_t currentLimitLv1;
					uint8_t currentLimitLv2;
					uint8_t currentLimitLv3;
					uint8_t currentLimitLv4;
					uint8_t startCurrentLimitLv1;
					uint8_t startCurrentLimitLv2;
					uint8_t startCurrentLimitLv3;
					uint8_t startCurrentLimitLv4;
					uint8_t blePBondNvmIndex;
					uint16_t walkPower;
					uint16_t torqueToStart;
					union {
						struct{
							uint8_t num0;
							uint8_t num1;
							uint8_t num2;
							uint8_t num3;
						};
						uint8_t whole[4];
					}simplePWD;
					uint8_t simplePWDEn;
					uint8_t homePageMember;
					uint8_t tripID;
					uint8_t tripEvent;
					uint8_t bleNextPBondAddr;
					uint8_t bleCBondNvmIndex;
					uint8_t bleNextCBondAddr;
					uint8_t motorCurrentMax;
					int8_t slopeOffset;
					uint8_t btnVol;
					uint8_t ladarAlarmVol;
					uint8_t ecoBattLow;
					uint8_t climbSlopeLow;
					uint8_t climbSlopeMid;
					uint8_t climbSlopeHigh;
					uint8_t climbSpeed;
					uint16_t norTorqueThreshold;
					uint8_t norSpeedMid;
					uint8_t norSpeedHigh;
					uint32_t timeZone;
					char countryCode[3];
					uint8_t simplePWDFailCount;
					uint8_t reserved[PARA_LIST_L1L2_RESERVE_SIZE];
				}L1L2;
			}item;
			uint8_t buff[PARA_LIST_SIZE];
		};
	}cache;
}core_para_list_t;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void PLIST_Init(void);
bool PLIST_RestoreList(void);
void PLIST_ReadList(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
extern core_para_list_t paraList;

#endif /* CONSOLE_CORE_CORE_PARA_LIST_H_ */
