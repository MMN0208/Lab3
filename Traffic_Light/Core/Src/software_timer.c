/*
 * software_timer.c
 *
 *  Created on: Oct 29, 2022
 *      Author: ADMIN
 */

#include "software_timer.h"

int traffic_timer_flag[NO_OF_EACH] = {0, 0};
int traffic_timer_counter[NO_OF_EACH] = {0, 0};

int timer1_counter = 0;
int timer1_flag = 0;

int timer2_counter = 0;
int timer2_flag = 0;

int timer3_counter = 0;
int timer3_flag = 0;

void setTrafficTimer(int index, int duration) {
	if(SYSTEM_DELAY > 0) {
		traffic_timer_counter[index] = duration / SYSTEM_DELAY;
	} else traffic_timer_counter[index] = duration;
	traffic_timer_flag[index] = 0;
}

void setTimer1(int duration) {
	if(SYSTEM_DELAY > 0) {
		timer1_counter = duration / SYSTEM_DELAY;
	} else timer1_counter = duration;
	timer1_flag = 0;
}

void setTimer2(int duration) {
	if(SYSTEM_DELAY > 0) {
		timer2_counter = duration / SYSTEM_DELAY;
	} else timer2_counter = duration;
	timer2_flag = 0;
}


void setTimer3(int duration) {
	if(SYSTEM_DELAY > 0) {
		timer3_counter = duration / SYSTEM_DELAY;
	} else timer3_counter = duration;
	timer3_flag = 0;
}

void timerRun(void) {
	for(int i = 0; i < NO_OF_EACH; i++) {
		if(traffic_timer_counter[i] > 0) {
			traffic_timer_counter[i]--;
			if(traffic_timer_counter[i] <= 0) {
				traffic_timer_flag[i] = 1;
			}
		}
	}

	if(timer1_counter > 0) {
		timer1_counter--;
		if(timer1_counter <= 0) {
			timer1_flag = 1;
		}
	}

	if(timer2_counter > 0) {
		timer2_counter--;
		if(timer2_counter <= 0) {
			timer2_flag = 1;
		}
	}

	if(timer3_counter > 0) {
		timer3_counter--;
		if(timer3_counter <= 0) {
			timer3_flag = 1;
		}
	}
}
