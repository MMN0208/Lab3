/*
 * fsm_automatic.c
 *
 *  Created on: Oct 29, 2022
 *      Author: ADMIN
 */

#include "fsm_automatic.h"

void fsm_automatic_run(void) {
	for(int i = 0; i < NO_OF_EACH; i++) {
		switch(lightStatus[i]) {
		case INIT:
			allOff(i);
			if(i == 0) {
				lightStatus[i] = RED;
				setTrafficTimer(i, getRedTime());
			}
			else {
				lightStatus[i] = GRN;
				setTrafficTimer(i, getGrnTime());
			}
			break;
		case RED:
			redLight(i);
			if(traffic_timer_flag[i] == 1) {
				setTrafficTimer(i, getGrnTime());
				lightStatus[i] = GRN;
			}
			break;
		case GRN:
			grnLight(i);
			if(traffic_timer_flag[i] == 1) {
				setTrafficTimer(i, getYelTime());
				lightStatus[i] = YEL;
			}
			break;
		case YEL:
			yelLight(i);
			if(traffic_timer_flag[i] == 1) {
				setTrafficTimer(i, getRedTime());
				lightStatus[i] = RED;
			}
			break;
		default: break;
		}
	}
}
