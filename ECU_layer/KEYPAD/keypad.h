/* 
 * File:   keypad.h
 * Author: Arafa
 *
 * Created on March 12, 2023, 6:16 PM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

/* section : includes*/
#include "keypad_config.h"
#include "../../MCAL_layer/GPIO/GPIO.h"

/* section : Macro Declaration*/


/* section : Macro Functions Declarations*/

/* section : Data Types Declarations*/
typedef struct {
    port_index_t keypad_pin_port;
    pin_index_t  keypad_pin;   
}keypad_pin_t;

typedef struct{
    keypad_pin_t keypad_rows[KEYPAD_MAX_ROWS_NO];
    keypad_pin_t keypad_cols[KEYPAD_MAX_COLS_NO];
}keypad_config_t;

/* section : Function Declaration*/
Std_ReturnType keypad_initialize(const keypad_config_t *keypad_config);
Std_ReturnType keypad_get_value(const keypad_config_t *keypad_config, char *value);

#endif	/* KEYPAD_H */

