/*
 * global.h
 *
 *  Created on: Oct 29, 2022
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

typedef enum  {
	INIT,
	AUTO_RED,
	AUTO_GRN,
	AUTO_YEL,
	MAN_RED,
	MAN_YEL,
	MAN_GRN
} state;

extern int status;

#endif /* INC_GLOBAL_H_ */
