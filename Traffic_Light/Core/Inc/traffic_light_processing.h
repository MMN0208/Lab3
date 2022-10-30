/*
 * traffic_light_processing.h
 *
 *  Created on: Oct 29, 2022
 *      Author: ADMIN
 */

#ifndef INC_TRAFFIC_LIGHT_PROCESSING_H_
#define INC_TRAFFIC_LIGHT_PROCESSING_H_

#include "main.h"

#define NO_OF_EACH	2

void allOff(int index);
void redLight(int index);
void yelLight(int index);
void grnLight(int index);

void redBlink(void);
void yelBlink(void);
void grnBlink(void);

int getRedTime(void);
int getYelTime(void);
int getGrnTime(void);

void updateRedTime(int time);
void updateYelTime(int time);
void updateGrnTime(int time);

#endif /* INC_TRAFFIC_LIGHT_PROCESSING_H_ */
