/*
 * push_button.h
 *
 * Created: 8/5/2022 10:48:40 PM
 *  Author: DABOUR
 */ 


#ifndef PUSH_BUTTON_H_
#define PUSH_BUTTON_H_

/* Section : Include */
#include "..\..\MCAL_Layer\GPIO\hal_gpio.h"
#include "../../MCAL_Layer/Interrupt/hal_interrupt.h"
/* Section : Macro Declarations */


/* Section : Macro Functions Declarations */


/* Section : Data Type Declarations */

typedef struct {
	uint8 port : 3;
	uint8 pin : 3;
	uint8 reserved_bit : 2;
}push_button_cfg_t;

/* Section : Function Declarations */

/**
 * @brief function to interfacing selected pin with button by make the pin is input
 * @param led is pointer to led_char_t contain the port and the pin wanted to connect led with it
 * @return OK or not ok if pass wrong port index or pin index or null pointer
 */
Std_ReturnType push_button_intialize (push_button_cfg_t *push_button);

/**
 * @brief function read the state of pin which connected with button
 * @param led is pointer to led_char_t contain the port and the pin wanted to connect led with it
 * @return OK or not ok if pass wrong port index or pin index or null pointer
 */
Std_ReturnType push_button_read_status (push_button_cfg_t *push_button, logic_t *push_button_status);

/**
 * @brief function to enable  interrupt in INT0 as interface as button
 */
Std_ReturnType push_button_interrupted_enable (void);

/**
 * @brief function to disable  interrupt in INT0 as interface as button
 */
Std_ReturnType push_button_interrupted_disable (void);

#endif /* PUSH_BUTTON_H_ */