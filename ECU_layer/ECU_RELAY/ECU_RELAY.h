/* 
 * File:   ECU_RELAY.h
 * Author: Arafa
 *
 * Created on February 25, 2023, 10:33 AM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/* section : includes*/
#include "../../MCAL_layer/GPIO/GPIO.h"


/* section : Macro Declaration*/


/* section : Macro Functions Declarations*/

/* section : Data Types Declarations*/
typedef enum {
    RELAY_OFF_STATUS =0,
    RELAY_ON_STATUS
}relay_status_t;

typedef enum {
    RELAY_NORMALLY_OPEN =0,
    RELAY_NORMALLY_CLOSED
}relay_normarl_state_t;
typedef struct{
    pin_config_t relay_pin;
    relay_status_t relay_status;
    relay_normarl_state_t relay_normarl_state;
}relay_t;
/* section : Function Declaration*/

Std_ReturnType relay_initialize(const relay_t *relay);
Std_ReturnType relay_turn_on(relay_t *relay);
Std_ReturnType relay_turn_off(relay_t *relay);

#endif	/* ECU_RELAY_H */

