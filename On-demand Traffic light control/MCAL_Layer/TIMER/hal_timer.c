/*
 * hal_timer.c
 *
 * Created: 8/10/2022 2:12:25 AM
 *  Author: DABOUR
 */ 
#include "hal_timer.h"

Std_ReturnType timer0_initialization_normal_mode (timer0_cfg_t *timer){
	Std_ReturnType ret = E_OK;
	if(NULL == timer){
		ret = E_NOT_OK;
	}
	else{
		TCNT0_REG = timer->init_value;
		
		TCCR0_REG = 0x07 & (timer->prescaler);
	}
	return ret;
}

//Std_ReturnType timer0_enable_interrupt_normal_mode (timer0_cfg_t *timer);

Std_ReturnType timer0_reset_value_normal_mode (timer0_cfg_t *timer){
	Std_ReturnType ret = E_OK;
	if(NULL == timer){
		ret = E_NOT_OK;
	}
	else{
		TCNT0_REG = timer->init_value;
	}
	return ret;
}
Std_ReturnType timer0_delay_normal_mode (timer0_cfg_t *timer){
	Std_ReturnType ret = E_OK;
	if(NULL == timer){
		ret = E_NOT_OK;
	}
	else{
		TCNT0_REG = timer->init_value;
		TCCR0_REG = 0x07 & (timer->prescaler);
		
		while(READ_BIT(TIFR_REG,TOV0_PIN) != STD_LOW)			// wait until timer0 over flow flag be come one
		;

		TCCR0_REG = 0x00;						// stop timer0
		SET_BIT(TIFR_REG, TOV0_PIN);
	}
	return ret;
};

Std_ReturnType timer0_off (void){
	
	TCCR0_REG = 0x00;						// stop timer0
	TIFR_REG = 0x01;						// clear TOV0
	
	return E_OK;
	
}

Std_ReturnType timer1_initialization_normal_mode (timer1_cfg_t *timer){
	Std_ReturnType ret = E_OK;
	if(NULL == timer){
		ret = E_NOT_OK;
	}
	else{
		TCCR1B_REG = 0x07 & (timer->prescaler);
		TCCR1A_REG = 0x00;
		
		TCNT1_REG = timer->init_value;
	}
	return ret;
}

Std_ReturnType timer1_reset_value_normal_mode (timer1_cfg_t *timer){
	Std_ReturnType ret = E_OK;
	if(NULL == timer){
		ret = E_NOT_OK;
	}
	else{
		TCNT1_REG = timer->init_value;
	}
	return ret;
}

Std_ReturnType timer1_delay_normal_mode (timer1_cfg_t *timer){
	
	Std_ReturnType ret = E_OK;
	if(NULL == timer){
		ret = E_NOT_OK;
	}
	else{
		TCNT1_REG = timer->init_value;
		
		TCCR1B_REG = 0x07 & (timer->prescaler);
		TCCR1A_REG = 0x00;
		
		while(READ_BIT(TIFR_REG,TOV1_PIN) == STD_LOW);
		
		TCCR1B_REG = 0x00;						// stop timer0
		SET_BIT(TIFR_REG, TOV1_PIN);
		
	}
	return ret;
}

Std_ReturnType timer1_off (void){
	
	TCCR1B_REG = 0x00;		// close the CLK
	TCCR1A_REG = 0x00;
	
	return E_OK;
}