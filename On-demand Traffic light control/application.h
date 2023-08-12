/* 
 * File:   application.h
 * Author: DABOUR
 *
 * Created on July 31, 2022, 3:37 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section : Include */

//#include "ECU_Layer/LED/led.h"
//#include "ECU_Layer/BUSH_BUTTON/push_button.h"
#include "main_components/components.h"
#include "ECU_Layer/time_applications/ecu_time_applications.h"

/* Section : Macro Declarations */


/* Section : Macro Functions Declarations */


/* Section : Data Type Declarations */
typedef enum{
	RED_SIGN = 1,
	YELLOW_SIGN,
	GREEN_SIGN
}trafic_sign_t;

typedef enum{
	SEQUANCE_DOWNWARD,		// means the traffic moves from red to green. 
	SEQUANCE_UPWARD			// means the traffic moves from green to red. 
}sequance_t;

typedef enum{
	TRAFFIC_CAR_MODE,
	TRAFFIC_PEDESTRIANS_MODE
}traffic_mode_t;
 
/* Section : Function Declarations */

/************************************************************************/
/* brief function represent as startup application to initialize traffic*/ 
/*       cars leds and traffic pedestrians leds and intialize the times */
/*		 can used in system                                             */
/************************************************************************/
void application_intialize(void);

/**************************************************************************************/
/* brief function execution ever 250ms if the timer0 (fast timer function) is enabled */
/**************************************************************************************/
void interrrupt_each_250msec (void);

/**************************************************************************************/
/* brief function execution ever 5 sec if the timer1 (timer control sign) is enabled  */
/**************************************************************************************/
void interrrupt_each_5sec (void);


 
#endif	/* APPLICATION_H */

