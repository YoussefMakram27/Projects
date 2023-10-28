/* 
 * File:   Ecu_Relay.h
 * Author: GAMING STORE
 *
 * Created on August 11, 2023, 2:41 PM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/*section includes*/

#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*section macro declaration*/

#define relay_status_on  0x01
#define relay_status_off 0x00

/*section function like macro*/


/*data type declaration*/

typedef struct 
{
    uint8 relay_port   :4;
    uint8 relay_pin    :3;
    uint8 relay_status :1;
}relay_t;

/*Interfaces Software declaration*/

std_returntype relay_intialize(const relay_t *_relay);
std_returntype relay_turn_on(const relay_t *_relay);
std_returntype relay_turn_off(const relay_t *_relay);

#endif	/* ECU_RELAY_H */

