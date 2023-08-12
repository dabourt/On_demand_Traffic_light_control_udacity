/* 
 * File:   hal_gpio.h
 * Author: DABOUR
 *
 * Created on July 31, 2022, 3:42 AM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* Section : Include */

#include "../Device_config.h"
#include "../mcal_std_types.h"
#include "hal_gpio_config.h"
#include "hal_gpio_reg.h"

/* Section : Macro Declarations */
#define BIT_MASK ((uint8)1)

#define PORT_PIN_MAX_NUMBER 8
#define PORT_MAX_NUMBER 4

/* Section : Macro Functions Declarations */
#define HWREG8(_X) (*((volatile uint8 *)(_X)))

#define SET_BIT(REG, BIT_POSN) (REG |= (BIT_MASK << BIT_POSN))
#define CLEAR_BIT(REG, BIT_POSN) (REG &= ~(BIT_MASK << BIT_POSN))
#define TOGGLE_BIT(REG, BIT_POSN) (REG ^= (BIT_MASK << BIT_POSN))

#define READ_BIT(REG, BIT_POSN) ((REG >> BIT_POSN) & BIT_MASK)

/* Section : Data Type Declarations */
typedef enum{
    GPIO_LOW,
    GPIO_HIGH    
}logic_t;

typedef enum{
    GPIO_DIRECTION_OUTPUT = 0,
    GPIO_DIRECTION_INPUT
}direction_t;

typedef enum{
    pin0 = 0,
    pin1,
    pin2,
    pin3,
    pin4,
    pin5,
    pin6,
    pin7            
}pin_index_t;

typedef enum{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX,
}port_index_t;

typedef struct{
    uint8 port : 3;
    uint8 pin : 3;
    uint8 direction : 1;
    uint8 logic : 1;
}pin_config_t;

/* Section : Function Declarations */

/******************************** pin functions *********************************/

/**
 * @brief this function selected the pin is input or output  
 * @param _pin_config pointer to pin_config_t contain the pin number in selected port
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config);

/**
 * @brief this function return the direction of pin selected pin
 * @param _pin_config pointer to pin_config_t contain the pin number in selected port
 * @param  direction_status 
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status);

/**
 * @brief function used to write a logic (LOW , HIGH) in selected pin
 * @param _pin_config pointer to pin_config_t
 * @param logic pointer to variable to hold pin state wanted to write
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic);

/**
 * @brief function used to read a logic (LOW , HIGH) in selected pin
 * @param _pin_config pointer to pin_config_t
 * @param logic pointer to variable to hold pin state 
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic);

/**
 * @brief function to toggle the pin logic
 * @param _pin_config pointer to pin_config_t
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config);

/**
 * @brief function to initialize the pin and set the director and the logic 
 * @param _pin_config
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType gpio_pin_intialize(const pin_config_t *_pin_config);


/******************************** ports functions *********************************/
/**
 * @brief function to initialize the direction of port
 * @param port contain the index of port
 * @param direction included port direction GPIO_INPUT or GPIO_OPUTPUT
 * @return state of function OK or NOK if passed wrong port or null pointer
 */
Std_ReturnType gpio_port_direction_intialize(port_index_t port, uint8 direction);

/**
 * @brief function to select port direction
 * @param port contain the index of port
 * @param direction included port direction GPIO_INPUT or GPIO_OPUTPUT
 * @return state of function OK or NOK if passed wrong port or null pointer
 */
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status);

/**
 * @brief function to set port as output high or low
 * @param port contain the index of port
 * @param direction included port direction GPIO_INPUT or GPIO_OPUTPUT
 * @return state of function OK or NOK if passed wrong port or null pointer 
 */
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic);

/**
 * @brief function to read logic from the port
 * @param port contain the index of port
 * @param direction included port direction GPIO_INPUT or GPIO_OPUTPUT
 *  @return state of function OK or NOK if passed wrong port or null pointer
 */
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic);

/**
 * @brief function to toggle the logic on the port
 * @param port contain the index of port
 * @param direction included port direction GPIO_INPUT or GPIO_OPUTPUT
 * @return state of function OK or NOK if passed wrong port or null pointer
 */
Std_ReturnType gpio_port_toggle_logic(port_index_t port);

#endif	/* HAL_GPIO_H */