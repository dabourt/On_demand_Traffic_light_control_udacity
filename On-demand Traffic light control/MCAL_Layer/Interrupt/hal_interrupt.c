/*
 * hal_interrupt.c
 *
 * Created: 8/10/2022 2:11:01 AM
 *  Author: DABOUR
 */ 
#include "hal_interrupt.h"

void (*ext0_call_back_ptr) (void) = NULL;
void (*int_timer1_call_back_ptr) (void) = NULL;
void (*int_timer0_call_back_ptr) (void) = NULL;


void global_interrupt_enable (void){
	SET_BIT(SREG_REG, 7);			// 7 is pin is enabled global interrupt
}
void global_interrupt_disable (void){
	CLEAR_BIT(SREG_REG, 7);
}


Std_ReturnType interrupt_ex_enable (interrupt_request_t request, external_int_pin_t pin){
	Std_ReturnType ret = E_OK;
	/* Trigger ISC01 , ISC00 to select interrupt request mode */
	switch(request){
		case INTERRUPT_LOW_LEVEL:
			CLEAR_BIT(MCUCR_REG, ISC00_PIN);
			CLEAR_BIT(MCUCR_REG, ISC01_PIN);
			break;
		case INTERRUPT_ANY_EDGE:
			SET_BIT(MCUCR_REG, ISC00_PIN);
			CLEAR_BIT(MCUCR_REG, ISC01_PIN);
			break;
		case INTERRUPT_FALLING_EDGE:
			CLEAR_BIT(MCUCR_REG, ISC00_PIN);
			SET_BIT(MCUCR_REG, ISC01_PIN);
			break;
		case INTERRUPT_RISING_EDGE:
			SET_BIT(MCUCR_REG, ISC00_PIN);
			SET_BIT(MCUCR_REG, ISC01_PIN);
			break;
		default:
			ret = E_NOT_OK;
	}
	SET_BIT(GICR_REG, (pin));		// Enable External Interrupt 0
	return ret;
}
Std_ReturnType interrupt_ex_disable (external_int_pin_t pin){
	CLEAR_BIT(GICR_REG, (pin));	// disable External Interrupt 0
	return E_OK;
}

Std_ReturnType interrupt_timer0_ov_enable(void){
	SET_BIT(TIMSK_REG, TOIE0_PIN); 	// Enable Timer0 overflow interrupts
	return E_OK;
}
Std_ReturnType interrupt_timer0_ov_disable(void){
	CLEAR_BIT(TIMSK_REG, TOIE0_PIN); 	// disable Timer0 overflow interrupts
	return E_OK;
}

Std_ReturnType interrupt_timer1_ov_enable(void){
	SET_BIT(TIMSK_REG, TOIE1_PIN); // enable overflow interrupt
	return E_OK;
}
Std_ReturnType interrupt_timer1_ov_disable(void){
	CLEAR_BIT(TIMSK_REG, TOIE1_PIN); // disable overflow interrupt
	return E_OK;
}

Std_ReturnType ext0_set_call_back (void (*function_ptr)(void)){
	Std_ReturnType ret = E_NOT_OK;
	if(function_ptr != NULL){
		ext0_call_back_ptr = function_ptr;
		ret = E_OK;
	}
	return ret;
}

void __vector_1(void) __attribute__((signal, used));
void __vector_1(void){
	if(ext0_call_back_ptr != NULL){
		ext0_call_back_ptr();
	}
}



Std_ReturnType int_timer1_set_call_back (void (*function_ptr)(void)){
	Std_ReturnType ret = E_NOT_OK;
	if(function_ptr != NULL){
		int_timer1_call_back_ptr = function_ptr;
		ret = E_OK;
	}
	return ret;
}

void __vector_9(void) __attribute__((signal, used));
void __vector_9(void){
	if(int_timer1_call_back_ptr != NULL){
		int_timer1_call_back_ptr();
	}
}

Std_ReturnType int_timer0_set_call_back (void (*function_ptr)(void)){
	Std_ReturnType ret = E_NOT_OK;
	if(function_ptr != NULL){
		int_timer0_call_back_ptr = function_ptr;
		ret = E_OK;
	}
	return ret;
}

void __vector_11(void) __attribute__((signal, used));
void __vector_11(void){
	if(int_timer0_call_back_ptr != NULL){
		int_timer0_call_back_ptr();
	}
}
