/* 
 * File:   keypad.c
 * Author: GAMING STORE
 *
 * Created on August 31, 2023, 10:23 AM
 */
#include "keypad.h"


uint8 keypad_values[keypad_rows][keypad_columns] =
{
    {'7','8','9','/'},
    {'4','5','6','*'},
    {'1','2','3','-'},
    {'#','0','=','+'},
};


/**
 * 
 * @brief this function intialize rows pins of the keypad to be out,coumns pins to be input
 * @param _keypad pointer to value of type keypad_t
 * @return status of the function
 *         E_ok :if the fuction executed in a right way
 *         E_nok:if the function didn't execute in a right way
 */
std_returntype keypad_intialize(const keypad_t *_keypad)
{
    std_returntype ret = E_ok;
    uint8 rows_counter = 0, columns_counter = 0;
    if(NULL == _keypad)
    {
        ret = E_nok;
    }
    else
    {
        for(rows_counter = 0; rows_counter < keypad_rows; rows_counter++ )
        {
            ret = gpio_pin_intialize(&(_keypad->keypad_rows_pins[rows_counter]));
        }
        for(columns_counter = 0; columns_counter < keypad_columns; columns_counter++ )
        {
            ret = gpio_pin_intialize(&(_keypad->keypad_columns_pins[columns_counter]));
        }
    }   
    return ret;
}
/**
 * @brief this function scan keypad to be ready for the user to write numbers and return the number the user write
 * @param _keypad
 * @param value
 * @return status of the function
 *         E_ok :if the fuction executed in a right way
 *         E_nok:if the function didn't execute in a right way
 */
std_returntype keypad_get_value(const keypad_t *_keypad, uint8 *value)
{
    std_returntype ret = E_ok;
    uint8 rows_counter = 0, columns_counter = 0,counter = 0;
    uint8 status= 0;
    if(NULL == _keypad)
    {
        ret = E_nok;
    }
    else
    {
        for(rows_counter = 0;rows_counter < keypad_rows;rows_counter++)
        {
            for(counter = 0;counter < keypad_rows;counter++)
            {
                ret = gpio_pin_write_logic(&(_keypad->keypad_rows_pins[counter]), low);
            }
            ret = gpio_pin_write_logic(&(_keypad->keypad_rows_pins[rows_counter]),high);
            for(columns_counter = 0;columns_counter < keypad_columns; columns_counter++)
            {
                ret = gpio_pin_read_logic(&(_keypad->keypad_columns_pins[columns_counter]),&status);
                if(status == high)
                {
                    *value = keypad_values[rows_counter][columns_counter];
                }
            }
        }
    }   
    return ret;
}    

