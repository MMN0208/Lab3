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
int grnTime = 10;

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

void redBlink(void) {
	HAL_GPIO_TogglePin(redPort[0], redPin[0]);
	HAL_GPIO_TogglePin(redPort[1], redPin[1]);
}

void yelBlink(void) {
	HAL_GPIO_TogglePin(yelPort[0], yelPin[0]);
	HAL_GPIO_TogglePin(yelPort[1], yelPin[1]);
}

void grnBlink(void) {
	HAL_GPIO_TogglePin(grnPort[0], grnPin[0]);
	HAL_GPIO_TogglePin(grnPort[1], grnPin[1]);
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

void updateRedTime(int time) {
	redTime = time;
}

void updateYelTime(int time) {
	yelTime = time;
}

void updateGrnTime(int time) {
	grnTime = time;
}
