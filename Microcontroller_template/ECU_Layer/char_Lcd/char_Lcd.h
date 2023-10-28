/* 
 * File:   char_Lcd.h
 * Author: GAMING STORE
 *
 * Created on September 9, 2023, 8:00 AM
 */

#ifndef CHAR_LCD_H
#define	CHAR_LCD_H

/*Includes Section*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*Macro Declaration Section*/
#define _lcd_clear_display                   0x01
#define _lcd_return_home                     0x02
#define _lcd_entrymode_decrement_shift_off   0x04
#define _lcd_entrymode_decrement_shift_on    0x05
#define _lcd_entrymode_increment_shift_off   0x06
#define _lcd_entrymode_increment_shift_on    0x07
#define _lcd_display_on_cursor_off_blink_off 0x0C
#define _lcd_display_on_cursor_on_blink_off  0x0E
#define _lcd_display_on_cursor_on_blink_on   0x0F
#define _lcd_display_shift_right             0x1c
#define _lcd_display_shift_left              0x18
#define _lcd_cursor_move_shift_right         0x14
#define _lcd_cursor_move_shift_left          0x10
#define _lcd_8_bit_2_lines                   0x38
#define _lcd_4_bit_2_lines                   0x28
#define _lcd_ddram_start                     0x80
#define _lcd_cgram_start                     0x40
#define row1                                 1
#define row2                                 2
#define row3                                 3
#define row4                                 4


/*Fuction Like Macro Section*/



/*Data Types Section*/

typedef struct 
{
    pin_config_t rs;
    pin_config_t en;
    pin_config_t data[4];
}lcd_4_bit_t;

typedef struct 
{
    pin_config_t rs;
    pin_config_t en;
    pin_config_t data[8];
}lcd_8_bit_t;


/*Software Interfaces Section*/

std_returntype lcd_4_bit_intialize       (const lcd_4_bit_t *_lcd);
std_returntype lcd_4_bit_send_char       (const lcd_4_bit_t *_lcd, uint8 data);
std_returntype lcd_4_bit_send_char_pos   (const lcd_4_bit_t *_lcd, uint8 data, uint8 row, uint8 column);
std_returntype lcd_4_bit_send_string     (const lcd_4_bit_t *_lcd, uint8 *str);
std_returntype lcd_4_bit_send_string_pos (const lcd_4_bit_t *_lcd, uint8 *str, uint8 row, uint8 column);
std_returntype lcd_4_bit_send_command (const lcd_4_bit_t *_lcd, uint8 command);
std_returntype lcd_4_bit_send_custom_char(const lcd_4_bit_t *_lcd, uint8 row, uint8 column,
                                          const uint8 data[], uint8 mem_pos);

std_returntype lcd_8_bit_intialize       (const lcd_8_bit_t *_lcd);
std_returntype lcd_8_bit_send_char       (const lcd_8_bit_t *_lcd, uint8 data);
std_returntype lcd_8_bit_send_char_pos   (const lcd_8_bit_t *_lcd, uint8 data, uint8 row, uint8 column);
std_returntype lcd_8_bit_send_string     (const lcd_8_bit_t *_lcd, uint8 *str);
std_returntype lcd_8_bit_send_string_pos (const lcd_8_bit_t *_lcd, uint8 *str, uint8 row, uint8 column);
std_returntype lcd_8_bit_send_command (const lcd_8_bit_t *_lcd, uint8 command);
std_returntype lcd_8_bit_send_custom_char(const lcd_8_bit_t *_lcd, uint8 row, uint8 column,
                                          const uint8 data[], uint8 mem_pos);

std_returntype convert_uint8_to_string (uint8 num,uint8 *str);
std_returntype convert_uint16_to_string(uint16 num,uint16 *str);
std_returntype convert_uint32_to_string(uint32 num,uint32 *str);
#endif	/* CHAR_LCD_H */

