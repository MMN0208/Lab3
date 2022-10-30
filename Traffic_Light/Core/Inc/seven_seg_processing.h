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
#define LED_SCAN_PERIOD	250

void updateCountdownBuffer(void);
void updateTimeBuffer(int time);
void updateModeBuffer(int mode);
void scan7SEG(void);
void reset7SEGIndex(void);

#endif /* INC_SEVEN_SEG_PROCESSING_H_ */
