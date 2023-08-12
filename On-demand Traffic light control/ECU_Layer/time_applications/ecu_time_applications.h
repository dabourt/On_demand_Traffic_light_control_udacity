/*
 * ecu_time_applications.h
 *
 * Created: 8/10/2022 5:24:21 AM
 *  Author: DABOUR
 */ 


#ifndef ECU_SWITCH_TIME_H_
#define ECU_SWITCH_TIME_H_

/* Section : Include */
#include "../../MCAL_Layer/TIMER/hal_timer.h"
#include "../../MCAL_Layer/Interrupt/hal_interrupt.h"

/* Section : Macro Declarations */


/* Section : Macro Functions Declarations */


/* Section : Data Type Declarations */


/* Section : Function Declarations */

/**
 * @brief function to make timer interrupt every 5sec (this function enable this timer)
 */
Std_ReturnType timer_control_sign_enable (void);

/**
 * @brief function to make timer interrupt every 5sec (this function disable this timer)
 */
Std_ReturnType timer_control_sign_disable (void);

/**
 * @brief function to reset the control sign timer
 */
Std_ReturnType timer_control_sign_reset (void);

/**
 * @brief to use control sign timer as delay not interrupt
 */
Std_ReturnType timer_control_sign_delay (void);

/**
 * @brief function to make timer interrupt every 250msec (this function enable this timer)
 */
Std_ReturnType fast_timer_enable (void);

/**
 * @brief function to make timer interrupt every 250msec (this function disable this timer)
 */
Std_ReturnType fast_timer_disable (void);

/**
 * @brief function to reset this timer to initial value
 */
Std_ReturnType fast_timer_reset (void);

/**
 * @brief to use this timer as delay and turn of interrupt
 */
Std_ReturnType fast_timer_delay (void);


#endif /* ECU_SWITCH_TIME_H_ */