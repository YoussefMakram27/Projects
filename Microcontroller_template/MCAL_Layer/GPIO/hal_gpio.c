/* 
 * File:   hal_gpio.h
 * Author: Youssef M.Makram
 *
 * Created on July 20, 2023, 7:00 AM
 */
#include "hal_gpio.h"


volatile uint8 *port_registers[] ={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};
volatile uint8 *tris_registers[] ={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
volatile uint8 *lat_registers[]  ={&LATA,&LATB,&LATC,&LATD,&LATE};
/**
 * @brief intialize the direction of a specific pin @reference direction_t
 * @param _pin_config :pointer to the configuration @reference Pin_config_t
 * @return status of the function
 *         E_ok :function executed successfully
 *         E_ok :function didn't execute successfully
 */
#if PIN_CONFIGURATION == CONFIG_ENABLE
std_returntype gpio_pin_direction_intialize(const pin_config_t *_pin_config)
{
    std_returntype ret=E_ok;
     if(NULL == (_pin_config)|| ((_pin_config->pin)>(pin_max_number-1)))
    {
        ret=E_nok;
    }
    else
    {
        switch(_pin_config->direction)
        {
        
    
            case output :
               clear(*tris_registers[_pin_config->port],_pin_config->pin);
                
            break;
            
            case input :
                set(*tris_registers[_pin_config->port],_pin_config->pin);
            break;
            
            default:
                ret=E_nok;
        }
    }
    
    return ret;
}
#endif
/**
 * @brief return direction status of a specific pin @referene direction_t
 * @param _pin_config :pointer to the configuration @reference Pin_config_t
 * @param _direction  :pointer to variable by which we will return the direction of the pin @refernce direction_t
 * @return status of the function
 *         E_ok :function executed successfully
 *         E_ok :function didn't execute successfully 
 */
#if PIN_CONFIGURATION == CONFIG_ENABLE
std_returntype gpio_pin_get_direction_status(const pin_config_t *_pin_config,direction_t *_direction)
{
    std_returntype ret=E_ok;
    if(NULL == _pin_config || NULL == _direction || (_pin_config->pin)>(pin_max_number-1))
    {
        ret=E_nok;
    }
    else
    {
        *_direction=read(*tris_registers[_pin_config->port],_pin_config->pin);
    }
    return ret;
}
#endif
/**
 * @brief write high or low on a specific pin @ref logic_t
 * @param _pin_config :pointer to the configuration @reference Pin_config_t
 * @param logic       :pointer to varaiable by which user can pass a direction he want to set on specific pin @refernce logic_t
 * @return status of the function
 *         E_ok :function executed successfully
 *         E_ok :function didn't execute successfully 
 */
#if PIN_CONFIGURATION == CONFIG_ENABLE
std_returntype gpio_pin_write_logic(const pin_config_t *_pin_config,logic_t logic)
{
    std_returntype ret=E_ok;
    if(NULL == (_pin_config)|| ((_pin_config->pin)>(pin_max_number-1)))
    {
        ret=E_nok;
    }
    else
    {
        switch(logic)
        {
            case high :
                set(*lat_registers[_pin_config->port],_pin_config->pin);
                
            break;
            case low :
              clear(*lat_registers[_pin_config->port],_pin_config->pin);
            break;
            
            default :ret=E_nok;
        }
    }
    return ret;
}
#endif
/**
 * @brief read the logic on a specific pin @ref logic_t
 * @param _pin_config :pointer to the configuration @reference Pin_config_t
 * @param _logic       :pointer to variable by which we return the logic of specific pin
 * @return status of the function
 *         E_ok :function executed successfully
 *         E_ok :function didn't execute successfully 
 */
#if PIN_CONFIGURATION == CONFIG_ENABLE
std_returntype gpio_pin_read_logic(const pin_config_t *_pin_config,logic_t *_logic)
{
    std_returntype ret=E_ok;
    if(NULL == _pin_config || NULL == _logic || (_pin_config->pin)>(pin_max_number-1))
    {
        ret=E_nok;
    }
    else
    {
        *_logic = read(*port_registers[_pin_config->port],_pin_config->pin);
    }
    return ret;
}
#endif
/**
 * @brief toggle logic on a specific pin @ref logic_t
 * @param _pin_config :pointer to the configuration @reference Pin_config_t
 * @return status of the function
 *         E_ok :function executed successfully
 *         E_ok :function didn't execute successfully 
 */
#if PIN_CONFIGURATION == CONFIG_ENABLE
std_returntype gpio_pin_toggle_logic(const pin_config_t *_pin_config)
{
    std_returntype ret=E_ok;
    if(NULL == _pin_config || (_pin_config->pin)>(pin_max_number-1))
    {
        ret=E_nok;
    }
    else
    {
        toggle(*lat_registers[_pin_config->port],_pin_config->pin);
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config :pointer to the configuration @reference Pin_config_t
 * @return status of the function
 *         E_ok :function executed successfully
 *         E_ok :function didn't execute successfully 
 */
#if PIN_CONFIGURATION == CONFIG_ENABLE
std_returntype gpio_pin_intialize(const pin_config_t *_pin_config)
{
    std_returntype ret=E_ok;
     if(NULL == (_pin_config)|| ((_pin_config->pin)>(pin_max_number-1)))
    {
        ret=E_nok;
    }
    else
    {
         gpio_pin_direction_intialize(_pin_config);
         gpio_pin_write_logic(_pin_config,_pin_config->logic);
    }
}
#endif
/**
 * 
 * @param _port
 * @return status of the function
 *         E_ok :function executed successfully
 *         E_ok :function didn't execute successfully 
 */
#if PORT_CONFIGURATION == CONFIG_ENABLE
std_returntype gpio_port_direction_intialize(port_index_t _port,uint8 _direction)
{
    std_returntype ret=E_ok;
    if(_port >(port_max_number-1))
    {
        ret=E_nok;
    }
    else
    {
        *tris_registers[_port]=_direction;
    }
    return ret;
}
#endif
/**
 * 
 * @param _port
 * @param _direction
 * @return status of the function
 *         E_ok :function executed successfully
 *         E_ok :function didn't execute successfully
 */
#if PORT_CONFIGURATION == CONFIG_ENABLE
std_returntype gpio_port_get_direction_status(port_index_t _port,direction_t *_direction)
{
    std_returntype ret=E_ok;
    if(NULL == _direction || _port >(port_max_number-1))
    {
        ret=E_nok;
    }
    else
    {
        *_direction =  *tris_registers[_port];
    }
    return ret;
}
#endif
/**
 * 
 * @param _port
 * @param logic
 * @return status of the function
 *         E_ok :function executed successfully
 *         E_ok :function didn't execute successfully 
 */
#if PORT_CONFIGURATION == CONFIG_ENABLE
std_returntype gpio_port_write_logic(port_index_t _port,uint8 logic)
{
    std_returntype ret=E_ok;
    if(_port >(port_max_number-1))
    {
        ret=E_nok;
    }
    else
    {
        *lat_registers[_port]=logic;
    }
    return ret;
}
#endif
/**
 * 
 * @param _port
 * @param logic
 * @return status of the function
 *         E_ok :function executed successfully
 *         E_ok :function didn't execute successfully
 */
#if PORT_CONFIGURATION == CONFIG_ENABLE
std_returntype gpio_port_read_logic(port_index_t _port,logic_t *logic)
{
    std_returntype ret=E_ok;
    if(_port > (port_max_number-1) || NULL == logic)
    {
        ret=E_nok;
    }
    else
    {
        *logic = *lat_registers[_port];
    }
    return ret;
}
#endif
/**
 * 
 * @param _port
 * @return status of the function
 *         E_ok :function executed successfully
 *         E_ok :function didn't execute successfully 
 */
#if PORT_CONFIGURATION == CONFIG_ENABLE
std_returntype gpio_port_toggle_logic(port_index_t _port)
{
    std_returntype ret=E_ok;
    if(_port>(port_max_number-1))
    {
        ret=E_nok;
    }
    else
    {
        *lat_registers[_port]^=PORTC_MASK;
    }
    return ret;
}
#endif