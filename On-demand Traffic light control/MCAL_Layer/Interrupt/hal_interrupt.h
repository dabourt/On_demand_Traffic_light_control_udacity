/*
 * hal_interrupt.h
 *
 * Created: 8/10/2022 2:11:58 AM
 *  Author: DABOUR
 */ 


#ifndef HAL_INTERRUPT_H_
#define HAL_INTERRUPT_H_

/* Section : Include */
#include "../Device_config.h"
#include "../compiler.h"
#include "../mcal_std_types.h"
#include "hal_interrupt_reg.h"

/* Section : Macro Declarations */
#define BIT_MASK ((uint8)1)

/* Section : Macro Functions Declarations */

#ifndef SET_BIT
#define SET_BIT(REG, BIT_POSN) ((REG) |= ((BIT_MASK) << BIT_POSN))
#endif

#ifndef CLEAR_BIT
#define CLEAR_BIT(REG, BIT_POSN) ((REG) &= ~((BIT_MASK) << BIT_POSN))
#endif

#ifndef TOGGLE_BIT
#define TOGGLE_BIT(REG, BIT_POSN) ((REG) ^= ((BIT_MASK) << BIT_POSN))
#endif

#ifndef READ_BIT
#define READ_BIT(REG, BIT_POSN) (((REG) >> (BIT_POSN)) & BIT_MASK)
#endif

#ifndef HWREG8
#define HWREG8(_X) (*((volatile uint8 *)(_X)))
#endif

/* Section : Data Type Declarations */

typedef enum {
	INTERRUPT_LOW_LEVEL,
	INTERRUPT_ANY_EDGE,
	INTERRUPT_FALLING_EDGE,
	INTERRUPT_RISING_EDGE,
}interrupt_request_t;

typedef enum {				// from GICR register
	EX_INT2 = 5,
	EX_INT0,
	EX_INT1
}external_int_pin_t;

/* Section : Function Declarations */

/**
 * @brief call this function to enable global interrupt
 */
void global_interrupt_enable (void);

/**
 * @brief call this function to enable global interrupt
 */
void global_interrupt_disable (void);

/**
 * @brief function to enable the external interrupt and select the interrupted pin and interrupt request sensitivity
 * @param pin variable hold interrupted pin
 * @param request hold the mode of interrupt request sensitivity
 */
Std_ReturnType interrupt_ex_enable (interrupt_request_t request, external_int_pin_t pin);

/**
 * @brief function to disable the external interrupt on selected pin  
 * @param pin variable hold interrupted pin
 * @param request hold the mode of interrupt request sensitivity
 */
Std_ReturnType interrupt_ex_disable (external_int_pin_t pin);

/**
 * @brief function to enable the timer0 interrupt when timer1 reach the overflow
 */
Std_ReturnType interrupt_timer0_ov_enable(void);

/**
 * @brief function to disable the timer0 overflow interrupt
 */
Std_ReturnType interrupt_timer0_ov_disable(void);

/**
 * @brief function to enable the timer1 interrupt when timer1 reach the overflow
 */
Std_ReturnType interrupt_timer1_ov_enable(void);

/**
 * @brief function to disable the timer1 overflow interrupt
 */
Std_ReturnType interrupt_timer1_ov_disable(void);

/**
 * @brief function executed when INT0 inter to interrupt
 *		  Select the program to be executed when entering this type of interrupt as a function and pass the address of this function to ext0_set_call_back function
 * @param function_ptr pointer to function
 * @return OK or E_NOT_OK if pass NULL pointer
 */
Std_ReturnType ext0_set_call_back (void (*function_ptr)(void));

/**
 * @brief function executed when timer1 reach thee overflow
 *		  Select the program to be executed when entering this type of interrupt as a function and pass the address of this function to int_timer1_set_call_back function
 * @param function_ptr pointer to function
 * @return OK or E_NOT_OK if pass NULL pointer
 */
Std_ReturnType int_timer1_set_call_back (void (*function_ptr)(void));

/**
 * @brief function executed when int_timer0_set_call_back
 *		  Select the program to be executed when entering this type of interrupt as a function and pass the address of this function to int_timer0_set_call_back function
 * @param function_ptr pointer to function
 * @return OK or E_NOT_OK if pass NULL pointer
 */
Std_ReturnType int_timer0_set_call_back (void (*function_ptr)(void));


#endif /* HAL_INTERRUPT_H_ */