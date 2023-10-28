/* 
 * File:   Ecu_init.h
 * Author: GAMING STORE
 *
 * Created on August 31, 2023, 2:10 PM
 */

#ifndef ECU_INIT_H
#define	ECU_INIT_H

#include "keypad/keypad.h"
#include "char_Lcd/char_Lcd.h"


lcd_4_bit_t lcd_1 =
{
    .en.port      = port_C,
    .en.pin       = pin_1,
    .en.direction = output,
    .en.logic     = low,
    .rs.port      = port_C,
    .rs.pin       = pin_0,
    .rs.direction = output,
    .rs.logic     = low,
    .data[0].port      = port_C,
    .data[0].pin       = pin_2,
    .data[0].direction = output,
    .data[0].logic     = low,
    .data[1].port      = port_C,
    .data[1].pin       = pin_3,
    .data[1].direction = output,
    .data[1].logic     = low,
    .data[2].port      = port_C,
    .data[2].pin       = pin_4,
    .data[2].direction = output,
    .data[2].logic     = low,
    .data[3].port      = port_C,
    .data[3].pin       = pin_5,
    .data[3].direction = output,
    .data[3].logic     = low,
};

lcd_8_bit_t lcd_2 =
{
    .en.port      = port_C,
    .en.pin       = pin_7,
    .en.direction = output,
    .en.logic     = low,
    .rs.port      = port_C,
    .rs.pin       = pin_6,
    .rs.direction = output,
    .rs.logic     = low,
    .data[0].port      = port_D,
    .data[0].pin       = pin_0,
    .data[0].direction = output,
    .data[0].logic     = low,
    .data[1].port      = port_D,
    .data[1].pin       = pin_1,
    .data[1].direction = output,
    .data[1].logic     = low,
    .data[2].port      = port_D,
    .data[2].pin       = pin_2,
    .data[2].direction = output,
    .data[2].logic     = low,
    .data[3].port      = port_D,
    .data[3].pin       = pin_3,
    .data[3].direction = output,
    .data[3].logic     = low,
    .data[4].port      = port_D,
    .data[4].pin       = pin_4,
    .data[4].direction = output,
    .data[4].logic     = low,
    .data[5].port      = port_D,
    .data[5].pin       = pin_5,
    .data[5].direction = output,
    .data[5].logic     = low,
    .data[6].port      = port_D,
    .data[6].pin       = pin_6,
    .data[6].direction = output,
    .data[6].logic     = low,
    .data[7].port      = port_D,
    .data[7].pin       = pin_7,
    .data[7].direction = output,
    .data[7].logic     = low,
};






uint8 common_cathode[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0xEF};
uint8 ones,tens;
uint8 number = 0;
uint8 new_num;
uint8 hours = 23,minutes = 59,seconds = 50;

keypad_t keypad_1 =
{
  .keypad_rows_pins[0].port = port_C,
  .keypad_rows_pins[0].pin = pin_0,
  .keypad_rows_pins[0].direction = output,
  .keypad_rows_pins[0].logic = low,
  .keypad_rows_pins[1].port = port_C,
  .keypad_rows_pins[1].pin = pin_1,
  .keypad_rows_pins[1].direction = output,
  .keypad_rows_pins[1].logic = low,
  .keypad_rows_pins[2].port = port_C,
  .keypad_rows_pins[2].pin = pin_2,
  .keypad_rows_pins[2].direction = output,
  .keypad_rows_pins[2].logic = low,
  .keypad_rows_pins[3].port = port_C,
  .keypad_rows_pins[3].pin = pin_3,
  .keypad_rows_pins[3].direction = output,
  .keypad_rows_pins[3].logic = low,  
  .keypad_columns_pins[0].port = port_C,
  .keypad_columns_pins[0].pin = pin_4,
  .keypad_columns_pins[0].direction = input,
  .keypad_columns_pins[0].logic = low,
  .keypad_columns_pins[1].port = port_C,
  .keypad_columns_pins[1].pin = pin_5,
  .keypad_columns_pins[1].direction = input,
  .keypad_columns_pins[1].logic = low,
  .keypad_columns_pins[2].port = port_C,
  .keypad_columns_pins[2].pin = pin_6,
  .keypad_columns_pins[2].direction = input,
  .keypad_columns_pins[2].logic = low,
  .keypad_columns_pins[3].port = port_C,
  .keypad_columns_pins[3].pin = pin_7,
  .keypad_columns_pins[3].direction = input,
  .keypad_columns_pins[3].logic = low,
};

led_t led1 = {.port_name=port_C,.pin=pin_0,.led_status=led_off};
led_t led2 = {.port_name=port_C,.pin=pin_1,.led_status=led_off};
led_t led3 = {.port_name=port_C,.pin=pin_2,.led_status=led_off};
led_t led4 = {.port_name=port_C,.pin=pin_3,.led_status=led_off};

button_t btn1 ={.btn_pin.port=port_C,.btn_pin.pin=pin_2,.btn_pin.direction=input,
.btn_pin.logic=low,.btn_connection=button_active_high,.btn_state=button_released,};

button_state_t btn1_state =button_released;
button_state_t btn1_valid_state =button_released;
button_state_t btn1_last_valid_state =button_released;
button_state_t btn2_state =button_released;

led_status  led_s= led_off;
uint32 counter=0;
uint8 flag=0;
uint8 program_selected=0;

relay_t relay1 = {.relay_port = port_C , .relay_pin = pin_0 , .relay_status = relay_status_off};

#endif	/* ECU_INIT_H */

