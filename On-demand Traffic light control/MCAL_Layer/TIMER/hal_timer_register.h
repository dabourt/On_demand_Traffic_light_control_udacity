/*
 * hal_timer_register.h
 *
 * Created: 8/11/2022 2:25:23 AM
 *  Author: DABOUR
 */ 


#ifndef HAL_TIMER_REGISTER_H_
#define HAL_TIMER_REGISTER_H_

#define TCNT0_REG (*((volatile uint8 *)(0x52)))
#define TCCR0_REG (*((volatile uint8 *)(0x53)))

#define TCCR1B_REG (*((volatile uint8 *)(0x4E)))
#define TCCR1A_REG (*((volatile uint8 *)(0x4F)))

#define TCNT1L_REG (*((volatile uint8 *)(0x4C)))
#define TCNT1H_REG (*((volatile uint8 *)(0x4D)))
#define TCNT1_REG  (*((volatile uint16 *)(0x4C)))

#define TIFR_REG  (*((volatile uint8 *)(0x58)))

#define TOV0_PIN 0
#define TOV1_PIN 2

#endif /* HAL_TIMER_REGISTER_H_ */