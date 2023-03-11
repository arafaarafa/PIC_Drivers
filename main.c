/* 
 * File:   main.c
 * Author: Arafa
 *
 * Created on February 11, 2023, 9:27 PM
 */

#include "application.h"
#include "ECU_layer/DC_MOTOR/DC_MOTOR.h"
#include "ECU_layer/7_SEGMENTS/7_SEGMENTS.h"



/*
 * 
 */

Std_ReturnType ret= E_OK;
/*led_t led_0 = {.port_name = PORTA_INDEX , .pin = PIN0, .led_status = LED_ON };
led_t led_1 = {.port_name = PORTA_INDEX , .pin = PIN1, .led_status = LED_ON };
led_t led_2 = {.port_name = PORTA_INDEX , .pin = PIN2, .led_status = LED_OFF };
button_t btn_0 = {.button_pin.port=PORTA_INDEX,
                    .button_pin.direction = GPIO_DIRECTION_INPUT,
                    .button_pin.pin =PIN5,
                    .button_pin.logic = GPIO_LOW,
                    .button_state =BUTTON_RELEASED,.button_active= BUTTON_ACTIVE_HIGH };

button_t btn_1 = {.button_pin.port=PORTB_INDEX,
                    .button_pin.direction = GPIO_DIRECTION_INPUT,
                    .button_pin.pin =PIN0,
                    .button_pin.logic = GPIO_LOW,
                    .button_state =BUTTON_RELEASED,.button_active= BUTTON_ACTIVE_LOW};

relay_t relay_NC={.relay_pin.port=PORTB_INDEX,
                    .relay_pin.direction = GPIO_DIRECTION_OUTPUT,
                    .relay_pin.pin =PIN1,
                    .relay_pin.logic = GPIO_LOW,
                    .relay_status = RELAY_ON_STATUS,
                    .relay_normarl_state = RELAY_NORMALLY_CLOSED};

relay_t relay_NO={.relay_pin.port=PORTB_INDEX,
                    .relay_pin.direction = GPIO_DIRECTION_OUTPUT,
                    .relay_pin.pin =PIN2,
                    .relay_pin.logic = GPIO_LOW,
                    .relay_status = RELAY_OFF_STATUS,
                    .relay_normarl_state = RELAY_NORMALLY_OPEN};


dc_motor_config_t motor_1 = {
    .dc_motor_pins[0].port =PORTB_INDEX,
    .dc_motor_pins[0].pin = PIN3,
    .dc_motor_pins[0].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor_pins[1].port =PORTB_INDEX,
    .dc_motor_pins[1].pin = PIN4,
    .dc_motor_pins[1].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor_EN.port =PORTB_INDEX,
    .dc_motor_EN.pin = PIN5,
    .dc_motor_EN.direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor_status = DC_MOTOR_OFF,
    
    
};*/
SVS_config_t seven_seg ={.SVS_port = PORTD_INDEX,
                            .SVS_nibble_state = SVS_LOW_NIBBLE
                            ,.SVS_EN_PINS[0].SVS_en_pin=PIN6,
                            .SVS_EN_PINS[0].SVS_en_port = PORTC_INDEX
                            ,.SVS_EN_PINS[1].SVS_en_pin=PIN7,
                            .SVS_EN_PINS[1].SVS_en_port = PORTC_INDEX,
                            .SVS_EN_PINS[2].SVS_en_pin=PIN4,
                            .SVS_EN_PINS[2].SVS_en_port = PORTD_INDEX,
                            .SVS_EN_PINS[3].SVS_en_pin=PIN5,
                            .SVS_EN_PINS[3].SVS_en_port = PORTD_INDEX,
                            .SVS_EN_PINS[4].SVS_en_pin=PIN6,
                            .SVS_EN_PINS[4].SVS_en_port = PORTD_INDEX
                            ,.SVS_EN_PINS[5].SVS_en_pin=PIN7,
                            .SVS_EN_PINS[5].SVS_en_port = PORTD_INDEX};



int main() {
   
    appliction_intialize();
    uint8 data[SVS_MAX_NO ]= {1,2,3,4,5,6};
    while(1){
        /*relay_turn_on(&relay_NC);
        relay_turn_on(&relay_NO);


        __delay_ms(5000);
        relay_turn_off(&relay_NC);
        relay_turn_off(&relay_NO);
        
        motor_turn_on(&motor_1, DC_MOTOR_RIGHT );
        __delay_ms(5000);
         motor_turn_on(&motor_1, DC_MOTOR_LEFT );
        __delay_ms(5000);
        motor_stop(&motor_1);
        __delay_ms(5000);*/
        
        
            
            for(uint8 counter = 0; counter<SVS_MAX_NO ; counter++){
                data[counter]++;
                if(data[counter]>9){
                    data[counter]=0;
                }
                SVS_print_pov(&seven_seg, data);
                __delay_ms(30);
            }
           
            
            

    }
    return (EXIT_SUCCESS);
}

void appliction_intialize(void){
    ADCON0 = 0x00;
    ADCON1 = 0x0F;
    /*led_intialize(&led_0);
    led_intialize(&led_1);
    led_intialize(&led_2);
    button_initializa(&btn_0);
    button_initializa(&btn_1);
    relay_initialize(&relay_NC);
    relay_initialize(&relay_NO);
    
    motor_initialize(&motor_1);*/
    SVS_initialize(&seven_seg);
    
    
}

 