/*
 * hal_timer.h
 *
 * Created: 8/10/2022 2:12:50 AM
 *  Author: DABOUR
 */ 


#ifndef HAL_TIMER_H_
#define HAL_TIMER_H_

/* Section : Include */
#include "../Device_config.h"
#include "../compiler.h"
#include "../mcal_std_types.h"
#include "hal_timer_register.h"
/* Section : Macro Definition */

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

typedef enum{
	CLK_0,
	CLK_1,
	CLK_8,
	CLK_64,
	CLK_256,
	CLK_1024
}timer_prescaler_t;

typedef struct
{
	uint8 init_value;
	timer_prescaler_t prescaler;
}timer0_cfg_t;

typedef struct
{
	uint16 init_value;
	timer_prescaler_t prescaler;
}timer1_cfg_t;

/* Section : Function Declarations */

/********************************** timer zero **********************************/
/**
 * @brief set timer0 in normal mode and set initial value
 * @param timer is pointer to timer contain initial value and prescaler
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType timer0_initialization_normal_mode (timer0_cfg_t *timer);

/**
 * @brief  reset the timer0 to initial value
 * @param timer is pointer to timer contain initial value and prescaler
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType timer0_reset_value_normal_mode (timer0_cfg_t *timer);

/**
 * @brief function to delay the program at time calculated by this equations (initial value = delay / timer_tick) , (timer_tick = prescaler/F_CPU)
 * @param timer is pointer to timer contain initial value and prescaler
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType timer0_delay_normal_mode (timer0_cfg_t *timer);

/**
 * @brief function to stop timer0
 */
Std_ReturnType timer0_off (void);

/********************************** timer one **********************************/

/**
 * @brief set timer1 in normal mode and set initial value
 * @param timer is pointer to timer contain initial value and prescaler
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType timer1_initialization_normal_mode (timer1_cfg_t *timer);

/**
 * @brief  reset the timer1 to initial value
 * @param timer is pointer to timer contain initial value and prescaler
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType timer1_reset_value_normal_mode (timer1_cfg_t *timer);

/**
 * @brief function to delay the program at time calculated by this equations (initial value = delay / timer_tick) , (timer_tick = prescaler/F_CPU)
 * @param timer is pointer to timer contain initial value and prescaler
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType timer1_delay_normal_mode (timer1_cfg_t *timer);

/**
 * @brief function to stop timer1
 */
Std_ReturnType timer1_off (void);

#endif /* HAL_TIMER_H_ */