/*
 * traffic_light_processing.h
 *
 *  Created on: Oct 29, 2022
 *      Author: ADMIN
 */

#ifndef INC_TRAFFIC_LIGHT_PROCESSING_H_
#define INC_TRAFFIC_LIGHT_PROCESSING_H_

#include "main.h"
#include "software_timer.h"

#define NO_OF_EACH	2

#define SOUTH_NORTH 0
#define EAST_WEST	1

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

void setCountdown(int direction, int duration);
void updateCountdown(void);
int getCountdown(int direction);

void updateRedTime(void);
void updateYelTime(int time);
void updateGrnTime(int time);

#endif /* INC_TRAFFIC_LIGHT_PROCESSING_H_ */
