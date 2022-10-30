/*
 * input_reading.c
 *
 *  Created on: Oct 29, 2022
 *      Author: ADMIN
 */
#include "input_reading.h"
//we aim to work with more than one buttons
#define NO_OF_BUTTONS 				       3
//timer interrupt duration is 10ms, so to pass 1 second,
//we need to jump to the interrupt service routine 100 time
#define DURATION_FOR_AUTO_INCREASING	   500
#define BUTTON_IS_PRESSED                  GPIO_PIN_RESET
#define BUTTON_IS_RELEASED                 GPIO_PIN_SET
//the buffer that the final result is stored after

//button ports and pins array
GPIO_TypeDef * buttonPort[NO_OF_BUTTONS] = {
	BTN_0_GPIO_Port,
	BTN_1_GPIO_Port,
	BTN_2_GPIO_Port
};

uint16_t buttonPin[NO_OF_BUTTONS] = {
	BTN_0_Pin,
	BTN_1_Pin,
	BTN_2_Pin
};

//debouncing
static GPIO_PinState buttonBuffer[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};
//we define three buffers for debouncing
static GPIO_PinState debounceButtonBuffer0[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};
//we define a flag for a button pressed more than 1 second.
static uint8_t flagForButtonPressed[NO_OF_BUTTONS];
//we define counter for automatically increasing the value
//after the button is pressed more than 1 second.
static uint16_t counterForButtonHold[NO_OF_BUTTONS] = {0, 0, 0};

void button_reading(void){
	for(int i = 0; i < NO_OF_BUTTONS; i++) {
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = debounceButtonBuffer0[i];
		debounceButtonBuffer0[i] = HAL_GPIO_ReadPin(buttonPort[i], buttonPin[i]);
		if((debounceButtonBuffer2[i] == debounceButtonBuffer1[i]) || (debounceButtonBuffer1[i] == debounceButtonBuffer0[i])) {
			if(buttonBuffer[i] != debounceButtonBuffer0[i]) {
				buttonBuffer[i] = debounceButtonBuffer0[i];
				if(buttonBuffer[i] == BUTTON_IS_PRESSED) {
					counterForButtonHold[i] = DURATION_FOR_AUTO_INCREASING;
					if(SYSTEM_DELAY > 0) counterForButtonHold[i] /= SYSTEM_DELAY;
					flagForButtonPressed[i] = 1;
				}
			}
			else {
				counterForButtonHold[i]--;
				if(counterForButtonHold[i] == 0) {
					buttonBuffer[i] = BUTTON_IS_RELEASED;
				}
			}
		}
	}
}

int is_button_pressed(int index){
	if(index < 0 || index > NO_OF_BUTTONS) return -1;
	if(flagForButtonPressed[index] == 1) {
		flagForButtonPressed[index] = 0;
		return 1;
	}
	return 0;
}
