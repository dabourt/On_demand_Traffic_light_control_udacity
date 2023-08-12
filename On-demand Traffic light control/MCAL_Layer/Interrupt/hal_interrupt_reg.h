/*
 * hal_interrupt_reg.h
 *
 * Created: 8/10/2022 8:14:39 PM
 *  Author: DABOUR
 */ 


#ifndef HAL_INTERRUPT_REG_H_
#define HAL_INTERRUPT_REG_H_


#define MCUCR_REG  (*((volatile uint8 *)(0x55)))
#define GICR_REG   (*((volatile uint8 *)(0x5B)))
#define TIMSK_REG  (*((volatile uint8 *)(0x59)))
#define TIFR_REG   (*((volatile uint8 *)(0x58)))
#define SREG_REG   (*((volatile uint8 *)(0x5F)))

#define ISC00_PIN 0
#define ISC01_PIN 1

#define TOIE0_PIN 0
#define TOIE1_PIN 2

#endif /* HAL_INTERRUPT_REG_H_ */