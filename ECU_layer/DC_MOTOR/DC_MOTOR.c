#include "DC_MOTOR.h"


Std_ReturnType motor_initialize(const dc_motor_config_t *dc_motor){
    Std_ReturnType ret = E_OK;
    
    if(dc_motor == NULL){
        ret =E_NOT_OK;
    }
    else{
        gpio_pin_direction_initialize(&(dc_motor->dc_motor_pins[0]));
        gpio_pin_direction_initialize(&(dc_motor->dc_motor_pins[1]));
        gpio_pin_direction_initialize(&(dc_motor->dc_motor_EN));
    }
    return ret;
}
Std_ReturnType motor_turn_on(dc_motor_config_t *dc_motor, dc_motor_direction_t dc_motor_direction ){
    Std_ReturnType ret = E_OK;
    
    if(dc_motor == NULL){
        ret =E_NOT_OK;
    }
    else{
        
         // need to change when define PWM
        if(dc_motor_direction == DC_MOTOR_RIGHT){
            gpio_pin_write_logic(&(dc_motor->dc_motor_pins[0]), GPIO_HIGH);
            gpio_pin_write_logic(&(dc_motor->dc_motor_pins[1]), GPIO_LOW);
            dc_motor->dc_motor_direction = DC_MOTOR_RIGHT;
        }
        else if(dc_motor_direction == DC_MOTOR_LEFT)
        {
            gpio_pin_write_logic(&(dc_motor->dc_motor_pins[0]), GPIO_LOW);
            gpio_pin_write_logic(&(dc_motor->dc_motor_pins[1]), GPIO_HIGH);
            dc_motor->dc_motor_direction = DC_MOTOR_LEFT;
        }
        else{
            ret =E_NOT_OK;
        }  
        
        if(ret == E_OK){
            gpio_pin_write_logic(&(dc_motor->dc_motor_EN), GPIO_HIGH);
            dc_motor->dc_motor_status = DC_MOTOR_ON;
        }
    }
    return ret;
}
Std_ReturnType motor_stop(dc_motor_config_t *dc_motor){
    Std_ReturnType ret = E_OK;
    
    if(dc_motor == NULL){
        ret =E_NOT_OK;
    }
    else{
        gpio_pin_write_logic(&(dc_motor->dc_motor_EN), GPIO_LOW); // need to change when define PWM
        dc_motor->dc_motor_status = DC_MOTOR_OFF;
    }
    return ret;
}
Std_ReturnType motor_set_speed(dc_motor_config_t *dc_motor, uint8 dc_motor_speed) { //to do
    Std_ReturnType ret = E_OK;
    
    if(dc_motor == NULL){
        ret =E_NOT_OK;
    }
    else{
        
    }
    return ret;
}
