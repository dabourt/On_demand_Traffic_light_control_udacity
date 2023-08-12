#include "led.h"
/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_intialize(const led_char_t *led){
    Std_ReturnType ret = E_OK;
    if(NULL == led){
        ret = E_NOT_OK;
    }else
    {
        pin_config_t pin_cfg = {
            .port = led->port,
            .pin = led->pin,
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = led->led_status
        };
        gpio_pin_intialize(&pin_cfg);
    }
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_on(const led_char_t *led){
    Std_ReturnType ret = E_OK;
    if(NULL == led){
        ret = E_NOT_OK;
    }else
    {
        pin_config_t pin_cfg = {
            .port = led->port,
            .pin = led->pin,
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = GPIO_HIGH
        };
        gpio_pin_write_logic(&pin_cfg, GPIO_HIGH);
    
    }
    
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_off(const led_char_t *led){
    Std_ReturnType ret = E_OK;
    if(NULL == led){
        ret = E_NOT_OK;
    }else
    {
        pin_config_t pin_cfg = {
            .port = led->port,
            .pin = led->pin,
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = GPIO_LOW
        };
        gpio_pin_write_logic(&pin_cfg, GPIO_LOW);
    
    }
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_toggle(const led_char_t *led){
    Std_ReturnType ret = E_OK;
    if(NULL == led){
        ret = E_NOT_OK;
    }else
    {
        pin_config_t pin_cfg = {
            .port = led->port,
            .pin = led->pin,
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = led->led_status
        };
        gpio_pin_toggle_logic(&pin_cfg);
    }
    return ret;    
}