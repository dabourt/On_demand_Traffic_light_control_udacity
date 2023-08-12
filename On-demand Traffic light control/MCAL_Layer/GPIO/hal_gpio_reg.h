/*
 * hal_gpio_reg.h
 *
 * Created: 8/10/2022 8:48:25 PM
 *  Author: DABOUR
 */ 


#ifndef HAL_GPIO_REG_H_
#define HAL_GPIO_REG_H_

#define DDRA_REG (*((volatile uint8 *)(0x3A)))
#define DDRB_REG (*((volatile uint8 *)(0x37)))
#define DDRC_REG (*((volatile uint8 *)(0x34)))
#define DDRD_REG (*((volatile uint8 *)(0x31)))

#define PINA_REG (*((volatile uint8 *)(0x39)))
#define PINB_REG (*((volatile uint8 *)(0x36)))
#define PINC_REG (*((volatile uint8 *)(0x33)))
#define PIND_REG (*((volatile uint8 *)(0x30)))

#define PORTA_REG (*((volatile uint8 *)(0x3B)))
#define PORTB_REG (*((volatile uint8 *)(0x38)))
#define PORTC_REG (*((volatile uint8 *)(0x35)))
#define PORTD_REG (*((volatile uint8 *)(0x32)))



#endif /* HAL_GPIO_REG_H_ */