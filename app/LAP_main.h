/*
 * LAP_main.h
 *
 *  Created on: 2020. 06. 11.
 *      Author: YJPark
 */

#ifndef APPLICATION_GASTAG_EXE_GASTAG_SRC_LAP_MAIN_H_
#define APPLICATION_GASTAG_EXE_GASTAG_SRC_LAP_MAIN_H_

typedef struct
{
	uint8_t event;
	uint8_t status;
	uint16_t conn_handle;
	uint16_t handle;
	uint32_t msg_len;
	uint8_t* msg;
}LAPEvt_msgt;

enum
{
	LAP_CENTRAL_EVT = 0,
	LAP_PERIPHERAL_EVT,
	LAP_LIDx_EVT,
	LAP_PNIP_EVT,
	LAP_AMD_EVT,
};

enum{
	LAP_CENTRAL_ST_SCAN_RESULT = 0,
	LAP_CENTRAL_ST_SCAN_TIMEOUT,
	LAP_CENTRAL_ST_CONN_TIMEOUT,
	LAP_CENTRAL_ST_SCAN_ADV_REPORT,
	LAP_CENTRAL_ST_CONNECTED,
	LAP_CENTRAL_ST_DISCONNECTED,
	LAP_CENTRAL_ST_DATA_RECEIVED,
};

enum
{
	LAP_PERIPHERAL_ST_CONNECTED = 0,
	LAP_PERIPHERAL_ST_DISCONNECTED,
	LAP_PERIPHERAL_ST_DATA_RECEIVED,
};

enum{
	LAP_EVT_LIDX = 0,
	LAP_EVT_PNIP,
	LAP_EVT_AMD,

	EC_EVT_CENTRAL,
	EC_EVT_PERIPHERAL,
};

enum{
	EC_STATUS_ADV_REPORT,
	EC_STATUS_CONNECTED,
	EC_STATUS_DISCONNECTED,

	EC_STATUS_DATA_RECEIVE,
	EC_STATUS_ENTRANCE_INFO,

};

#define LAP_EVENT_HANDLE_NULL				0
#define LAP_EVENT_MSG_LEN_NULL				0

void LAP_main_task_init(void);

int LAP_event_send(uint8_t evt, uint8_t state, uint16_t conn_handle, uint16_t handle,
									uint32_t msg_len, uint8_t* msg);

void send_option_msg(uint8_t device_ID, uint8_t max_current);
void send_calib_msg();
void send_short_msg(uint8_t CMD);

#endif /* APPLICATION_GASTAG_EXE_GASTAG_SRC_LAP_MAIN_H_ */
