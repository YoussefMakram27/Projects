/* 
 * File:   ecu_push_button.h
 * Author: GAMING STORE
 *
 * Created on August 4, 2023, 10:10 AM
 */

#ifndef ECU_PUSH_BUTTON_H
#define	ECU_PUSH_BUTTON_H

/*section includes*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*section macro declaration*/

/*section function like macro*/


/*data type declaration*/
typedef enum
{
    button_active_low,
    button_active_high,        
}button_active_state_t;
typedef enum
{
    button_released,
    button_pressed,        
}button_state_t;
typedef struct
{
    pin_config_t btn_pin;
    button_state_t btn_state;
    button_active_state_t btn_connection;
    
}button_t;


/*section function declaration*/

std_returntype button_initialize(const button_t *btn);
std_returntype button_read_state(const button_t *btn,button_state_t *btn_state);

#endif	/* ECU_PUSH_BUTTON_H */

