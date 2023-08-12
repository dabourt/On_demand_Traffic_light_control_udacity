/*
 * components.c
 *
 * Created: 8/11/2022 7:26:50 PM
 *  Author: DABOUR
 */

#include "components.h"

/********************** static function section  *********************/


/********************* global variables section  *********************/
extern flag_t flag_250ms;
led_char_t car_red_led = {
	.pin = pin0,
	.port = PORTA_INDEX,
	.led_status = GPIO_LOW
};

led_char_t car_yellow_led = {
	.pin = pin1,
	.port = PORTA_INDEX,
	.led_status = GPIO_LOW
};

led_char_t car_green_led = {
	.pin = pin2,
	.port = PORTA_INDEX,
	.led_status = GPIO_LOW
};

push_button_cfg_t podstrain_button = {
	.pin = pin2,
	.port = PORTD_INDEX,
};

led_char_t podstrain_red_led = {
	.pin = pin0,
	.port = PORTB_INDEX,
	.led_status = GPIO_LOW
};

led_char_t podstrain_yellow_led = {
	.pin = pin1,
	.port = PORTB_INDEX,
	.led_status = GPIO_LOW
};

led_char_t podstrain_green_led = {
	.pin = pin2,
	.port = PORTB_INDEX,
	.led_status = GPIO_LOW
};


/* car's traffic light LEDs initializations */
void traffic_car_signs_initialization(void){
	led_intialize(&car_red_led);
	led_intialize(&car_yellow_led);
	led_intialize(&car_green_led);
}

/* pedestrians request button initialization */
void pedestrians_button_initialization(void){
	push_button_intialize(&podstrain_button);
}

/* pedestrians traffic light LEDs initializations */
void traffic_pedestrians_signs_initialization(void){
	led_intialize(&podstrain_red_led);
	led_intialize(&podstrain_yellow_led);
	led_intialize(&podstrain_green_led);
}

void car_red_sign (void)
{
	led_turn_on(&car_red_led);
	led_turn_off(&car_yellow_led);
	led_turn_off(&car_green_led);
}

void car_yellow_sign (void)
{
	
	if(flag_250ms == FLAG_SET){
		led_turn_on(&car_yellow_led);
	}
	else
	{
		led_turn_off(&car_yellow_led);
	}
	led_turn_off(&car_red_led);
	led_turn_off(&car_green_led);
}

void car_green_sign (void)
{
	led_turn_off(&car_red_led);
	led_turn_off(&car_yellow_led);
	led_turn_on(&car_green_led);
}

void pedestrians_red_sign (void)
{
	led_turn_on(&podstrain_red_led);
	led_turn_off(&podstrain_yellow_led);
	led_turn_off(&podstrain_green_led);
}

void pedestrians_yellow_sign (void)
{
	if(flag_250ms == FLAG_SET){
		led_turn_off(&podstrain_yellow_led);
	}
	else
	{
		led_turn_on(&podstrain_yellow_led);
	}
	led_turn_off(&podstrain_red_led);
	led_turn_off(&podstrain_green_led);
}

void pedestrians_green_sign (void)
{
	led_turn_off(&podstrain_red_led);
	led_turn_off(&podstrain_yellow_led);
	led_turn_on(&podstrain_green_led);
}