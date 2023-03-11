#include "7_SEGMENTS.h"



#if SVS_BCD_NOT_BCD == SVS_NOT_BCD
Std_ReturnType SVS_initialize(const SVS_config_t *Seven_SEG){
    Std_ReturnType ret = E_OK;
    
    if(Seven_SEG == NULL){
        ret =E_NOT_OK;
    }
    else{
        
        ret = gpio_port_direction_initialize(Seven_SEG->SVS_port, 0x00);
    }
    return ret;

}
Std_ReturnType SVS_print(const SVS_config_t *Seven_SEG, SVS_data_t data){
    Std_ReturnType ret = E_OK;
    
    if(Seven_SEG == NULL){
        ret =E_NOT_OK;
    }
    else{
        uint8 temp = (uint8)data;
        #if (SVS_COMMON_ANODE_CATHODE == COMMON_ANODE)
        temp = (uint8)(~data);
        ret = gpio_port_write_logic(Seven_SEG->SVS_port, temp);
        #elif SVS_COMMON_ANODE_CATHODE == COMMON_CATHODE
        ret = gpio_port_write_logic(Seven_SEG->SVS_port, temp);
        #endif
    }
    return ret;

}
#elif SVS_BCD_NOT_BCD == SVS_BCD
Std_ReturnType SVS_initialize(const SVS_config_t *Seven_SEG){
    Std_ReturnType ret = E_OK;
    
    if(Seven_SEG == NULL){
        ret =E_NOT_OK;
    }
    else{
        pin_config_t temp;
        temp.port = Seven_SEG->SVS_port;
        temp.direction= GPIO_DIRECTION_OUTPUT;
        
        if(Seven_SEG->SVS_nibble_state == SVS_LOW_NIBBLE){
            gpio_port_low_nibble_direction_initialize(&temp, 0xF0);
        }else if(Seven_SEG->SVS_nibble_state == SVS_HIGH_NIBBLE){
            gpio_port_high_nibble_direction_initialize(&temp, 0x0F);
        
        }
        #if SVS_POV_ON_OFF == SVS_POV_ON
        int svs_counter = 0;
        
        temp.direction = GPIO_DIRECTION_OUTPUT;
        for(;svs_counter<SVS_MAX_NO; svs_counter++){
                temp.port = Seven_SEG->SVS_EN_PINS[svs_counter].SVS_en_port;
                temp.pin = Seven_SEG->SVS_EN_PINS[svs_counter].SVS_en_pin;
                gpio_pin_direction_initialize(&temp);
                
        }
        #endif
        
        
    }
    return ret;
}
Std_ReturnType SVS_print(const SVS_config_t *Seven_SEG, SVS_data_t data){
    Std_ReturnType ret = E_OK;
    
    if(Seven_SEG == NULL){
        ret =E_NOT_OK;
    }
    else{
        pin_config_t temp;
        temp.port = Seven_SEG->SVS_port;
        temp.direction= GPIO_DIRECTION_OUTPUT;
        
        if(Seven_SEG->SVS_nibble_state == SVS_LOW_NIBBLE){
            gpio_port_low_nibble_write_logic(&temp, data);
        }else if(Seven_SEG->SVS_nibble_state == SVS_HIGH_NIBBLE){
            gpio_port_high_nibble_write_logic(&temp, data);
        
        }
    }
    return ret;
}
#if SVS_POV_ON_OFF == SVS_POV_ON
    Std_ReturnType SVS_print_pov(SVS_config_t *Seven_SEG, uint8 *data){
        Std_ReturnType ret = E_OK;
    
        if(Seven_SEG == NULL){
            ret =E_NOT_OK;
        }
        else{
            
            pin_config_t temp ;
            for(uint8 svs_counter_2 = 0 ;svs_counter_2<SVS_MAX_NO; svs_counter_2++){
                
                temp.port = Seven_SEG->SVS_EN_PINS[svs_counter_2].SVS_en_port;
                temp.pin = Seven_SEG->SVS_EN_PINS[svs_counter_2].SVS_en_pin;
                gpio_pin_write_logic( &temp, GPIO_HIGH);    
            }
            uint8 svs_counter = 0;
            for(;svs_counter<SVS_MAX_NO; svs_counter++){
                if(svs_counter != 0){
                    temp.port = Seven_SEG->SVS_EN_PINS[svs_counter-1].SVS_en_port;
                    temp.pin = Seven_SEG->SVS_EN_PINS[svs_counter-1].SVS_en_pin;
                    gpio_pin_write_logic( &temp, GPIO_HIGH);  
                }
                temp.port = Seven_SEG->SVS_EN_PINS[svs_counter].SVS_en_port;
                temp.pin = Seven_SEG->SVS_EN_PINS[svs_counter].SVS_en_pin;
                gpio_pin_write_logic( &temp, GPIO_LOW);
                SVS_print(Seven_SEG, data[svs_counter]);
                for(long l =0; l<=500;l++);
            }
            
        }
        return ret;
    
    }
#endif

#endif
