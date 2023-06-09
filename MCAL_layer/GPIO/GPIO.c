#include "GPIO.h"

volatile uint8 *tris_registers[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
volatile uint8 *port_registers[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};
volatile uint8 *lat_registers[] = {&LATA, &LATB, &LATC, &LATD, &LATE};


#if GPIO_PIN_CONFIGURATION == CONFIG_ENABLE
/**
 * 
 * @param pin_config it is pointer to pin configuration @ref pin_config_t
 * @return status of function could be 
 *          E_OK : the function done successfully
 *          E_NOT_OK : the function has issue to perform this action
 */
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t *pin_config){
    Std_ReturnType ret = E_OK;
    if(pin_config == NULL || pin_config->pin > PIN_MAX_NUMBER-1 || pin_config->port > PORT_MAX_NUMBER-1){
        ret =E_NOT_OK;
    }
    else{
        if(pin_config->direction == GPIO_DIRECTION_OUTPUT){
        CLEAR_BIT(HWREG8(tris_registers[pin_config->port]), pin_config->pin);
        
        }
        else if(pin_config->direction == GPIO_DIRECTION_INPUT){
            SET_BIT(HWREG8(tris_registers[pin_config->port]), pin_config->pin);
        }
        else{
            ret =  E_NOT_OK;
        }
    }
    
    return ret;
}
#endif


#if GPIO_PIN_CONFIGURATION == CONFIG_ENABLE
/**
 * 
 * @param pin_config it is pointer to pin configuration @ref pin_config_t
 * @param direction_status
 * @return status of function could be 
 *          E_OK : the function done successfully
 *          E_NOT_OK : the function has issue to perform this action
 */
Std_ReturnType gpio_pin_get_direction_status( pin_config_t *pin_config, direction_t *direction_status){
    
    Std_ReturnType ret = E_OK;
    
    if(pin_config == NULL || direction_status == NULL){
        ret =E_NOT_OK;
    }
    else{
        *direction_status = READ_BIT(HWREG8(tris_registers[pin_config->port]),pin_config->pin);
        pin_config->direction = *direction_status;
    }
    
    
    return ret;
    
}
#endif

#if GPIO_PIN_CONFIGURATION == CONFIG_ENABLE
/**
 * 
 * @param pin_config it is pointer to pin configuration @ref pin_config_t
 * @param logic
 * @return status of function could be 
 *          E_OK : the function done successfully
 *          E_NOT_OK : the function has issue to perform this action
 */
Std_ReturnType gpio_pin_write_logic( pin_config_t *pin_config, logic_t logic){

    Std_ReturnType ret = E_OK;
    
    if(pin_config == NULL){
        ret =E_NOT_OK;
    }
    else{
        switch(logic){
            case GPIO_HIGH:
                SET_BIT(HWREG8(lat_registers[pin_config->port]),pin_config->pin);
                pin_config->logic = GPIO_HIGH;
                break;
            case GPIO_LOW:
                CLEAR_BIT(HWREG8(lat_registers[pin_config->port]),pin_config->pin);
                pin_config->logic = GPIO_LOW;
                break;
                default:
                    ret = E_NOT_OK;
                    break;
        
        }
    }
    return ret;

}
#endif

#if GPIO_PIN_CONFIGURATION == CONFIG_ENABLE
/**
 * 
 * @param pin_config it is pointer to pin configuration @ref pin_config_t
 * @param logic
 * @return status of function could be 
 *          E_OK : the function done successfully
 *          E_NOT_OK : the function has issue to perform this action
 */
Std_ReturnType gpio_pin_read_logic( pin_config_t *pin_config, logic_t *logic){

    Std_ReturnType ret = E_OK;
    
    if(pin_config == NULL || logic == NULL){
        ret =E_NOT_OK;
    }
    else{
        *logic = READ_BIT(HWREG8(port_registers[pin_config->port]),pin_config->pin);
        pin_config->logic = *logic;
    }
    return ret;

}
#endif

#if GPIO_PIN_CONFIGURATION == CONFIG_ENABLE
/**
 * 
 * @param pin_config it is pointer to pin configuration @ref pin_config_t
 * @return status of function could be 
 *          E_OK : the function done successfully
 *          E_NOT_OK : the function has issue to perform this action
 */
Std_ReturnType gpio_pin_toggle_logic( pin_config_t *pin_config){

    Std_ReturnType ret = E_OK;
    
    if(pin_config == NULL){
        ret =E_NOT_OK;
    }
    else{
        TOGGLE_BIT(HWREG8(lat_registers[pin_config->port]), pin_config->pin);
        pin_config->logic = ~pin_config->logic;
    }
    return ret;

}
#endif

#if GPIO_PIN_CONFIGURATION == CONFIG_ENABLE
/**
 * 
 * @param pin_config it is pointer to pin configuration @ref pin_config_t
 * @return status of function could be 
 *          E_OK : the function done successfully
 *          E_NOT_OK : the function has issue to perform this action
 *          
 */
Std_ReturnType gpio_pin_initialize( pin_config_t* pin_config){
    Std_ReturnType ret = E_OK;
    
    if(pin_config == NULL){
        ret =E_NOT_OK;
    }
    else{
        ret=gpio_pin_direction_initialize(pin_config);
        ret=gpio_pin_write_logic(pin_config,pin_config->logic);
    }
    return ret;
}
#endif
#if GPIO_PORT_CONFIGURATION == CONFIG_ENABLE
/**
 * 
 * @param port
 * @param direction
 * @return status of function could be 
 *          E_OK : the function done successfully
 *          E_NOT_OK : the function has issue to perform this action
 */
Std_ReturnType gpio_port_direction_initialize(port_index_t port, uint8 direction){

    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1){
        ret =E_NOT_OK;
    }
    else{
        HWREG8(tris_registers[port]) = direction;
    }
    return ret;
    


}
#endif

#if GPIO_PORT_CONFIGURATION == CONFIG_ENABLE
/**
 * 
 * @param port
 * @param direction_status
 * @return status of function could be 
 *          E_OK : the function done successfully
 *          E_NOT_OK : the function has issue to perform this action
 */
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status){

    Std_ReturnType ret = E_OK;
    
    if(direction_status == NULL || port > PORT_MAX_NUMBER-1){
        ret =E_NOT_OK;
    }
    else{
        *direction_status = HWREG8(tris_registers[port]) ;
    }
    return ret;

}
#endif



#if GPIO_PORT_CONFIGURATION == CONFIG_ENABLE
/**
 * 
 * @param port
 * @param logic
 * @return status of function could be 
 *          E_OK : the function done successfully
 *          E_NOT_OK : the function has issue to perform this action
 */
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic){
 
    Std_ReturnType ret = E_OK;
    
    if(port > PORT_MAX_NUMBER-1){
        ret =E_NOT_OK;
    }
    else{
        HWREG8(lat_registers[port]) = logic;
    }
    
    return ret;

}
#endif

#if GPIO_PORT_CONFIGURATION == CONFIG_ENABLE
/**
 * 
 * @param port
 * @param logic
 * @return status of function could be 
 *          E_OK : the function done successfully
 *          E_NOT_OK : the function has issue to perform this action
 */
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic){

    Std_ReturnType ret = E_OK;
    
    if(logic == NULL || port > PORT_MAX_NUMBER-1){
        ret =E_NOT_OK;
    }
    else{
        *logic = HWREG8(lat_registers[port]) ;
    }
    return ret;

}
#endif

#if GPIO_PORT_CONFIGURATION == CONFIG_ENABLE
/**
 * 
 * @param port
 * @return status of function could be 
 *          E_OK : the function done successfully
 *          E_NOT_OK : the function has issue to perform this action
 */
Std_ReturnType gpio_port_toggle_logic(port_index_t port){

    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1){
        ret =E_NOT_OK;
    }
    else{
         HWREG8(lat_registers[port]) ^= 0xFF;
    }
    
    return ret;

}
#endif



Std_ReturnType gpio_port_low_nibble_direction_initialize(pin_config_t *pin_config, uint8 data){
    Std_ReturnType ret = E_OK;
    if(pin_config == NULL){
        ret =E_NOT_OK;
    }
    else{
        SET_LOW_NIBBLE_BITS(HWREG8(tris_registers[pin_config->port]), data);
    }
    return ret;

}
Std_ReturnType gpio_port_low_nibble_write_logic(pin_config_t *pin_config, uint8 data){
    Std_ReturnType ret = E_OK;
    if(pin_config == NULL){
        ret =E_NOT_OK;
    }
    else{
        SET_LOW_NIBBLE_BITS(HWREG8(lat_registers[pin_config->port]), data);
    }
    return ret;
}
Std_ReturnType gpio_port_high_nibble_direction_initialize(pin_config_t *pin_config, uint8 data){
    Std_ReturnType ret = E_OK;
    if(pin_config == NULL){
        ret =E_NOT_OK;
    }
    else{
        SET_HIGH_NIBBLE_BITS(HWREG8(tris_registers[pin_config->port]), data);
    }
    return ret;

}
Std_ReturnType gpio_port_high_nibble_write_logic(pin_config_t *pin_config, uint8 data){
    Std_ReturnType ret = E_OK;
    if(pin_config == NULL){
        ret =E_NOT_OK;
    }
    else{
        SET_HIGH_NIBBLE_BITS(HWREG8(lat_registers[pin_config->port]), data);
    }
    return ret;

}