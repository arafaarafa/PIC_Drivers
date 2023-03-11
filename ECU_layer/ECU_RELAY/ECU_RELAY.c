#include "ECU_RELAY.h"


/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_initialize(const relay_t *relay){
    Std_ReturnType ret = E_OK;
    
    if(relay == NULL){
        ret =E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_initialize(&(relay->relay_pin));
    }
    return ret;
}

/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_turn_on(relay_t *relay){
    Std_ReturnType ret = E_OK;
    
    if(relay == NULL){
        ret =E_NOT_OK;
    }
    else{
        logic_t temp_logic = GPIO_HIGH ;
        if(relay->relay_normarl_state == RELAY_NORMALLY_CLOSED){
            temp_logic = GPIO_LOW ;
        }
        else if(relay->relay_normarl_state == RELAY_NORMALLY_OPEN){
            temp_logic = GPIO_HIGH ;
        }
        ret = gpio_pin_write_logic( &(relay->relay_pin), temp_logic);
        if(ret != E_NOT_OK)
            relay->relay_status = RELAY_ON_STATUS;
        
    }
    return ret;
}
/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_turn_off(relay_t *relay){
    Std_ReturnType ret = E_OK;
    
    if(relay == NULL){
        ret =E_NOT_OK;
    }
    else{
        logic_t temp_logic = GPIO_LOW ;
        if(relay->relay_normarl_state == RELAY_NORMALLY_CLOSED){
            temp_logic = GPIO_HIGH ;
        }
        else if(relay->relay_normarl_state == RELAY_NORMALLY_OPEN){
            temp_logic = GPIO_LOW ;
        }
        ret = gpio_pin_write_logic( &(relay->relay_pin), temp_logic);
        if(ret != E_NOT_OK)
            relay->relay_status = RELAY_OFF_STATUS;
        
    }
    return ret;
}
