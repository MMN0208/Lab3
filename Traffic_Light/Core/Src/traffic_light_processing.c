/*
 * traffic_light_processing.c
 *
 *  Created on: Oct 29, 2022
 *      Author: ADMIN
 */

#include "traffic_light_processing.h"

#define ON			GPIO_PIN_RESET
#define OFF			GPIO_PIN_SET
#define SECOND		1000 // 1s = 1000ms

//red light ports and pins
GPIO_TypeDef * redPort[NO_OF_EACH] = {
	RED_0_GPIO_Port,
	RED_1_GPIO_Port
};

uint16_t redPin[NO_OF_EACH] = {
	RED_0_Pin,
	RED_1_Pin
};

//yel light ports and pins
GPIO_TypeDef * yelPort[NO_OF_EACH] = {
	YEL_0_GPIO_Port,
	YEL_1_GPIO_Port
};

uint16_t yelPin[NO_OF_EACH] = {
	YEL_0_Pin,
	YEL_1_Pin
};

//grn light ports and pins
GPIO_TypeDef * grnPort[NO_OF_EACH] = {
	GRN_0_GPIO_Port,
	GRN_1_GPIO_Port
};

uint16_t grnPin[NO_OF_EACH] = {
	GRN_0_Pin,
	GRN_1_Pin
};

//initial time for red, yel, grn lights
int redTime = 15;
int yelTime = 3;
int grnTime = 12;

//count-down for south/north, east/west lights
int snCountdown = 0;
int ewCountdown = 0;

void allOff(int index) {
	HAL_GPIO_WritePin(redPort[index], redPin[index], OFF);
	HAL_GPIO_WritePin(yelPort[index], yelPin[index], OFF);
	HAL_GPIO_WritePin(grnPort[index], grnPin[index], OFF);
}

void redLight(int index) {
	HAL_GPIO_WritePin(redPort[index], redPin[index], ON);
	HAL_GPIO_WritePin(yelPort[index], yelPin[index], OFF);
	HAL_GPIO_WritePin(grnPort[index], grnPin[index], OFF);

}
void yelLight(int index) {
	HAL_GPIO_WritePin(redPort[index], redPin[index], OFF);
	HAL_GPIO_WritePin(yelPort[index], yelPin[index], ON);
	HAL_GPIO_WritePin(grnPort[index], grnPin[index], OFF);
}
void grnLight(int index) {
	HAL_GPIO_WritePin(redPort[index], redPin[index], OFF);
	HAL_GPIO_WritePin(yelPort[index], yelPin[index], OFF);
	HAL_GPIO_WritePin(grnPort[index], grnPin[index], ON);
}

void yelBlink(void) {
	for(int i = 0; i < NO_OF_EACH; i++) {
		HAL_GPIO_WritePin(redPort[i], redPin[i], OFF);
		HAL_GPIO_TogglePin(yelPort[i], yelPin[i]);
		HAL_GPIO_WritePin(grnPort[i], grnPin[i], OFF);
	}
}

void grnBlink(void) {
	for(int i = 0; i < NO_OF_EACH; i++) {
		HAL_GPIO_WritePin(redPort[i], redPin[i], OFF);
		HAL_GPIO_WritePin(yelPort[i], yelPin[i], OFF);
		HAL_GPIO_TogglePin(grnPort[i], grnPin[i]);
	}
}

int getRedTime(void) {
	return redTime * SECOND;
}

int getYelTime(void) {
	return yelTime * SECOND;
}

int getGrnTime(void) {
	return grnTime * SECOND;
}

void setCountdown(int direction, int duration) {
	if(duration <= 0) return;
	if(direction == SOUTH_NORTH) {
		snCountdown = duration / SECOND;
	}
	else if(direction == EAST_WEST) {
		ewCountdown = duration / SECOND;
	}
}

void updateCountdown() {
	if(snCountdown > 0) snCountdown--;
	if(ewCountdown >0) ewCountdown--;
}

int getCountdown(int direction) {
	if(direction == SOUTH_NORTH) {
		return snCountdown;
	}
	else if(direction == EAST_WEST) {
		return ewCountdown;
	}
	return -1;
}

void updateRedTime(void) {
	redTime = yelTime + grnTime;
}

void updateYelTime(int time) {
	yelTime = time;
}

void updateGrnTime(int time) {
	grnTime = time;
}
