/*
 * public.h
 *
 *  Created on: 2022年11月7日
 *      Author: JerichoLo
 */

#ifndef CONSOLE_PUBLIC_H_
#define CONSOLE_PUBLIC_H_
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef enum io_level {
	kio_level_low = 0,
	kio_level_high,
}io_level_t;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void PUBLIC_SwapU32Data(uint8_t *srcData);

/*******************************************************************************
 * Variables
 ******************************************************************************/

#endif /* CONSOLE_PUBLIC_H_ */
