/* 
 * File:   External_Interrupt.h
 * Author: Youssef M.Makram
 *
 * Created on November 1, 2023, 8:46 AM
 */

#ifndef EXTERNAL_INTERRUPT_H
#define	EXTERNAL_INTERRUPT_H

/*Includes Section*/

#include "Interrupt_config.h"
/*Macro Declaration Section*/

/*Data Types Section*/

typedef enum
{
    Low_Priority = 0,
    High_Priority,
}priority_t;

typedef enum
{
    falling_edge = 0,        
    rising_edge,
}Edge_Pin_t;

typedef enum
{
    INT_0 = 0,
    INT_1 = 1,
    INT_2 = 2,        
}INTX_number_t;

typedef struct
{
    pin_config_t INTX_Pin;
    void (*ISR_funct_pointer) (void);
    priority_t pin_priority;
    Edge_Pin_t pin_edge;
    INTX_number_t pin_source_number;
}INTX_t;

typedef struct
{
    pin_config_t RBX_Pin;
    void (*ISR_funct_pointer) (void);
    priority_t pin_priority;
    
}RBX_t;
/*Function Like Macro Section*/

/*INTCON REGISTERS*/

/*EXTERNAL INTX*/
#define INT0ExternalInterruptEnable()  (INTCONbits.INT0IE = 1)
#define INT0ExternalInterruptDisable() (INTCONbits.INT0IE = 0)
#define INT0SetFlag()                  (INTCONbits.INT0IF = 1)
#define INT0ClearFlag()                (INTCONbits.INT0IF = 0)
#define ExternalINT0RisingEdge()       (INTCON2bits.INTEDG0 = 0)
#define ExternalINT0RisingEdge()       (INTCON2bits.INTEDG0 = 1)
#define ExternalINT0FallingEdge()      (INTCON2bits.INTEDG0 = 0)

#define INT1ExternalInterruptEnable() (INTCON3bits.INT1IE = 1)
#define INT1ExternalInterruptDisable() (INTCON3bits.INT1IE = 0)
#define INT1SetFlag()             (INTCON3bits.INT1IF = 1)
#define INT1ClearFlag()           (INTCON3bits.INT1IF = 0)
#define ExternalINT1PriorityEnable() (INTCON3bits.INT1IP = 1)
#define ExternalINT1PriorityDiable() (INTCON3bits.INT1IP = 0)
#define ExternalINT1RisingEdge()  (INTCON2bits.INTEDG1 = 1)
#define ExternalINT1FallingEdge() (INTCON2bits.INTEDG1 = 0)

#define INT2ExternalInterruptEnable() (INTCON3bits.INT2IE = 1)
#define INT2ExternalInterruptDisable() (INTCON3bits.INT2IE=0)
#define INT2SetFlag()             (INTCON3bits.INT2IF = 1)
#define INT2ClearFlag()           (INTCON3bits.INT2IF = 0)
#define ExternalINT2PriorityEnable() (INTCON3bits.INT2IP = 1)
#define ExternalINT2PriorityDiable() (INTCON3bits.INT2IP = 0)
#define ExternalINT2RisingEdge()  (INTCON2bits.INTEDG2 = 1)
#define ExternalINT2FallingEdge() (INTCON2bits.INTEDG2 = 0)

/*EXTERNAL PORTB*/

#define RBPortChangeInterruptEnable()    (INTCONbits.RBIE = 1)
#define RBPortChangeInterruptDisable()   (INTCONbits.RBIE = 0)
#define RBPortChangeInterruptSetFlag()   (INTCONbits.RBIF = 1)
#define RBPortChangeInterruptClearFlag() (INTCONbits.RBIF = 0)
#define RBPortChangeInterruptPriorityEnable() (INTCON2bits.RBIP = 1)
#define RBPortChangeInterruptPriorityDisable() (INTCON2bits.RBIP = 0)

/*SOftware Interfaces Section*/

std_returntype Interupt_INTx_Init(const INTX_t *obj);
std_returntype Interupt_INTx_DeInit(const INTX_t *obj);
std_returntype Interupt_RBx_Init(const RBX_t *obj);
std_returntype Interupt_RBx_DeInit(const RBX_t *obj);

void ISR_int0(void);
void ISR_int1(void);
void ISR_int2(void);
#endif	/* EXTERNAL_INTERRUPT_H */

