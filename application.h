/* 
 * File:   application.h
 * Author: Arafa
 *
 * Created on February 11, 2023, 10:45 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H



/* section : Macro Declaration*/
#define _XTAL_FREQ 16000000ul
/* section : includes*/
#include "ECU_layer/LED/LED.h"
#include "ECU_layer/PUSH_BUTTON/PUSH_BUTTON.h"
#include "ECU_layer/ECU_RELAY/ECU_RELAY.h"
#include "ECU_layer/7_SEGMENTS/7_SEGMENTS.h"


/* section : Macro Functions Declarations*/

/* section : Data Types Declarations*/

/* section : Function Declaration*/
void appliction_intialize(void);
#endif	/* APPLICATION_H */

