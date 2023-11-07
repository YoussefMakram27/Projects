/* 
 * File:   Interrupt_config.h
 * Author: Youssef M.Makram
 *
 * Created on November 1, 2023, 8:45 AM
 */

#ifndef INTERRUPT_CONFIG_H
#define	INTERRUPT_CONFIG_H

/*Includes Section*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "pic18f4620.h"
#include "../../MCAL_Layer/std_types.h"

/*Macro Declaration Section*/

#define Interrupt_Enable                      1
#define Interrupt_Disable                     0 
#define Interrupt_occur                       1
#define Interrupt_not_occur                   0
#define Interrupt_priority_Enable             1
#define Interrupt_priority_Disable            0
#define Interuppt_Priority_Levels_Enable      1
#define Interuppt_Priority_Levels_Disable     0
#define External_Interrupt_INTX_Enable        1
#define External_Interrupt_INTX_Disable       0
#define External_Interrupt_onchange_Enable    1
#define External_Interrupt_onchange_Disable   0

/*Function Like Macro Section*/

#if Interrupt_priority_Enable

/*INTCON REGISTERS*/
#define InterruptHighpriorityEnable()        (INTCONbits.GIEH = 1)
#define InterruptLevelsDisable()             (INTCONbits.GIEH = 0)
#define InterruptLowPriorityPeriphralEnable()  (INTCONbits.GIEL = 1)
#define InterruptLowPriorityPeriphralDisable() (INTCONbits.GIEL = 0)

#else

/*INTCON REGISTERS*/
#define GlobalInterruptLevelsEnable()     (INTCONbits.GIE = 1)
#define GlobalInterruptLevelsDisable()    (INTCONbits.GIE = 0)
#define PeriphralInterruptEnable()  (INTCONbits.PEIE = 1)
#define PeriphralInterruptDisable() (INTCONbits.PEIE = 0)

#endif

/*INTCON REGISTERS*/
#define Timer0Enable() (INTCONbits.T0IE = 1)
#define Timer0Disable() (INTCONbits.T0IE = 0)
#define Timer0SetFlag (INTCONbits.T0IF = 1)
#define Timer0ClearFlag (INTCONbits.T0IF = 0)  /*Must be cleared in software*/




/*Data Types Section*/



/*SOftware Interfaces Section*/


#endif	/* INTERRUPT_CONFIG_H */

