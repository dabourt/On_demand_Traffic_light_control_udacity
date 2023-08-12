/*
 * ecu_time_applications.c
 *
 * Created: 8/10/2022 5:24:51 AM
 *  Author: DABOUR
 */ 
#include "ecu_time_applications.h"

timer1_cfg_t timer_control_sign = {
	.init_value = 46005,	// to set 5 sec timer
	.prescaler = CLK_256	// set up timer with prescaler = 256
};

timer0_cfg_t timer_fast = {
	.init_value = 47,		// to set 500 msec timer
	.prescaler = CLK_1024
};

Std_ReturnType timer_control_sign_enable (void){
	Std_ReturnType ret;
	
	ret = timer1_initialization_normal_mode(&timer_control_sign);
	interrupt_timer1_ov_enable();
	
	return ret;
}
Std_ReturnType timer_control_sign_disable (void){
	interrupt_timer1_ov_disable();
	timer1_off();
	return E_OK;
}

Std_ReturnType timer_control_sign_reset (void){
	Std_ReturnType ret;
	
	ret = timer1_reset_value_normal_mode(&timer_control_sign);
	return ret;
}

Std_ReturnType timer_control_sign_delay (void){
	Std_ReturnType ret;
	ret = timer1_delay_normal_mode(&timer_control_sign);
	return ret;
}

/***************************************************************************/

Std_ReturnType fast_timer_enable (void){
	Std_ReturnType ret;
	
	ret = timer0_initialization_normal_mode(&timer_fast);
	interrupt_timer0_ov_enable();
	
	return ret;
}
Std_ReturnType fast_timer_disable (void){
	interrupt_timer0_ov_disable();
	timer0_off();
	return E_OK;
}
Std_ReturnType fast_timer_reset (void){
	Std_ReturnType ret;
	
	ret = timer0_reset_value_normal_mode(&timer_fast);
	
	return ret;
}

Std_ReturnType fast_timer_delay (void){
	Std_ReturnType ret;
	ret = timer0_delay_normal_mode(&timer_fast);
	return ret;
}