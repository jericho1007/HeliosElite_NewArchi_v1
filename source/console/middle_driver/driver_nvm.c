/*
 * driver_nvm.c
 *
 *  Created on: 2022年11月23日
 *      Author: JerichoLo
 */
#include "driver_nvm.h"
#include "public.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static flexnvm_config_t s_driver;

/*******************************************************************************
 * Code
 ******************************************************************************/
void NVM_Init(void)
{
	FLEXNVM_Init(&s_driver);
}

bool NVM_EraseSector(const uint32_t startAddr, uint32_t sectors)
{
	bool result = false;
	uint32_t addr = (startAddr & 0xFFFFF);

	if((addr % NVM_SECTOR_SIZE) == 0 &&
	   (addr >= NVM_START_ADDR) &&
	   (addr <= (NVM_START_ADDR + NVM_VALID_SIZE)))
	{
		if(FLEXNVM_DflashErase(&s_driver, startAddr, (NVM_SECTOR_SIZE * sectors), kFTFx_ApiEraseKey))
		{
			if(FLEXNVM_DflashVerifyErase(&s_driver, startAddr, (NVM_SECTOR_SIZE * sectors), kFTFx_MarginValueUser))
			{
				result = true;
			}
		}
	}

	return result;
}

bool NVM_WriteFlash(uint8_t *srcData, uint32_t startAddr, uint32_t len, bool isSwap)
{
	bool result = false;
	uint32_t index;
	uint32_t failAddr = 0;
	uint32_t failData = 0;
	uint32_t writeLen = 0;
	uint8_t nonAlignbits = (len % 8);

	if((startAddr % 8) == 0 &&	/* align address  */
	   len > 0)
	{
		writeLen = len;
		if(nonAlignbits > 0)	/* align length */
		{
			writeLen += (8 - nonAlignbits);
		}
		if(isSwap)
		{
			for(index = 0; index < writeLen; (index += 4))
			{
				PUBLIC_SwapU32Data(&srcData[index]);
			}
		}
		if(FLEXNVM_DflashProgram(&s_driver, startAddr, srcData, writeLen) == kStatus_FTFx_Success)
		{
			if(FLEXNVM_DflashVerifyProgram(&s_driver, startAddr, writeLen, srcData, kFTFx_MarginValueUser, &failAddr, &failData))
			{
				result = true;
			}
		}
	}

	return result;
}

void NVM_ReadFlash(uint8_t *destData, uint32_t startAddr, uint32_t len, bool isSwap)
{
	if(len > 0)
	{
		uint32_t index;
		uint32_t addrAlign 	= (startAddr>>2)<<2;	/* address must be times of 4 */
		uint32_t addrOffset = startAddr & 0x3;
		uint8_t readBuff[((len + 3) & 0xFFFFFFFC)];
		uint32_t alignLen = sizeof(readBuff);

		memset(readBuff, 0, alignLen);	/* clean */
		memcpy(destData, (uint8_t*)addrAlign, alignLen);	/* get data to temp buffer from flash */
		if(isSwap)
		{
			for(index = 0; index < alignLen; (index += 4))
			{
				PUBLIC_SwapU32Data(&readBuff[index]);
			}
		}
		memcpy(destData, &readBuff[addrOffset], len);		/* copy data to dest buffer */
	}
}
