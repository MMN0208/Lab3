/*
 * input_reading.c
 *
 *  Created on: Oct 29, 2022
 *      Author: ADMIN
 */

#include "main.h"
//we aim to work with more than one buttons
#define NO_OF_BUTTONS 				       3
//timer interrupt duration is 10ms, so to pass 1 second,
//we need to jump to the interrupt service routine 100 time
#define DURATION_FOR_AUTO_INCREASING	   100
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
static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];
//we define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
//we define a flag for a button pressed more than 1 second.
static uint8_t flagForButtonPress1s[NO_OF_BUTTONS];
//we define counter for automatically increasing the value
//after the button is pressed more than 1 second.
static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];

void button_reading(void){
	for(int i = 0; i < NO_OF_BUTTONS; i++){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(buttonPort[i], buttonPin[i]);
		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
			buttonBuffer[i] = debounceButtonBuffer1[i];
		if(buttonBuffer[i] == BUTTON_IS_PRESSED){
		//if a button is pressed, we start counting
			if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING){
				counterForButtonPress1s[i]++;
			} else {
			//the flag is turned on when 1 second has passed
			//since the button is pressed.
				flagForButtonPress1s[i] = 1;
				//TODO
			}
		} else {
			counterForButtonPress1s[i] = 0;
			flagForButtonPress1s[i] = 0;
		}
	}
}

int is_button_pressed(int index){
	if(index >= NO_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

int is_button_pressed_1s(int index){
	if(index >= NO_OF_BUTTONS) return 0;
	return (flagForButtonPress1s[index] == 1);
}
