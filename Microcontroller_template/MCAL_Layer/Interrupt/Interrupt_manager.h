/* 
 * File:   Interrupt_manager.h
 * Author: Youssef M.Makram
 *
 * Created on November 1, 2023, 1:19 PM
 */

#ifndef INTERRUPT_MANAGER_H
#define	INTERRUPT_MANAGER_H

#include "Interrupt_config.h"

#if Interrupt_priority_Enable
void __interrupt() Interruptmanagerhigh(void)
{
    
}

void __interrupt(low_priority) Interruptmanager(void)
{
    
}

#else

void __interrupt() Interruptmanager(void)
{
    
}

#endif	/* INTERRUPT_MANAGER_H */

