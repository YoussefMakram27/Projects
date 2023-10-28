/* 
 * File:   ECU_Led.h
 * Author: GAMING STORE
 *
 * Created on July 20, 2023, 7:18 AM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/*section includes*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*section macro declaration*/

/*section function like macro*/


/*data type declaration*/
typedef enum
{
    led_off,
    led_on,        
}led_status;
typedef struct
{
    uint8 port_name :3;
    uint8 pin       :3;
    uint8 led_status:1;
    uint8 reserved  :1;
    
}led_t;

/*section function declaration*/

std_returntype led_intialize(const led_t *led);
std_returntype led_turn_on(const led_t *led);
std_returntype led_turn_off(const led_t *led);
std_returntype led_toggle(const led_t *led);
#endif	/* ECU_LED_H */

