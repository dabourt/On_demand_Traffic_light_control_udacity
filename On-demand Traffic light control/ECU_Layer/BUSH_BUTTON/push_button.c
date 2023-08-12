/*
 * pushbutton.c
 *
 * Created: 8/5/2022 10:47:44 PM
 *  Author: DABOUR
 */ 

#include "push_button.h"

/************************************************************************/
/* @																	*/
/* @para : push_button_cfg_t											*/
/* @return                                                              */
/************************************************************************/
Std_ReturnType push_button_intialize (push_button_cfg_t *push_button){
	Std_ReturnType ret = E_OK;
	if(NULL == push_button){
		ret = E_NOT_OK;
	}else
	{
		pin_config_t pin_cfg = {
			.port = push_button->port,
			.pin = push_button->pin,
			.direction = GPIO_DIRECTION_INPUT,
			.logic = GPIO_HIGH
		};
		ret = gpio_pin_direction_intialize(&pin_cfg);
	}
	return ret;
}

/************************************************************************/
/* @																	*/
/* @para																*/
/* @return                                                              */
/************************************************************************/
Std_ReturnType push_button_read_status (push_button_cfg_t *push_button, logic_t *push_button_status){
	Std_ReturnType ret = E_OK;
	if(NULL == push_button){
		ret = E_NOT_OK;
	}else
	{
		pin_config_t pin_cfg = {
			.port = push_button->port,
			.pin = push_button->pin,
			.direction = GPIO_DIRECTION_INPUT,
			.logic = GPIO_LOW
		};
		ret = gpio_pin_read_logic(&pin_cfg, push_button_status);
	}
	return ret;
}

Std_ReturnType push_button_interrupted_enable (void){
	Std_ReturnType ret;
	interrupt_request_t request = INTERRUPT_RISING_EDGE;
	external_int_pin_t pin = EX_INT0;
	ret = interrupt_ex_enable (request, pin);
	return ret;
}
Std_ReturnType push_button_interrupted_disable (void){
	Std_ReturnType ret;
	external_int_pin_t pin = EX_INT0;
	ret = interrupt_ex_disable (pin);
	return ret;
}