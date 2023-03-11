/* 
 * File:   7_SEGMENTS.h
 * Author: Arafa
 *
 * Created on March 3, 2023, 4:44 PM
 */

#ifndef SEGMENTS_H
#define	SEGMENTS_H

/* section : includes*/
#include "7_SEGMENTS_CONFIG.h"
#include "../../MCAL_layer/GPIO/GPIO.h"



/* section : Macro Declaration*/


/* section : Macro Functions Declarations*/

/* section : Data Types Declarations*/

#if SVS_BCD_NOT_BCD == SVS_NOT_BCD
typedef enum {
            SV_0=0b00111111 ,
            SV_1=0b00000110 ,
            SV_2=0b1011011 ,  
            SV_3=0b1001111,	
            SV_4=0b1100110,
            SV_5=0b1101101,
            SV_6=0b1111101,
            SV_7=0b0000111,
            SV_8=0b1111111,
            SV_9=0b1001111
            
} SVS_data_t;
typedef struct{
    port_index_t SVS_port;
}SVS_config_t;
#elif SVS_BCD_NOT_BCD == SVS_BCD
typedef enum {
            SV_0=0,
            SV_1,
            SV_2,  
            SV_3,	
            SV_4,
            SV_5,
            SV_6,
            SV_7,
            SV_8,
            SV_9
            
} SVS_data_t;

typedef enum{
    SVS_LOW_NIBBLE=0,
    SVS_HIGH_NIBBLE        
}SVS_nibble_state_t;

#if SVS_POV_ON_OFF == SVS_POV_ON
typedef struct {
    port_index_t SVS_en_port;
    pin_index_t  SVS_en_pin;   
}SVS_en_pin_t;

typedef struct{
    port_index_t SVS_port;
    SVS_nibble_state_t  SVS_nibble_state;
    SVS_en_pin_t SVS_EN_PINS[SVS_MAX_NO];
}SVS_config_t;
#elif SVS_POV_ON_OFF == SVS_POV_OFF
typedef struct{
    port_index_t SVS_port;
    SVS_nibble_state_t  SVS_nibble_state;
}SVS_config_t;
#endif
#endif


/* section : Function Declaration*/
Std_ReturnType SVS_initialize(const SVS_config_t *Seven_SEG);
Std_ReturnType SVS_print(const SVS_config_t *Seven_SEG, SVS_data_t data);
#if SVS_POV_ON_OFF == SVS_POV_ON
    Std_ReturnType SVS_print_pov(SVS_config_t *Seven_SEG, uint8 *data);
#endif


#endif	/* 7_SEGMENTS_H */

