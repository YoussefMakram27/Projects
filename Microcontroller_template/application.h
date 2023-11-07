/* 
 * File:   application.h
 * Author: GAMING STORE
 *
 * Created on July 20, 2023, 7:24 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/*section includes*/
#include "ECU_Layer/Led/ECU_Led.h"
#include "ECU_Layer/Button/ecu_push_button.h"
#include "ECU_Layer/Relay/Ecu_Relay.h"
#include "ECU_Layer/DcMotor/dc_motor.h"
#include "ECU_Layer/7_segment/_7_segment.h"
#include "ECU_Layer/keypad/keypad.h"
#include "ECU_Layer/char_Lcd/char_Lcd.h"
#include "ECU_Layer/Ecu_init.h"
#include "MCAL_Layer/Interrupt/External_Interrupt.h"
#include "MCAL_Layer/Interrupt/Interrupt_config.h"
/*section macro declaration*/

/*section function like macro*/





/*data type declaration*/

/*INTERRUPT*/



INTX_t int0_obj =
{
    .INTX_Pin.port = port_B,
    .INTX_Pin.pin  = pin_0,
    .INTX_Pin.direction = input,
    .INTX_Pin.logic     = low,
    .pin_edge           = rising_edge,
    .pin_priority       = High_Priority,
    .pin_source_number  = INT_0,
    .ISR_funct_pointer = ISR_int0,
};
    
/*section function declaration*/




void application_intialize(void);
#endif	/* APPLICATION_H */

