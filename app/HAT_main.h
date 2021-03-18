/*
 * HAT_main.h
 *
 *  Created on: 2020. 06. 11.
 *      Author: YJPark
 */

#ifndef APP_HAT_MAIN_H_
#define APP_HAT_MAIN_H_

#include <ubinos.h>

#include <stdio.h>
#include <stdint.h>
#include <string.h>


enum{
	HAT_DEFAULT_EVT,
	EVT_BUTTON1,
	EVT_BUTTON2,
	EVT_BUTTON3,
	EVT_BUTTON4,
};

enum{
	HAT_DEFAULT_ST
};

typedef struct
{
	uint8_t event;
	uint8_t status;
	uint8_t* msg;
}HATEvt_msgt;

void HAT_main_task_init(void);
int HAT_event_send(uint8_t evt, uint8_t state, uint8_t* msg);

#endif /* APP_HAT_MAIN_H_ */
