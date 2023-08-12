/*
 * components.h
 *
 * Created: 8/11/2022 7:26:21 PM
 *  Author: DABOUR
 */ 


#ifndef COMPONENTS_H_
#define COMPONENTS_H_

/* Section : Include */

#include "../ECU_Layer/LED/led.h"
#include "../ECU_Layer/BUSH_BUTTON/push_button.h"

/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef enum{
	FLAG_SET,
	FLAG_CLEAR
}flag_t;


/* Section : Function Declarations */

/**
 * @brief function initialize traffic sign for cars
 */
void traffic_car_signs_initialization(void);

/**
 * @brief function initialize traffic sign for pedestrians
 */
void traffic_pedestrians_signs_initialization(void);

/**
 * @brief function initialize button for pedestrians to switch to pedestrians 
 */
void pedestrians_button_initialization(void);

/**
 * @brief function to turn on red sign for car and turn off yellow and green sign 
 */
void car_red_sign (void);

/**
 * @brief function to blinking yellow sign for car and turn off red and green sign
 */
void car_yellow_sign (void);

/**
 * @brief function to turn on green sign for car and turn off yellow and red sign
 */
void car_green_sign (void);

/**
 * @brief function to turn on red sign for pedestrians and turn off yellow and green sign 
 */
void pedestrians_red_sign (void);

/**
 * @brief function to blinking yellow sign for pedestrians and turn off red and green sign
 */
void pedestrians_yellow_sign (void);

/**
 * @brief function to turn on green sign for pedestrian and turn off yellow and red sign
 */
void pedestrians_green_sign (void);


#endif /* COMPONENTS_H_ */