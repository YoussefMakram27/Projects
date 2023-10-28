/* 
 * File:   Ecu_Relay.c
 * Author: GAMING STORE
 *
 * Created on August 11, 2023, 2:41 PM
 */
#include "Ecu_Relay.h"

/**
 * @brief this function intialize the pin to be output,and the status of the pin is low
 * @param _relay :pointer to relay module @ref relay_t
 * @return status of the function 
 *         E_ok  :if function executed in a right way
 *         E_nok :if function didn't execute in a right way
 */
std_returntype relay_intialize(const relay_t *_relay)
{
    std_returntype ret = E_ok;
    if(NULL == _relay)
    {
        ret = E_nok;
    }
    else
    {
        pin_config_t obj = {.port = _relay->relay_port , .pin = _relay->relay_pin ,
                            .logic = _relay->relay_status , .direction = output};
        gpio_pin_intialize(&obj);
    }
}
/**
 * @brief this function turn the relay on
 * @param _relay :pointer to relay module @ref relay_t
 * @return status of the function 
 *         E_ok  :if function executed in a right way
 *         E_nok :if function didn't execute in a right way
 */
std_returntype relay_turn_on(const relay_t *_relay)
{
    std_returntype ret = E_ok;
    if(NULL == _relay)
    {
        ret = E_nok;
    }
    else
    {
        pin_config_t obj = {.port = _relay->relay_port , .pin = _relay->relay_pin ,
                            .logic = _relay->relay_status , .direction = output};
        gpio_pin_write_logic(&obj,high);
    }
}
/**
 * @brief this  function turn the relay off
 * @param _relay :pointer to relay module @ref relay_t
 * @return status of the function 
 *         E_ok  :if function executed in a right way
 *         E_nok :if function didn't execute in a right way
 */
std_returntype relay_turn_off(const relay_t *_relay)
{
    std_returntype ret = E_ok;
    if(NULL == _relay)
    {
        ret = E_nok;
    }
    else
    {
        pin_config_t obj = {.port = _relay->relay_port , .pin = _relay->relay_pin ,
                            .logic = _relay->relay_status , .direction = output};
        gpio_pin_write_logic(&obj,low);
    }
}