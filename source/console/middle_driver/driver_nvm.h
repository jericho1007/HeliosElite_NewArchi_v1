/*
 * driver_nvm.h
 *
 *  Created on: 2022年11月23日
 *      Author: JerichoLo
 */

#ifndef CONSOLE_MIDDLE_DRIVER_DRIVER_NVM_H_
#define CONSOLE_MIDDLE_DRIVER_DRIVER_NVM_H_
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"
#include "fsl_flash.h"
#include "fsl_ftfx_controller.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define NVM_SECTOR_SIZE		0x800 		/* 2KB */
#define NVM_VALID_SIZE		0x3000		/* 12KB */
#define NVM_START_ADDR		0x7C800		/* */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void NVM_Init(void);
bool NVM_EraseSector(const uint32_t startAddr, uint32_t sectors);
bool NVM_WriteFlash(uint8_t *srcData, uint32_t startAddr, uint32_t len, bool isSwap);
void NVM_ReadFlash(uint8_t *destData, uint32_t startAddr, uint32_t len, bool isSwap);

/*******************************************************************************
 * Variables
 ******************************************************************************/


#endif /* CONSOLE_MIDDLE_DRIVER_DRIVER_NVM_H_ */
