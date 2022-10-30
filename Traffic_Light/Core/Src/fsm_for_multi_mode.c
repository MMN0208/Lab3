/*
 * fsm_for_mode_switching.c
 *
 *  Created on: Oct 30, 2022
 *      Author: ADMIN
 */

#include "fsm_for_multi_mode.h"

#define TIMER_INIT 	10 // 10ms

void fsm_multi_mode_run(void) {
	switch(status) {
	case STARTUP:
		setTimer1(TIMER_INIT);
		status = MODE1;
		break;
	case MODE1:
		fsm_automatic_run();
		updateCountdownBuffer();
		scan7SEG();
		if(is_button_pressed(0)) {
			setTimer1(TIMER_INIT);
			status = MODE2;
			reset7SEGIndex();
			allOff(0);
			allOff(1);
		}
		break;
	case MODE2:
		if(timer1_flag == 1) {
			setTimer1(500);
			redBlink();
		}
		if(is_button_pressed(0)) {
			setTimer1(TIMER_INIT);
			status = MODE1;
			reset7SEGIndex();
			allOff(0);
			allOff(1);
		}
	default: break;
	}
}
