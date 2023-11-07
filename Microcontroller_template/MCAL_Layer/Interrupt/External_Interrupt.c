/* 
 * File:   External_Interrupt.c
 * Author: Youssef M.Makram
 *
 * Created on November 1, 2023, 8:46 AM
 */

#include "External_Interrupt.h"


static std_returntype disableexternalINTxinterrupt(const INTX_t *obj);
static std_returntype externalINtxclearflag(const INTX_t *obj);
static std_returntype setINTxpriority(const INTX_t *obj);
static std_returntype configureINTxedge(const INTX_t *obj);  
static std_returntype interruptINtxpininit(const INTX_t *obj);
static std_returntype callingINtxfunction(const INTX_t *obj);
static std_returntype enableexternalINtxinterrupt(const INTX_t *obj);

static std_returntype disableexternalRBxinterrupt(const INTX_t *obj);
static std_returntype externalRBxclearflag(const INTX_t *obj);
static std_returntype setRBxpriority(const INTX_t *obj);
static std_returntype interruptRBxpininit(const INTX_t *obj);
static std_returntype callingRBxfunction(const INTX_t *obj);
static std_returntype enableexternalRBxinterrupt(const INTX_t *obj);

void ISR_int0(void);
void ISR_int1(void);
void ISR_int2(void);


std_returntype Interupt_INTx_Init(const INTX_t *obj)
{
    std_returntype ret = E_ok;
    if(NULL == obj)
    {
        ret = E_nok;
    }
    else
    {
        /*Disable External INtx interrupt*/
        ret = disableexternalINTxinterrupt(obj);
        /*Clear flag*/
        ret &= externalINtxclearflag(obj);
        /*set priority*/
        ret &= setINTxpriority(obj);
        /*set edge*/
        ret &= configureINTxedge(obj);        
        /*configure pin*/
        ret &= interruptINtxpininit(obj);
        /*function*/
        ret &= callingINtxfunction(obj);
        /*enable external INtx interrupt*/
        ret &= enableexternalINtxinterrupt(obj);
    }
    return ret;
}
std_returntype Interupt_INTx_DeInit(const INTX_t *obj)
{
    std_returntype ret = E_ok;
    if(NULL == obj)
    {
        ret = E_nok;
    }
    else
    {
        
    }
    return ret;
}
std_returntype Interupt_RBx_Init(const RBX_t *obj)
{
    std_returntype ret = E_ok;
    if(NULL == obj)
    {
        ret = E_nok;
    }
    else
    {
        /*Disable External RBx interrupt*/
        ret = disableexternalRBxinterrupt(obj);
        /*Clear flag*/
        ret &= externalRBxclearflag(obj);
        /*set priority*/
        ret &= setRBxpriority(obj);
        /*configure pin*/
        ret &= interruptRBxpininit(obj);
        /*function*/
        ret &= callingRBxfunction(obj);
        /*enable external RBx interrupt*/
        ret &= enableexternalRBxinterrupt(obj);
    }
    return ret;
}
std_returntype Interupt_RBx_DeInit(const RBX_t *obj)
{
    std_returntype ret = E_ok;
    if(NULL == obj)
    {
        ret = E_nok;
    }
    else
    {
        
    }
    return ret;
}

/*Helper Functions*/

static std_returntype disableexternalINTxinterrupt(const INTX_t *obj)
{
     std_returntype ret = E_ok;
    if(NULL == obj)
    {
        ret = E_nok;
    }
    else
    {
        if(obj->pin_source_number == INT_0)
        {
            INT0ExternalInterruptDisable();
            ret = E_ok;
        }
        else if(obj->pin_source_number == INT_1)
        {
            INT1ExternalInterruptDisable();
            ret = E_ok;
        }
        else if(obj->pin_source_number == INT_2)
        {
            INT2ExternalInterruptDisable();
            ret = E_ok;
        }
        else
        {
            /*NOthing*/
        }
    }
    return ret;
}
static std_returntype externalINtxclearflag(const INTX_t *obj)
{
     std_returntype ret = E_ok;
    if(NULL == obj)
    {
        ret = E_nok;
    }
    else
    {
        
    }
    return ret;
}
static std_returntype setINTxpriority(const INTX_t *obj)
{
     std_returntype ret = E_ok;
    if(NULL == obj)
    {
        ret = E_nok;
    }
    else
    {
        
    }
    return ret;
}
static std_returntype configureINTxedge(const INTX_t *obj)
{
     std_returntype ret = E_ok;
    if(NULL == obj)
    {
        ret = E_nok;
    }
    else
    {
        
    }
    return ret;
}
static std_returntype interruptINtxpininit(const INTX_t *obj)
{
     std_returntype ret = E_ok;
    if(NULL == obj)
    {
        ret = E_nok;
    }
    else
    {
        
    }
    return ret;
}
static std_returntype callingINtxfunction(const INTX_t *obj)
{
     std_returntype ret = E_ok;
    if(NULL == obj)
    {
        ret = E_nok;
    }
    else
    {
        
    }
    return ret;
}
static std_returntype enableexternalINtxinterrupt(const INTX_t *obj)
{
     std_returntype ret = E_ok;
    if(NULL == obj)
    {
        ret = E_nok;
    }
    else
    {
        
        if(obj->pin_source_number == INT_0)
        {
           #if Interrupt_priority_Disable 
            GlobalInterruptLevelsEnable();
            PeriphralInterruptEnable();
           #else
            InterruptHighpriorityEnable();
           #endif
            INT0ExternalInterruptEnable();
            ret = E_ok;
        }
        else if(obj->pin_source_number == INT_1)
        {
            #if Interrupt_priority_Disable 
            GlobalInterruptLevelsEnable();
            PeriphralInterruptEnable();
           #else
            if(obj->pin_priority == High_Priority)
            {
                InterruptHighpriorityEnable();
            }
            else if (obj->pin_priority == Low_Priority)
            {
                InterruptLowPriorityPeriphralEnable();
            }
            else{/*Nothing*/}
           #endif
            INT1ExternalInterruptEnable();
            ret = E_ok;
        }
        else if(obj->pin_source_number == INT_2)
        {
            #if Interrupt_priority_Disable 
            GlobalInterruptLevelsEnable();
            PeriphralInterruptEnable();
           #else
            if(obj->pin_priority == High_Priority)
            {
                InterruptHighpriorityEnable();
            }
            else if (obj->pin_priority == Low_Priority)
            {
                InterruptLowPriorityPeriphralEnable();
            }
            else{/*Nothing*/}
           #endif
            INT2ExternalInterruptEnable();
            ret = E_ok;
        }
        else
        {
            /*NOthing*/
        }
    }
    return ret;
}

static std_returntype disableexternalRBxinterrupt(const INTX_t *obj)
{
     std_returntype ret = E_ok;
    if(NULL == obj)
    {
        ret = E_nok;
    }
    else
    {
        
    }
    return ret;
}
static std_returntype externalRBxclearflag(const INTX_t *obj)
{
     std_returntype ret = E_ok;
    if(NULL == obj)
    {
        ret = E_nok;
    }
    else
    {
        
    }
    return ret;
}
static std_returntype setRBxpriority(const INTX_t *obj)
{
     std_returntype ret = E_ok;
    if(NULL == obj)
    {
        ret = E_nok;
    }
    else
    {
        
    }
    return ret;
}
static std_returntype interruptRBxpininit(const INTX_t *obj)
{
     std_returntype ret = E_ok;
    if(NULL == obj)
    {
        ret = E_nok;
    }
    else
    {
        
    }
    return ret;
}
static std_returntype callingRBxfunction(const INTX_t *obj)
{
     std_returntype ret = E_ok;
    if(NULL == obj)
    {
        ret = E_nok;
    }
    else
    {
        
    }
    return ret;
}
static std_returntype enableexternalRBxinterrupt(const INTX_t *obj)
{
     std_returntype ret = E_ok;
    if(NULL == obj)
    {
        ret = E_nok;
    }
    else
    {
        
    }
    return ret;
}

void ISR_int0(void)
{
    
}
void ISR_int1(void)
{
    
}
void ISR_int2(void)
{
    
}