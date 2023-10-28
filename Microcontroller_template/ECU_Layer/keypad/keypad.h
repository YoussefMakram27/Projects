/* 
 * File:   keypad.h
 * Author: GAMING STORE
 *
 * Created on August 31, 2023, 10:23 AM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

/*section includes*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*section macro declaration*/

#define keypad_rows     4
#define keypad_columns  4

/*section function like macro*/



/*data type declaration*/

typedef struct 
{
    pin_config_t keypad_rows_pins[keypad_rows];
    pin_config_t keypad_columns_pins[keypad_columns];
}keypad_t;


/*section function declaration*/

std_returntype keypad_intialize(const keypad_t *_keypad);
std_returntype keypad_get_value(const keypad_t *_keypad, uint8 *value);


#endif	/* KEYPAD_H */

