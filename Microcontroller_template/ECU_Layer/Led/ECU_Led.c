/* 
 * File:   ECU_Led.h
 * Author: GAMING STORE
 *
 * Created on July 20, 2023, 7:18 AM
 */

#include "ECU_Led.h"
/**
 * @brief this function intialize the pin to be out and turn led off @ref led_t
 * @param led :pointer to the led module
 * @return status of the function
 *         E_ok :if the fuction executed in a right way
 *         E_nok:if the function didn't execute in a right way
 */
std_returntype led_intialize(const led_t *led)
{
    pin_config_t obj ={.port=led->port_name,.pin=led->pin,.logic=led->led_status,.direction=output};
    std_returntype ret=E_ok;
    if(NULL == led)
    {
        ret=E_nok;
    }
    else
    {
        gpio_pin_intialize(&obj);
    }
    return ret;
}
/**
 * @brief this function turn the led on @ref led_status
 * @param led :pointer to the led module
 * @return status of the function
 *         E_ok :if the fuction executed in a right way
 *         E_nok:if the function didn't execute in a right way
 */
std_returntype led_turn_on(const led_t *led)
{
    pin_config_t obj ={.port=led->port_name,.pin=led->pin,.logic=led->led_status,.direction=output};
    std_returntype ret=E_ok;
    if(NULL == led)
    {
        ret=E_nok;
    }
    else
    {
        gpio_pin_write_logic(&obj,high);
    }
    return ret;
}
/**
 * @brief this function turn the led off @ref led_status
 * @param led :pointer to the led module
 * @return status of the function
 *         E_ok :if the fuction executed in a right way
 *         E_nok:if the function didn't execute in a right way
 */
std_returntype led_turn_off(const led_t *led)
{
    pin_config_t obj ={.port=led->port_name,.pin=led->pin,.logic=led->led_status,.direction=output};
    std_returntype ret=E_ok;
    if(NULL == led)
    {
        ret=E_nok;
    }
    else
    {
        gpio_pin_write_logic(&obj,low);
    }
    return ret;
}
/**
 * @brief this function toggle the status of the led
 * @param led :pointer to the led module
 * @return status of the function
 *         E_ok :if the fuction executed in a right way
 *         E_nok:if the function didn't execute in a right way 
 */
std_returntype led_toggle(const led_t *led)
{
    pin_config_t obj ={.port=led->port_name,.pin=led->pin,.logic=led->led_status,.direction=output};
    std_returntype ret=E_ok;
    if(NULL == led)
    {
        ret=E_nok;
    }
    else
    {
        gpio_pin_toggle_logic(&obj);
    }
    return ret;
}