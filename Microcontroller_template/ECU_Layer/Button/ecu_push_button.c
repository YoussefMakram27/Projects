/* 
 * File:   ecu_push_button.c
 * Author: GAMING STORE
 *
 * Created on August 4, 2023, 10:10 AM
 */

#include "ecu_push_button.h"
/**
 * @brief this function initialize the assigned pin to be input
 * @param btn
 * @return status of the function
 *         E_ok :if the fuction executed in a right way
 *         E_nok:if the function didn't execute in a right way
 */
std_returntype button_initialize(const button_t *btn)
{
    std_returntype ret=E_ok;
    if(NULL == btn)
    {
        ret=E_nok;
    }
    else
    {
        gpio_pin_direction_intialize(&(btn->btn_pin));
    }
    return ret;
}
/**
 * @brief this function read the state of the button
 * @param btn
 * @param btn_state @ref btn_state_t
 * @return status of the function
 *         E_ok :if the fuction executed in a right way
 *         E_nok:if the function didn't execute in a right way 
 */
std_returntype button_read_state(const button_t *btn,button_state_t *btn_state)
{
    std_returntype ret=E_ok;
    logic_t btn_logic;
    if((NULL == btn) ||(NULL == btn_state))
    {
        ret=E_nok;
    }
    else
    {
        gpio_pin_read_logic(&(btn->btn_pin),&(btn_logic));
        if( button_active_high == btn->btn_connection)
        {
            
            if(btn_logic == high)
            {
                *btn_state=button_pressed;
            }
            else if(btn_logic == low)
            {
                *btn_state=button_released;
            }
            else{}
        }
        else if(button_active_low == btn->btn_connection)
        {
            
            if(btn_logic == high)
            {
                *btn_state=button_released;
            }
            else if(btn_logic == low)
            {
                *btn_state=button_pressed;
            }
            else{}
        }
        else{}
    }
    return ret;
}
