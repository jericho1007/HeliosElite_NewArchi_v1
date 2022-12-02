/*
 * core_dictionary.h
 *
 *  Created on: 2022年11月28日
 *      Author: JerichoLo
 */

#ifndef CONSOLE_CORE_CORE_DICTIONARY_H_
#define CONSOLE_CORE_CORE_DICTIONARY_H_
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef enum _bike_unit_code {
	kbike_unit_code_none = 0,
	kbike_unit_code_console_bootloader,
	kbike_unit_code_console_app,
	kbike_unit_code_controller_bootloader,
	kbike_unit_code_controller_app,
	kbike_unit_code_battery_cpp,
	kbike_unit_code_remote_5key_bootloader,
	kbike_unit_code_remote_5key_app
}bike_unit_code_t;

typedef struct _core_dictionary {
	struct {
		struct {
			uint8_t reserveB0;
			uint16_t wheelTimeToCycle; /* the time of turn around */
			uint16_t realTimeCurrent;
			uint8_t errCode;
		}id_0200;
		struct {
			uint16_t torque;
			uint8_t cadence;
			uint8_t reserveB3;
			uint8_t reserveB4;
			uint8_t reserveB5;
			uint8_t reserveB6;
			uint8_t reserve70;
		}id_0202;
		struct {
			uint8_t controllerModel0;
			uint8_t controllerModel1;
			uint8_t controllerModel2;
			uint8_t controllerModel3;
			uint8_t controllerModel4;
			uint8_t controllerModel5;
			uint8_t controllerModel6;
			uint8_t controllerModel7;
		}id_0221;
		struct {
			uint8_t controllerSN0;
			uint8_t controllerSN1;
			uint8_t controllerSN2;
			uint8_t controllerSN3;
			uint8_t controllerSN4;
			uint8_t controllerSN5;
			uint8_t controllerSN6;
			uint8_t controllerSN7;
		}id_0222;
		struct {
			uint8_t controllerSN8;
			uint8_t controllerSN9;
			uint8_t controllerSN10;
			uint8_t controllerSN11;
			uint8_t controllerSN12;
			uint8_t controllerSN13;
			uint8_t controllerSN14;
			uint8_t controllerSN15;
		}id_0223;
		struct {
			uint8_t profileVender0;
			uint8_t profileVender1;
			uint8_t profileVender2;
			uint8_t profileVender3;
			uint8_t profileVender4;
			uint8_t profileVender5;
			uint8_t profileVender6;
			uint8_t profileVender7;
		}id_0224;
		struct {
			uint8_t profileProdDate_Y0;
			uint8_t profileProdDate_Y1;
			uint8_t profileProdDate_Y2;
			uint8_t profileProdDate_Y3;
			uint8_t profileProdDate_M0;
			uint8_t profileProdDate_M1;
			uint8_t profileProdDate_D0;
			uint8_t profileProdDate_D1;
		}id_0225;
		struct {
			uint8_t motorSN0;
			uint8_t motorSN1;
			uint8_t motorSN2;
			uint8_t motorSN3;
			uint8_t motorSN4;
			uint8_t motorSN5;
			uint8_t motorSN6;
			uint8_t motorSN7;
		}id_0226;
		struct {
			uint8_t profileFWVer0;
			uint8_t profileFWVer1;
			uint8_t profileFWVer2;
			uint8_t profileFWVer3;
			uint8_t profileFWVer4;
			uint8_t profileFWVer5;
			uint8_t profileFWVer6;
			uint8_t profileFWVer7;
		}id_0227;
		struct {
			uint8_t reserveB0b0:1;
			uint8_t reserveB0b1:1;
			uint8_t lightHead:1;
			uint8_t walkFnEn:1;
			uint8_t sysCtrlMode:1;
			uint8_t throttleFn:2;
			uint8_t assSpeedLimitEn:1;
			uint8_t assLv;
			uint8_t wheelCircumference;
			uint8_t assSpeedLimit;
			uint8_t throttleSpeedLimit;
			uint8_t sendProfile;
		}id_0300;
		struct {
			uint8_t torqueRatioLv1;
			uint8_t torqueRatioLv2;
			uint8_t torqueRatioLv3;
			uint8_t torqueRatioLv4;
			uint8_t speedRatioLv1;
			uint8_t speedRatioLv2;
			uint8_t speedRatioLv3;
			uint8_t speedRatioLv4;
		}id_0341;
		struct {
			uint8_t currentLimitLv1;
			uint8_t currentLimitLv2;
			uint8_t currentLimitLv3;
			uint8_t currentLimitLv4;
			uint8_t startCurrentLimitLv1;
			uint8_t startCurrentLimitLv2;
			uint8_t startCurrentLimitLv3;
			uint8_t startCurrentLimitLv4;
		}id_0342;
		struct {
			uint8_t walkPwrL;
			uint8_t walKPwrH;
			uint8_t startToTorqueL;
			uint8_t startToTorqueH;
			uint8_t reserveB2;
			uint8_t reserveB3;
			uint8_t reserveB4;
			uint8_t reserveB5;
			uint8_t reserveB6;
			uint8_t reserveB7;
		}id_0343;
		struct {
			uint8_t resetSleepFlag:1;	/* 0:no reset, 1:reset */
			uint8_t reserveB0b1;
			uint8_t reserveB0b2;
			uint8_t reserveB0b3;
			uint8_t reserveB0b4;
			uint8_t reserveB0b5;
			uint8_t reserveB0b6;
			uint8_t reserveB0b7;
			uint8_t reserveB1;
			uint8_t reserveB2;
			uint8_t reserveB3;
			uint8_t reserveB4;
			uint8_t reserveB5;
			uint8_t reserveB6;
			uint8_t reserveB7;
		}id_0351;
	}controller;

	struct {
		struct {
			uint32_t voltage;
			int32_t workCurrent;
		}id_0401;
		struct {
			uint8_t BattPercentage;
			uint8_t fullCharged:1;
			uint8_t reCharge:1;
			uint8_t chargerDetectd:1;
			uint8_t reserveB1b3:1;
			uint8_t reserveB1b4:1;
			uint8_t reserveB1b5:1;
			uint8_t reserveB1b6:1;
			uint8_t reserveB1b7:1;
			uint8_t reserveB2;
			uint8_t reserveB3;
			uint32_t remainingCapacity;
		}id_0402;
		struct {
			uint8_t soh;
			uint8_t reserveB1;
			uint8_t reserveB2;
			uint8_t reserveB3;
			uint32_t fullCapacity;
		}id_0403;
		struct {
			uint8_t reserveB0;
			uint8_t reserveB1;
			uint16_t temperture;
			uint8_t reserveB4;
			uint8_t reserveB5;
			uint8_t reserveB6;
			uint8_t reserveB7;
		}id_0404;
		struct {
			uint8_t errCode0;
			uint8_t errCode1;
		}id_0405;
		struct {
			uint16_t cycleCount;
			uint16_t maxUnchargeTime;
			uint16_t recentUnchargeTime;
		}id_0411;
		struct {
			uint16_t subBattCell1;
			uint16_t subBattCell2;
			uint16_t subBattCell3;
			uint16_t subBattCell4;
		}id_0412;
		struct {
			uint16_t subBattCell5;
			uint16_t subBattCell6;
			uint16_t subBattCell7;
			uint16_t subBattCell8;
		}id_0413;
		struct {
			uint16_t subBattCell9;
			uint16_t subBattCell10;
			uint16_t subBattCell11;
			uint16_t subBattCell12;
		}id_0414;
		struct {
			uint16_t subBattCell13;
			uint16_t subBattCell14;
			uint16_t subBattCell15;
			uint16_t subBattCell16;
		}id_0415;
		struct {
			uint8_t battVerMain;
			uint8_t battVerSub;
			uint8_t battVerRelease;
		}id_0420;
	}battery;

	struct {
		struct {
			uint32_t paraAddr;
			uint32_t paraLength;
		}id_0101;
		struct {
			uint32_t flashAddr;
			uint32_t flashLength;
		}id_0102;
		struct {
			uint8_t targerUnitCode;	/* bike_unit_code_t */
			uint8_t fwVer_main;
			uint8_t fwVer_sub;
			uint8_t fwVer_release;
			uint8_t fwVer_debug;
		}id_0103;
		struct {
			uint8_t targetUnitCode;	/* bike_unit_code_t */
			uint8_t fwVer_main;
			uint8_t fwVer_sub;
			uint8_t fwVer_release;
			uint8_t fwVer_debug;
			uint8_t reqState;		/* 0:reject, 1:agree */
		}id_0104;
//		struct {
//
//		}id_0105;
		struct {
			uint8_t fileChecksum;
			uint8_t consoleRecvChecksum;
			uint8_t fileDownloadResult;
		}id_0106;
//		struct {
//
//		}id_0107;
		struct {
			uint8_t updateState;
		}id_0108;
		struct {
			uint8_t totalPackage_HH;	/* MSB */
			uint8_t totalPackage_HL;
			uint8_t totalPackage_LH;
			uint8_t totalPackage_LL;	/* LSB */
		}id_010A;
		struct {
			uint8_t segmentNum;
			uint8_t segmentCrc;
			uint8_t verifyResult;
		}id_010B;
		struct {
			uint8_t errCode0;
			uint8_t errCode1;
			uint8_t errCode2;
			uint8_t errCode3;
			uint8_t errCode4;
			uint8_t errCode5;
			uint8_t errCode6;
			uint8_t errCode7;
		}id_0119;
		struct {
			uint8_t errCode0;
			uint8_t errCode1;
			uint8_t errCode2;
			uint8_t errCode3;
			uint8_t errCode4;
			uint8_t errCode5;
			uint8_t errCode6;
			uint8_t errCode7;
		}id_0120;
		struct {
			uint8_t reqState;		/* 0:erase, 1:agree, 2:pause*/
			uint8_t uploadResult;
			uint8_t filePackage1;
			uint8_t filePackage2;
			uint8_t filePackage3;
		}id_012E;
		struct {
			uint8_t reqState;		/* 0:erase, 1:agree, 2:pause*/
			uint8_t uploadResult;
		}id_012F;
		struct {
			uint8_t offLineTripReset:1;
			uint8_t offLineUnlock:1;
			uint8_t offLineLightLeft:1;
			uint8_t offLineLightTail:1;
			uint8_t offLineLightRight:1;
			uint8_t offLineLightHead:1;
			uint8_t offLineBoostMode:1;
			uint8_t offLineWalkMode:1;
			uint8_t offLineTripEvent:4;
			uint8_t offLineNowAssLv:4;
			uint8_t offLineSlope;
			uint8_t offLineCadence;
			uint8_t offLineControllerRSOCCtrl;
			uint8_t offLineControllerTempCtrl;
			uint8_t offLineMotorTemp;
			uint8_t offLineBattRSOC;
		}id_0130;
		struct {
			uint8_t offLineBattTemp;
			uint8_t offLineTripID;
			uint16_t offLineMaxSpeed;
			uint16_t offLineAvdSpeed;
			uint16_t offLineSpeed;
		}id_0131;
		struct {
			uint16_t torque;
			uint16_t controllerCurrent;
			uint16_t controllerVoltage;
			uint16_t battCurrent;
		}id_0132;
		struct {
			uint16_t battVoltage;
			uint8_t reserve1;
			uint8_t reserve2;
			uint32_t timeStamp;
		}id_0133;
		struct {
			uint32_t totalODO;
			uint32_t totalTime;
		}id_0134;
		struct {
			uint32_t tripODO;
			uint32_t tripTime;
		}id_0135;
		struct {
			uint8_t errSrc0;
			uint8_t errCode0;
			uint8_t errSrc1;
			uint8_t errCode1;
			uint8_t errSrc2;
			uint8_t errCode2;
			uint8_t errSrc3;
			uint8_t errCode3;
		}id_0136;
		struct {
			uint8_t reserve0;
			uint8_t reserve1;
			uint8_t reserve2;
			uint8_t reserve3;
			uint8_t reserve4;
			uint8_t reserve5;
			uint8_t reserve6;
			uint8_t structureCRC;
		}id_0137;
		struct {
			uint8_t periList1;
			uint8_t periList2;
			uint8_t periList3;
			uint8_t periList4;
			uint8_t periList5;
			uint8_t periList6;
			uint8_t periList7;
			uint8_t periList8;
		}id_0150;
		struct {
			uint8_t periAliveList1;
			uint8_t periAliveList2;
			uint8_t periAliveList3;
			uint8_t periAliveList4;
			uint8_t periAliveList5;
			uint8_t periAliveList6;
			uint8_t periAliveList7;
			uint8_t periAliveList8;
		}id_0151;
		struct {
			uint8_t sysDiaDetectBtn;
			uint8_t reserve1;
			uint8_t reserve2;
			uint8_t reserve3;
			uint8_t reserve4;
			uint8_t reserve5;
			uint8_t reserve6;
			uint8_t reserve7;
		}id_0152;
		struct {
			uint16_t speed;
			uint16_t torque;		/* need filter */
			uint8_t cadence;		/* need filter */
			uint8_t reserveB3;
			uint8_t controllerTemp;	/* DAPU no support */
			uint8_t motorTemp;		/* DAPU no support */
		}id_0200;
		struct {
			uint16_t controllerOutputCurrent;	/* link from controller */
			uint16_t controllerInputVoltage;	/* no used */
			uint16_t speedLimit;				/* by para list */
			uint8_t reserveB6;
			uint8_t reserveB7;
		}id_0201;
		struct {
			uint32_t tripODO;					/* resume need keep */
			uint32_t tripTime;					/* resume need keep */
		}id_0202;
		struct {
			uint16_t wheelDia;					/* by para list */
			uint16_t wheelCircumference;		/* by para list */
		}id_0203;
		struct {
			uint8_t nowAssLv:4;
			uint8_t assLvSup:4;
			uint8_t reserveB1b0:1;
			uint8_t reserveB1b1:1;
			uint8_t reserveB1b2:1;
			uint8_t reserveB1b3:1;
			uint8_t reserveB1b4:1;
			uint8_t blindSpot:1;
			uint8_t walkMode:1;
			uint8_t reserveB1b7:1;
			uint8_t lightHead:1;
			uint8_t lightRight:1;
			uint8_t lightTail:1;
			uint8_t lightLeft:1;
			uint8_t reserveB2b4:1;
			uint8_t offlineData1:1;
			uint8_t unLock:1;
			uint8_t tripReset:1;
			uint8_t tripEvent:4;
			uint8_t reserveB3b4:1;
			uint8_t reserveB3b5:1;
			uint8_t reserveB3b6:1;
			uint8_t reserveB3b7:1;
			uint8_t mskNowAssLv:4;
			uint8_t mskAssLvSup:4;
			uint8_t reserveB5b0:1;
			uint8_t reserveB5b1:1;
			uint8_t reserveB5b2:1;
			uint8_t reserveB5b3:1;
			uint8_t reserveB5b4:1;
			uint8_t reserveB5b5:1;
			uint8_t mskWalkMode:1;
			uint8_t reserveB5b7:1;
			uint8_t mskLightHead:1;
			uint8_t mskLightRight:1;
			uint8_t mskLightTail:1;
			uint8_t mskLightLeft:1;
			uint8_t reserveB6b4:1;
			uint8_t mskOfflineData;
			uint8_t mskUnlock;
			uint8_t mskTripRest;
			uint8_t mskTripEvent:4;
			uint8_t reserveB7b4:1;
			uint8_t reserveB7b5:1;
			uint8_t reserveB7b6:1;
			uint8_t reserveB7b7:1;
		}id_0300;
		struct {
			uint16_t maxSpeed;
			uint16_t avgSpeed;
			uint16_t maintODO;
			uint8_t tripID;
		}id_0301;
		struct {
			uint32_t totalODO;
			uint32_t totalTime;
		}id_0302;
		struct {
			uint16_t range; /* how long ODO can be riding base relate bike info */
			int8_t slope;
		}id_0303;
		struct {
			uint32_t timeStamp;
		}id_0304;
		struct {
			uint8_t accessKey0;
			uint8_t accessKey1;
			uint8_t accessKey2;
			uint8_t accessKey3;
			uint8_t accessKey4;
			uint8_t accessKey5;
			uint8_t accessKey6;
			uint8_t accessKey7;
		}id_0305;
		struct {
			uint8_t mainRSOC;
			uint8_t mainASOC;
			uint16_t mainFCC;
			uint16_t mainCC;
			uint16_t mainCycleCount;
		}id_0400;
		struct {
			uint16_t mainCurrent;
			uint16_t mainVoltage;
			uint8_t mainTemp;
			uint8_t mainSOH;
			uint8_t mainFullCharge;
			uint8_t mainReCharge;
			uint8_t mainChargeDetected;
		}id_0401;
		struct {
			uint8_t mainSerial;
			uint8_t mainParalell;
			uint16_t mainCapacity;
			uint16_t mainMUCPeriod;
			uint16_t mainLUCPeriod;
		}id_0402;
		struct {
			uint8_t subRSOC;
			uint8_t subASOC;
			uint16_t subFCC;
			uint16_t subCC;
			uint16_t subCycleCount;
		}id_0410;
		struct {
			uint16_t subCurrent;
			uint16_t subVoltage;
			uint8_t subTemp;
			uint8_t subSOH;
			uint8_t subFullCharge;
			uint8_t subReCharge;
			uint8_t subChargeDetected;
		}id_0411;
		struct {
			uint8_t subSerial;
			uint8_t subParalell;
			uint16_t subCapacity;
			uint16_t subMUCPeriod;
			uint16_t subLUCPeriod;
		}id_0412;
	}console;

	struct {
		struct {
			uint8_t btn1Evt:3;
			uint8_t btn1EvtTime:5;
			uint8_t btn2Evt:3;
			uint8_t btn2EvtTime:5;
			uint8_t btn3Evt:3;
			uint8_t btn3EvtTime:5;
			uint8_t btn4Evt:3;
			uint8_t btn4EvtTime:5;
			uint8_t btn5Evt:3;
			uint8_t btn5EvtTime:5;
		}id_0390;
		struct {
			uint8_t buzzerCount;
			uint8_t buzzerTime;
			uint8_t buzzerResetTime;
			uint8_t buzzerVolume;
			uint8_t buzzerFreq;
		}id_0391;
		struct {
			uint8_t dataPage;
			uint8_t threatLvTarget1:2;
			uint8_t threatLvTarget2:2;
			uint8_t threatLvTarget3:2;
			uint8_t threatLvTarget4:2;
			uint8_t threatSideTarget1:2;
			uint8_t threatSideTarget2:2;
			uint8_t threatSideTarget3:2;
			uint8_t threatSideTarget4:2;
			uint8_t rangeTarget1:6;
			uint8_t rangeTarget2:6;
			uint8_t rangeTarget3:6;
			uint8_t rangeTarget4:6;
			uint8_t speedTarget1:4;
			uint8_t speedTarget2:4;
			uint8_t speedTarget3:4;
			uint8_t speedTarget4:4;
		}id_0392;
		struct {
			uint8_t radarErrCode;
			uint8_t radarState;
		}id_0393;
		struct {
			uint8_t keyVolume;
			uint8_t keyFreq;
			uint8_t radarVolume;
			uint8_t radarFreq;
		}id_0394;


		struct {
			uint8_t accessKey0;
			uint8_t accessKey1;
			uint8_t accessKey2;
			uint8_t accessKey3;
			uint8_t accessKey4;
			uint8_t accessKey5;
			uint8_t accessKey6;
			uint8_t accessKey7;
		}id_0800;
		struct {
			uint8_t profileModuleNameH1;
			uint8_t profileModuleNameH2;
			uint8_t profileModuleNameH3;
			uint8_t profileModuleNameH4;
			uint8_t profileModuleNameH5;
			uint8_t profileModuleNameH6;
			uint8_t profileModuleNameH7;
			uint8_t profileModuleNameH8S;
		}id_0801;
		struct {
			uint8_t profileModuleNameL1;
			uint8_t profileModuleNameL2;
			uint8_t profileModuleNameL3;
			uint8_t profileModuleNameL4;
			uint8_t profileModuleNameL5;
			uint8_t profileModuleNameL6;
			uint8_t profileModuleNameL7;
			uint8_t profileModuleNameL8;
		}id_0802;
		struct {
			uint8_t profileIDCodeH1;
			uint8_t profileIDCodeH2;
			uint8_t profileIDCodeH3;
			uint8_t profileIDCodeH4;
			uint8_t profileIDCodeH5;
			uint8_t profileIDCodeH6;
			uint8_t profileIDCodeH7;
			uint8_t profileIDCodeH8;
		}id_0803;
		struct {
			uint8_t profileIDCodeL1;
			uint8_t profileIDCodeL2;
			uint8_t profileIDCodeL3;
			uint8_t profileIDCodeL4;
			uint8_t profileIDCodeL5;
			uint8_t profileIDCodeL6;
			uint8_t profileIDCodeL7;
			uint8_t profileIDCodeL8;
		}id_0804;
		struct {
			uint8_t profileSerialNumH1;
			uint8_t profileSerialNumH2;
			uint8_t profileSerialNumH3;
			uint8_t profileSerialNumH4;
			uint8_t profileSerialNumH5;
			uint8_t profileSerialNumH6;
			uint8_t profileSerialNumH7;
			uint8_t profileSerialNumH8;
		}id_0805;
		struct {
			uint8_t profileSerialNumL1;
			uint8_t profileSerialNumL2;
			uint8_t profileSerialNumL3;
			uint8_t profileSerialNumL4;
			uint8_t profileSerialNumL5;
			uint8_t profileSerialNumL6;
			uint8_t profileSerialNumL7;
			uint8_t profileSerialNumL8;
		}id_0806;
		struct {
			uint8_t profileFWVerH1;
			uint8_t profileFWVerH2;
			uint8_t profileFWVerH3;
			uint8_t profileFWVerH4;
			uint8_t profileFWVerH5;
			uint8_t profileFWVerH6;
			uint8_t profileFWVerH7;
			uint8_t profileFWVerH8;
		}id_0807;
		struct {
			uint8_t profileFWVerL1;
			uint8_t profileFWVerL2;
			uint8_t profileFWVerL3;
			uint8_t profileFWVerL4;
			uint8_t profileFWVerL5;
			uint8_t profileFWVerL6;
			uint8_t profileFWVerL7;
			uint8_t profileFWVerL8;
		}id_0808;
		struct {
			uint8_t profileVenderH1;
			uint8_t profileVenderH2;
			uint8_t profileVenderH3;
			uint8_t profileVenderH4;
			uint8_t profileVenderH5;
			uint8_t profileVenderH6;
			uint8_t profileVenderH7;
			uint8_t profileVenderH8;
		}id_0809;
		struct {
			uint8_t profileVenderL1;
			uint8_t profileVenderL2;
			uint8_t profileVenderL3;
			uint8_t profileVenderL4;
			uint8_t profileVenderL5;
			uint8_t profileVenderL6;
			uint8_t profileVenderL7;
			uint8_t profileVenderL8;
		}id_080A;
		struct {
			uint8_t profileProtocolVerH1;
			uint8_t profileProtocolVerH2;
			uint8_t profileProtocolVerH3;
			uint8_t profileProtocolVerH4;
			uint8_t profileProtocolVerH5;
			uint8_t profileProtocolVerH6;
			uint8_t profileProtocolVerH7;
			uint8_t profileProtocolVerH8;
		}id_080B;
		struct {
			uint8_t profileProtocolVerL1;
			uint8_t profileProtocolVerL2;
			uint8_t profileProtocolVerL3;
			uint8_t profileProtocolVerL4;
			uint8_t profileProtocolVerL5;
			uint8_t profileProtocolVerL6;
			uint8_t profileProtocolVerL7;
			uint8_t profileProtocolVerL8;
		}id_080C;
		struct {
			uint8_t profileProductDate1;
			uint8_t profileProductDate2;
			uint8_t profileProductDate3;
			uint8_t profileProductDate4;
			uint8_t profileProductDate5;
			uint8_t profileProductDate6;
			uint8_t profileProductDate7;
			uint8_t profileProductDate8;
		}id_080D;
	}peripheral;
}core_dictionary_t;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void CORE_InitDictionary(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
extern core_dictionary_t sysDictionary;

#endif /* CONSOLE_CORE_CORE_DICTIONARY_H_ */
