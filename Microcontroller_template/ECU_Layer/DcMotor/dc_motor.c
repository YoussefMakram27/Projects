/* 
 * File:   dc_motor.c
 * Author: GAMING STORE
 *
 * Created on August 13, 2023, 3:58 PM
 */
#include "dc_motor.h"



/**
 * @brief this funtion intialize the pin to be output and the motor to be off
 * @param _dc_motor pointer to dcmotor module @ref dc_motor_t
 * @return status of the function
 *         E_ok  if function executed in a right way
 *         E_nok if function didn't execute in a right way
 */
std_returntype dc_motor_intialize(const dc_motor_t *_dc_motor)
{
    std_returntype ret = E_ok;
    if(NULL == _dc_motor)
    {
        ret = E_nok;
    }
    else
    {
        gpio_pin_intialize(&(_dc_motor->dc_motor_pin[motor_pin1]));
        gpio_pin_intialize(&(_dc_motor->dc_motor_pin[motor_pin2]));
    }
    return ret;
}
/**
 * @brief this function move the motor right
 * @param _dc_motor pointer to dcmotor module @ref dc_motor_t
 * @return status of the function
 *         E_ok  if function executed in a right way
 *         E_nok if function didn't execute in a right way
 */
std_returntype dc_motor_move_right(const dc_motor_t *_dc_motor)
{
    std_returntype ret = E_ok;
    if(NULL == _dc_motor)
    {
        ret = E_nok;
    }
    else
    {
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[motor_pin1]),high);
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[motor_pin2]),low);
    }
    return ret;
}
/**
 * @brief this function move the motor left
 * @param _dc_motor pointer to dcmotor module @ref dc_motor_t
 * @return status of the function
 *         E_ok  if function executed in a right way
 *         E_nok if function didn't execute in a right way
 */
std_returntype dc_motor_move_left(const dc_motor_t *_dc_motor)
{
    std_returntype ret = E_ok;
    if(NULL == _dc_motor)
    {
        ret = E_nok;
    }
    else
    {
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[motor_pin1]),low);
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[motor_pin2]),high);
    }
}
/**
 * @brief this function stop the motor
 * @param _dc_motor pointer to dcmotor module @ref dc_motor_t
 * @return status of the function
 *         E_ok  if function executed in a right way
 *         E_nok if function didn't execute in a right way
 */
std_returntype dc_motor_stop(const dc_motor_t *_dc_motor)
{
    std_returntype ret = E_ok;
    if(NULL == _dc_motor)
    {
        ret = E_nok;
    }
    else
    {
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[motor_pin1]),low);
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[motor_pin2]),low);
    }
}