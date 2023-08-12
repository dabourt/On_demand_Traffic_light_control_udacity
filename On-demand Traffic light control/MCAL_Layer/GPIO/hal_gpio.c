#include "hal_gpio.h"

volatile uint8 *gpio_direction_reg[4] = {&DDRA_REG, &DDRB_REG, &DDRC_REG, &DDRD_REG};				// Direction Registers
volatile uint8 *gpio_input_reg[4] = {&PINA_REG, &PINB_REG, &PINC_REG, &PIND_REG};					// Input Registers
volatile uint8 *gpio_output_reg [4] = {&PORTA_REG, &PORTB_REG, &PORTC_REG, &PORTD_REG};				// Output Registers



#if GPIO_PORT_PIN_CONFIGURATION == CONFIG_ENABLE 
/**
 * @brief this function selected the pin is input or output  
 * @param _pin_config pointer to pin_config_t contain the pin number in selected port
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config){
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        switch(_pin_config->direction){
            case GPIO_DIRECTION_OUTPUT : 
                SET_BIT(*gpio_direction_reg[_pin_config->port], _pin_config->pin);
                break;
            case GPIO_DIRECTION_INPUT :
                CLEAR_BIT(*gpio_direction_reg[_pin_config->port], _pin_config->pin);
                break;
            default : 
                ret = E_NOT_OK;
        }
    }
    return ret;
}

/**
 * @brief this function return the direction of pin selected pin
 * @param _pin_config pointer to pin_config_t contain the pin number in selected port
 * @param  direction_status 
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status){
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || NULL == direction_status || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        *direction_status = READ_BIT(*gpio_direction_reg[_pin_config->port], _pin_config->pin);
    }
    return ret;
}

/**
 * @brief function used to write a logic (LOW , HIGH) in selected pin
 * @param _pin_config pointer to pin_config_t
 * @param logic pointer to variable to hold pin state wanted to write
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic){
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{            
        switch(logic){
            case GPIO_LOW :
                CLEAR_BIT(*gpio_output_reg[_pin_config->port], _pin_config->pin);
                break;
            case GPIO_HIGH :
                SET_BIT(*gpio_output_reg[_pin_config->port], _pin_config->pin);
                break;
            default :
                ret = E_NOT_OK; 
        }

    }
    return ret;    
}

/**
 * @brief function used to read a logic (LOW , HIGH) in selected pin
 * @param _pin_config pointer to pin_config_t
 * @param logic pointer to variable to hold pin state 
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic){
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || NULL == logic || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        *logic = READ_BIT(*gpio_input_reg[_pin_config->port], _pin_config->pin);
    }    
    return ret;
}
/**
 * @brief function to toggle the pin logic
 * @param _pin_config pointer to pin_config_t
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config){
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        TOGGLE_BIT(*gpio_output_reg[_pin_config->port], _pin_config->pin);
    }
    return ret;
}

/**
 * @brief function to initialize the pin and set the director and the logic 
 * @param _pin_config
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType gpio_pin_intialize(const pin_config_t *_pin_config){
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_direction_intialize(_pin_config);
        gpio_pin_write_logic(_pin_config, _pin_config->logic);
    }
    return ret;
}
#endif


#if GPIO_PORT_CONFIGURATION == CONFIG_ENABLE
/**
 * @brief function to initialize the direction of port
 * @param port contain the index of port
 * @param direction included port direction GPIO_INPUT or GPIO_OPUTPUT
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType gpio_port_direction_intialize(port_index_t port, uint8 direction){
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        *gpio_direction_reg[port] = direction;
    }
    return ret;
}

/**
 * @brief function to select port direction
 * @param port contain the index of port
 * @param direction included port direction GPIO_INPUT or GPIO_OPUTPUT
 * @return state of function OK or NOK if passed wrong pin or port or null pointer
 */
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status){
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        *direction_status = *gpio_direction_reg[port];
    }
    return ret;
}

/**
 * @brief function to set port as output high or low
 * @param port contain the index of port
 * @param direction included port direction GPIO_INPUT or GPIO_OPUTPUT
 * @return state of function OK or NOK if passed wrong port or null pointer 
 */
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic){
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        *gpio_output_reg[port] = logic;
    }
	return ret;
}

/**
 * @brief function to read logic from the port
 * @param port contain the index of port
 * @param direction included port direction GPIO_INPUT or GPIO_OPUTPUT
 *  @return state of function OK or NOK if passed wrong port or null pointer
 */
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic){
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        *logic = *gpio_input_reg[port];
    }
    return ret;
}

/**
 * @brief function to toggle the logic on the port
 * @param port contain the index of port
 * @param direction included port direction GPIO_INPUT or GPIO_OPUTPUT
 * @return state of function OK or NOK if passed wrong port or null pointer
 */
Std_ReturnType gpio_port_toggle_logic(port_index_t port){
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        *gpio_output_reg[port] = ~(*gpio_output_reg[port]);
    }
    return ret;
} 

#endif