/* 
 * File:   hal_gpio.h
 * Author: Youssef M.Makram
 *
 * Created on July 20, 2023, 7:00 AM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/*section includes*/

#include "pic18f4620.h"
#include "../std_types.h"
#include "../device_config.h"

/*section macro declaration*/

#define bit_mask              (uint8)1
#define pin_max_number        8
#define port_max_number       5
#define PIN_CONFIGURATION     CONFIG_ENABLE
#define PORT_CONFIGURATION    CONFIG_ENABLE
#define PORTC_MASK            0xff
/*section function like macro*/

#define hwreg(_x) (*((volatile uint8 *)(_x)))
#define set(reg,bit_pos)         (reg |= (bit_mask<<bit_pos))
#define clear(reg,bit_pos)       (reg &= ~(bit_mask<<bit_pos))
#define toggle(reg,bit_pos)      (reg ^= (bit_mask<<bit_pos))
#define read(reg,bit_pos)        ((reg >> bit_pos)&bit_mask)

/*data type declaration*/
std_returntype ret=E_nok;
typedef enum
{
    low=0,
    high,        
}logic_t;

typedef enum
{
    output=0,
    input,        
}direction_t;

typedef enum
{
    port_A=0,
    port_B,
    port_C,
    port_D,
    port_E,
}port_index_t;

typedef enum
{
    pin_0=0,
    pin_1,
    pin_2,       
    pin_3,      
    pin_4,
    pin_5,
    pin_6,
    pin_7,        
}pin_index_t;

typedef struct
{
    uint8 port : 3;        /*@ref port_index_t*/
    uint8 pin : 3;         /*@ref pin_index_t*/
    uint8 logic : 1;       /*@ref logic_t*/
    uint8 direction : 1;   /*@ref direction_t*/
}pin_config_t;


/*section function declaration*/

std_returntype gpio_pin_direction_intialize(const pin_config_t *_pin_config);
std_returntype gpio_pin_get_direction_status(const pin_config_t *_pin_config,direction_t *_direction);
std_returntype gpio_pin_write_logic(const pin_config_t *_pin_config,logic_t logic);
std_returntype gpio_pin_read_logic(const pin_config_t *_pin_config,logic_t *_logic);
std_returntype gpio_pin_toggle_logic(const pin_config_t *_pin_config);
std_returntype gpio_pin_intialize(const pin_config_t *_pin_config);

std_returntype gpio_port_direction_intialize(port_index_t _port,uint8 _direction);
std_returntype gpio_port_get_direction_status(port_index_t _port,direction_t *_direction);
std_returntype gpio_port_write_logic(port_index_t _port,uint8 logic);
std_returntype gpio_port_read_logic(port_index_t _port,logic_t *logic);
std_returntype gpio_port_toggle_logic(port_index_t _port);

#endif	/* HAL_GPIO_H */

