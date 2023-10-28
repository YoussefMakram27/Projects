/* 
 * File:   dc_motor.h
 * Author: GAMING STORE
 *
 * Created on August 13, 2023, 3:58 PM
 */

#ifndef DC_MOTOR_H
#define	DC_MOTOR_H

/*section includes*/

#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*section macro declaration*/

#define dc_motor_status_on  0x01
#define dc_motor_status_off 0x00

#define motor_pin1 0
#define motor_pin2 1

/*section function like macro*/



/*data type declaration*/

typedef struct
{
    pin_config_t dc_motor_pin[2];
}dc_motor_t;

/*Interfaces Software declaration*/

std_returntype dc_motor_intialize  (const dc_motor_t *_dc_motor);
std_returntype dc_motor_move_right (const dc_motor_t *_dc_motor);
std_returntype dc_motor_move_left  (const dc_motor_t *_dc_motor);
std_returntype dc_motor_stop       (const dc_motor_t *_dc_motor);

#endif	/* DC_MOTOR_H */

