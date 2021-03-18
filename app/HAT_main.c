/*
 * HAT_main.c
 *
 *  Created on: 2020. 06. 11.
 *      Author: YJPark
 */

#include <ubinos.h>

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "HAT_main.h"
#include "ble_stack.h"
#include "LAP_main.h"

#include "Button.h"
#include "LED.h"

static msgq_pt HAT_msgq;


void button_handler1(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action);
void button_handler2(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action);
void button_handler3(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action);
void button_handler4(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action);


void HAT_main_task(void* arg){
	int r;
	HATEvt_msgt HAT_evt_msg;


	nrf_drv_gpiote_init();
	LED_init();
	Button_init(button_handler1, button_handler2, button_handler3, button_handler4);

	ble_stack_init_wait();


	LED_on(PIN_LED1);


	for (;;) {
		r = msgq_receive(HAT_msgq, (unsigned char*) &HAT_evt_msg);
		if (0 != r) {
			logme("fail at msgq_receive\r\n");
		} else {
			switch( HAT_evt_msg.event ){

			case EVT_BUTTON1 :
				break;

			case EVT_BUTTON2 :
				break;

			case EVT_BUTTON3 :
				break;

			case EVT_BUTTON4 :
				break;


			default :
				break;
			}

			if( HAT_evt_msg.msg != NULL ){
				free(HAT_evt_msg.msg);
			}
		}
	}
}

void HAT_main_task_init(void){
	int r;

	r = msgq_create(&HAT_msgq, sizeof(HATEvt_msgt), 20);
	if (0 != r) {
		printf("fail at msgq create\r\n");
	}

	r = task_create(NULL, HAT_main_task, NULL, task_gethighestpriority()-2, 512, NULL);
	if (r != 0) {
		printf("== HAT_main_task failed \n\r");
	} else {
		printf("== HAT_main_task created \n\r");
	}
}

int HAT_event_send(uint8_t evt, uint8_t state, uint8_t* msg)
{
	HATEvt_msgt hat_msg;

	hat_msg.event = evt;
	hat_msg.status = state;
	hat_msg.msg = msg;

	return msgq_send(HAT_msgq, (unsigned char*) &hat_msg);
}



void button_handler1(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action) {

	bsp_busywaitms(10);
	if ( nrf_drv_gpiote_in_is_set(pin))
		return;

	HAT_event_send(EVT_BUTTON1, 0, NULL);
}
void button_handler2(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action) {

	bsp_busywaitms(10);
	if ( nrf_drv_gpiote_in_is_set(pin))
		return;

	HAT_event_send(EVT_BUTTON2, 0, NULL);
}
void button_handler3(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action) {

	bsp_busywaitms(10);
	if ( nrf_drv_gpiote_in_is_set(pin))
		return;

	HAT_event_send(EVT_BUTTON3, 0, NULL);
}
void button_handler4(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action) {

	bsp_busywaitms(10);
	if ( nrf_drv_gpiote_in_is_set(pin))
		return;

	HAT_event_send(EVT_BUTTON4, 0, NULL);
}
