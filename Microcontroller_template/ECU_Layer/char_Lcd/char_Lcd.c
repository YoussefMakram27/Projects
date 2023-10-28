/* 
 * File:   char_Lcd.c
 * Author: Youssef M.Makram
 *
 * Created on September 9, 2023, 8:00 AM
 */

#include "char_Lcd.h"

static std_returntype lcd_send_4_bits(const lcd_4_bit_t *_lcd, uint8 data);
static std_returntype lcd_send_8_bits(const lcd_8_bit_t *_lcd, uint8 data);
static std_returntype lcd_4_bit_set_cursor(const lcd_4_bit_t *_lcd, uint8 row, uint8 column);
static std_returntype lcd_8_bit_set_cursor(const lcd_8_bit_t *_lcd, uint8 row, uint8 column);
static std_returntype lcd_4_bit_send_enable(const lcd_4_bit_t *_lcd);
static std_returntype lcd_8_bit_send_enable(const lcd_8_bit_t *_lcd);

std_returntype lcd_4_bit_intialize(const lcd_4_bit_t *_lcd)
{
    std_returntype ret = E_ok;
    uint8 counter = 0;
    if(NULL == _lcd)
    {
        ret = E_nok;
    }
    else
    {
        ret = gpio_pin_intialize(&(_lcd->en));
        ret = gpio_pin_intialize(&(_lcd->rs));
        for(counter = 0;counter < 4;counter++)
        {
            ret = gpio_pin_intialize(&(_lcd->data[counter]));
        }
        __delay_ms(20);
        ret = lcd_4_bit_send_command(_lcd, _lcd_8_bit_2_lines);
        __delay_ms(5);
        ret = lcd_4_bit_send_command(_lcd, _lcd_8_bit_2_lines);
        __delay_ms(1);
        ret = lcd_4_bit_send_command(_lcd, _lcd_8_bit_2_lines);
        
        ret = lcd_4_bit_send_command(_lcd, _lcd_clear_display);
        ret = lcd_4_bit_send_command(_lcd, _lcd_return_home);
        ret = lcd_4_bit_send_command(_lcd, _lcd_entrymode_increment_shift_off);
        ret = lcd_4_bit_send_command(_lcd, _lcd_display_on_cursor_on_blink_off);
        ret = lcd_4_bit_send_command(_lcd, _lcd_4_bit_2_lines);
        ret = lcd_4_bit_send_command(_lcd, _lcd_ddram_start);
        
    }
    return ret;
}
std_returntype lcd_4_bit_send_char       (const lcd_4_bit_t *_lcd, uint8 data)
{
    std_returntype ret = E_ok;
    if(NULL == _lcd)
    {
        ret = E_nok;
    }
    else
    {
        ret = gpio_pin_write_logic(&(_lcd->rs), high);
        
        ret = lcd_send_4_bits(_lcd, data >> 4);
        ret = lcd_4_bit_send_enable(_lcd);
        ret = lcd_send_4_bits(_lcd, data);
        ret = lcd_4_bit_send_enable(_lcd);
    }
    return ret;
}
std_returntype lcd_4_bit_send_char_pos   (const lcd_4_bit_t *_lcd, uint8 data, uint8 row, uint8 column)
{
    std_returntype ret = E_ok;
    if(NULL == _lcd)
    {
        ret = E_nok;
    }
    else
    {
        ret = lcd_4_bit_set_cursor(_lcd, row, column);
        
        ret = gpio_pin_write_logic(&(_lcd->rs), high);
        ret = lcd_send_4_bits(_lcd, data >> 4);
        ret = lcd_4_bit_send_enable(_lcd);
        ret = lcd_send_4_bits(_lcd, data);
        ret = lcd_4_bit_send_enable(_lcd);
    }
    return ret;
}
std_returntype lcd_4_bit_send_string     (const lcd_4_bit_t *_lcd, uint8 *str)
{
    std_returntype ret = E_ok;
    uint8 counter = 0;
    if(NULL == _lcd)
    {
        ret = E_nok;
    }
    else
    {
        while(*str)
        {
            ret = lcd_4_bit_send_char(_lcd, *str);
            str++;
        }
        
        
    }
    return ret;
}
std_returntype lcd_4_bit_send_string_pos (const lcd_4_bit_t *_lcd, uint8 *str, uint8 row, uint8 column)
{
    std_returntype ret = E_ok;
    if(NULL == _lcd)
    {
        ret = E_nok;
    }
    else
    {
        ret = lcd_4_bit_set_cursor(_lcd, row, column);
        while(*str)
        {
            ret = lcd_4_bit_send_char(_lcd, *str);
            str++;
        }
    }
    return ret;
}
std_returntype lcd_4_bit_send_command (const lcd_4_bit_t *_lcd, uint8 command)
{
     std_returntype ret = E_ok;
    if(NULL == _lcd)
    {
        ret = E_nok;
    }
    else
    {
        ret = gpio_pin_write_logic(&(_lcd->rs), low);
        
        ret = lcd_send_4_bits(_lcd, command >> 4);
        ret = lcd_4_bit_send_enable(_lcd);
        ret = lcd_send_4_bits(_lcd, command); 
        ret = lcd_4_bit_send_enable(_lcd);
    }
    return ret;
}
std_returntype lcd_4_bit_send_custom_char(const lcd_4_bit_t *_lcd, uint8 row, uint8 column,
                                          const uint8 data[], uint8 mem_pos)
{
    uint8 counter = 0;
    mem_pos--;
    std_returntype ret = E_ok;
    if(NULL == _lcd)
    {
        ret = E_nok;
    }
    else
    {
        ret = lcd_4_bit_send_command(_lcd, (_lcd_cgram_start + mem_pos*8));
        for(counter = 0; counter < 8; counter++)
        {
            ret = lcd_4_bit_send_char(_lcd, data[counter]);
        }
        ret = lcd_4_bit_send_char_pos(_lcd, mem_pos, row, column);
    }
    return ret;
}

std_returntype lcd_8_bit_intialize(const lcd_8_bit_t *_lcd)
{
    std_returntype ret = E_ok;
    uint8 counter = 0;
    if(NULL == _lcd)
    {
        ret = E_nok;
    }
    else
    {
        ret = gpio_pin_intialize(&(_lcd->en));
        ret = gpio_pin_intialize(&(_lcd->rs));
        for(counter = 0;counter < 8;counter++)
        {
            ret = gpio_pin_intialize(&(_lcd->data[counter]));
        }
        __delay_ms(20);
        ret = lcd_8_bit_send_command(_lcd, _lcd_8_bit_2_lines);
        __delay_ms(5);
        ret = lcd_8_bit_send_command(_lcd, _lcd_8_bit_2_lines);
        __delay_ms(1);
        ret = lcd_8_bit_send_command(_lcd, _lcd_8_bit_2_lines);
        
        ret = lcd_8_bit_send_command(_lcd, _lcd_clear_display);
        ret = lcd_8_bit_send_command(_lcd, _lcd_return_home);
        ret = lcd_8_bit_send_command(_lcd, _lcd_entrymode_increment_shift_off);
        ret = lcd_8_bit_send_command(_lcd, _lcd_display_on_cursor_on_blink_off);
        ret = lcd_8_bit_send_command(_lcd, _lcd_8_bit_2_lines);
        ret = lcd_8_bit_send_command(_lcd, _lcd_ddram_start);
        
    }
    return ret;
}
std_returntype lcd_8_bit_send_char       (const lcd_8_bit_t *_lcd, uint8 data)
{
    std_returntype ret = E_ok;
    if(NULL == _lcd)
    {
        ret = E_nok;
    }
    else
    {
        ret = gpio_pin_write_logic(&(_lcd->rs), high);
        
        ret = lcd_send_8_bits(_lcd, data);
        ret = lcd_8_bit_send_enable(_lcd);
        
    }
    return ret;
}
std_returntype lcd_8_bit_send_char_pos   (const lcd_8_bit_t *_lcd, uint8 data, uint8 row, uint8 column)
{
    std_returntype ret = E_ok;
    if(NULL == _lcd)
    {
        ret = E_nok;
    }
    else
    {
        ret = lcd_8_bit_set_cursor(_lcd, row, column);
        ret = gpio_pin_write_logic(&(_lcd->rs), high);
        ret = lcd_send_8_bits(_lcd, data);
        ret = lcd_8_bit_send_enable(_lcd);
        
    }
    return ret;
}
std_returntype lcd_8_bit_send_string     (const lcd_8_bit_t *_lcd, uint8 *str)
{
    std_returntype ret = E_ok;
    uint8 counter = 0;
    if(NULL == _lcd)
    {
        ret = E_nok;
    }
    else
    {
        while(*str)
        {
            ret = lcd_8_bit_send_char(_lcd, *str);
            str++;
        }
    }
    return ret;
}
std_returntype lcd_8_bit_send_string_pos (const lcd_8_bit_t *_lcd, uint8 *str, uint8 row, uint8 column)
{
    std_returntype ret = E_ok;
    if(NULL == _lcd)
    {
        ret = E_nok;
    }
    else
    {
        ret = lcd_8_bit_set_cursor(_lcd, row, column);
        while(*str)
        {
            ret = lcd_8_bit_send_char(_lcd, *str);
            str++;
        }
    }
    return ret;
}
std_returntype lcd_8_bit_send_command (const lcd_8_bit_t *_lcd, uint8 command)
{
    std_returntype ret = E_ok;
    if(NULL == _lcd)
    {
        ret = E_nok;
    }
    else
    {
        ret = gpio_pin_write_logic(&(_lcd->rs), low);
        
        ret = lcd_send_8_bits(_lcd, command);
        ret = lcd_8_bit_send_enable(_lcd);
        
        
    }
    return ret;
}
std_returntype lcd_8_bit_send_custom_char(const lcd_8_bit_t *_lcd, uint8 row, uint8 column,
                                          const uint8 data[], uint8 mem_pos)
{
    std_returntype ret = E_ok;
    uint8 counter = 0;
    if(NULL == _lcd)
    {
        ret = E_nok;
    }
    else
    {
        ret = lcd_8_bit_send_command(_lcd, (_lcd_cgram_start + mem_pos*8));
        for(counter = 0; counter < 8; counter++)
        {
            ret = lcd_8_bit_send_char(_lcd, data[counter]);
        }
        ret = lcd_8_bit_send_char_pos(_lcd, mem_pos, row, column);
        
    }
    return ret;
}

std_returntype convert_uint8_to_string (uint8 num,uint8 *str)
{
    std_returntype ret = E_ok;
    if(NULL == str)
    {
        ret = E_nok;
    }
    else
    {
        memset(str,'\0', 4);
        sprintf(str, "%i", num);
    }
    return ret;
}
std_returntype convert_uint16_to_string(uint16 num,uint16 *str)
{
    std_returntype ret = E_ok;
    if(NULL == str)
    {
        ret = E_nok;
    }
    else
    {
        memset(str,'\0', 6);
        sprintf(str, "%i", num);
    }
    return ret;
}
std_returntype convert_uint32_to_string(uint32 num,uint32 *str)
{
    std_returntype ret = E_ok;
    if(NULL == str)
    {
        ret = E_nok;
    }
    else
    {
        memset(str,'\0', 11);
        sprintf(str, "%i", num);
    }
    return ret;
}
static std_returntype lcd_send_4_bits(const lcd_4_bit_t *_lcd, uint8 data)
{
    std_returntype ret =E_ok;
    ret = gpio_pin_write_logic(&(_lcd->data[0]), (data >> 0) & 0x01);
    ret = gpio_pin_write_logic(&(_lcd->data[1]), (data >> 1) & 0x01);
    ret = gpio_pin_write_logic(&(_lcd->data[2]), (data >> 2) & 0x01);
    ret = gpio_pin_write_logic(&(_lcd->data[3]), (data >> 3) & 0x01);
    return ret;
}
static std_returntype lcd_send_8_bits(const lcd_8_bit_t *_lcd, uint8 data)
{
    std_returntype ret =E_ok;
    ret = gpio_pin_write_logic(&(_lcd->data[0]), (data >> 0) & 0x01);
    ret = gpio_pin_write_logic(&(_lcd->data[1]), (data >> 1) & 0x01);
    ret = gpio_pin_write_logic(&(_lcd->data[2]), (data >> 2) & 0x01);
    ret = gpio_pin_write_logic(&(_lcd->data[3]), (data >> 3) & 0x01);
    ret = gpio_pin_write_logic(&(_lcd->data[4]), (data >> 4) & 0x01);
    ret = gpio_pin_write_logic(&(_lcd->data[5]), (data >> 5) & 0x01);
    ret = gpio_pin_write_logic(&(_lcd->data[6]), (data >> 6) & 0x01);
    ret = gpio_pin_write_logic(&(_lcd->data[7]), (data >> 7) & 0x01);
    return ret;
}
static std_returntype lcd_8_bit_set_cursor(const lcd_8_bit_t *_lcd, uint8 row, uint8 column)
{
    std_returntype ret =E_ok;
    column--;
    switch(row)
    {
    case row1:
        ret = lcd_8_bit_send_command(_lcd, 0X80 + column);
        break;
    case row2:
        ret = lcd_8_bit_send_command(_lcd, 0xC0 + column);
        break;
    case row3:
        ret = lcd_8_bit_send_command(_lcd, 0x94 + column);
        break;
    case row4:
        ret = lcd_8_bit_send_command(_lcd, 0xD4 + column);
        break;
    default:break;
    }
    return ret;
        
}
static std_returntype lcd_4_bit_set_cursor(const lcd_4_bit_t *_lcd, uint8 row, uint8 column)
{
    std_returntype ret =E_ok;
    column--;
    switch(row)
    {
    case row1:
        ret = lcd_4_bit_send_command(_lcd, (0X80 + column));
        break;
    case row2:
        ret = lcd_4_bit_send_command(_lcd, (0xC0 + column));
        break;
    case row3:
        ret = lcd_4_bit_send_command(_lcd, (0x94 + column));
        break;
    case row4:
        ret = lcd_4_bit_send_command(_lcd, (0xD4 + column));
        break;
    default:break;
    }
       return ret; 
}
static std_returntype lcd_4_bit_send_enable(const lcd_4_bit_t *_lcd)
{
    std_returntype ret = E_ok;
    ret = gpio_pin_write_logic(&(_lcd->en), high);
    __delay_us(5);
    ret = gpio_pin_write_logic(&(_lcd->en), low);
    return ret;
}
static std_returntype lcd_8_bit_send_enable(const lcd_8_bit_t *_lcd)
{
    std_returntype ret = E_ok;
    ret = gpio_pin_write_logic(&(_lcd->en), high);
    __delay_us(5);
    ret = gpio_pin_write_logic(&(_lcd->en), low);
    return ret;
}