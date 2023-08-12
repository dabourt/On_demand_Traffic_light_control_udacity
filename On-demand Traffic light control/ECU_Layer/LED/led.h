/* 
 * File:   led.h
 * Author: DABOUR
 *
 * Created on July 31, 2022, 5:02 AM
 */

#ifndef LED_H
#define	LED_H

/* Section : Include */

#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_led_config.h"

/* Section : Macro Declarations */


/* Section : Macro Functions Declarations */


/* Section : Data Type Declarations */
typedef enum {
    LED_OFF,
    LED_ON
}led_status_t;

typedef struct {
    uint8 port : 3;
    uint8 pin : 3;
    uint8 led_status : 1;
    uint8 reserved_bit : 1;
}led_char_t;

/* Section : Function Declarations */

/**
 * @brief function to interfacing selected pin with led
 * @param led is pointer to led_char_t contain the port and the pin wanted to connect led with it
 * @return OK or not ok if pass wrong port index or pin index or null pointer
 */
Std_ReturnType led_intialize(const led_char_t *led);

/**
 * @brief function turn on led
 * @param led is pointer to led_char_t contain the port and the pin wanted to connect led with it
 * @return OK or not ok if pass wrong port index or pin index or null pointer
 */
Std_ReturnType led_turn_on(const led_char_t *led);

/**
 * @brief function turn off led
 * @param led is pointer to led_char_t contain the port and the pin wanted to connect led with it
 * @return OK or not ok if pass wrong port index or pin index or null pointer
 */
Std_ReturnType led_turn_off(const led_char_t *led);

/**
 * @brief function toggle led
 * @param led is pointer to led_char_t contain the port and the pin wanted to connect led with it
 * @return OK or not ok if pass wrong port index or pin index or null pointer
 */
Std_ReturnType led_toggle(const led_char_t *led);

#endif	/* LED_H */

