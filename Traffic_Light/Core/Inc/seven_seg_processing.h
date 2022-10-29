/*
 * seven_seg_processing.h
 *
 *  Created on: Oct 29, 2022
 *      Author: ADMIN
 */

#ifndef INC_SEVEN_SEG_PROCESSING_H_
#define INC_SEVEN_SEG_PROCESSING_H_

#include "main.h"
#include "software_timer.h"

#define MAX_7SEG_LEDS	4

void update7SEGBuffer();
void display7SEG(int index);

#endif /* INC_SEVEN_SEG_PROCESSING_H_ */
