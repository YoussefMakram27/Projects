/* 
 * File:   test.c
 * Author: Youssef M.Makram
 *
 * Created on July 23, 2023, 8:08 AM
 */
/*
#define HWREG8(_x)                       (*((volatile uint8 *)(_x)))
#define AHMED_LATC                       (HWREG8(0xF8B))
#define AHMED_TRISC                      (HWREG8(0xF94))
#define set(reg_add,bit_position)        (reg_add  |= (1<<bit_position))
#define clear(reg_add,bit_position)      (reg_add  &= ~(1<<bit_position))
#define toggle(reg_add,bit_position)     (reg_add  ^= (1<<bit_position))
#define latc_register ((volatile latc_reg_t *)0xF8B)
#define d_latc_register (*((volatile latc_reg_t *)0xF8B))
typedef union 
{
    struct
    {
        unsigned latc_p0 :1;
        unsigned latc_p1 :1;
        unsigned latc_p2 :1;
        unsigned latc_p3 :1;
        unsigned latc_p4 :1;
        unsigned latc_p5 :1;
        unsigned latc_p6 :1;
        unsigned latc_p7 :1;
    };
    uint8 latc_main_reg;
}latc_reg_t;
typedef union
{
    struct
    {
        unsigned self_sspm  :4;
        unsigned self_ckp   :1;
        unsigned self_sspen :1;
        unsigned self_sspov :1;
        unsigned self_wcol  :1;
    };
    uint8 sspcon1_main_reg;
}sspcon1_reg_t;

#define sspcon1_register   ((volatile sspcon1_reg_t *)0xFC6) 
#define d_sspcon1_register   (*((volatile sspcon1_reg_t *)0xFC6))


int main() 
{
    AHMED_TRISC = (0x00);
    
    sspcon1_register->sspcon1_main_reg=0xAA;
    __delay_ms(2000);
    sspcon1_register->sspcon1_main_reg=0x00;
    __delay_ms(2000);
    sspcon1_register->self_ckp=0x1;
    sspcon1_register->self_sspm=0x5;
    __delay_ms(2000);
    while(1)
    {
        __delay_ms(2000);
        latc_register->latc_main_reg=0x55;
        __delay_ms(2000);
        latc_register->latc_main_reg=0x00;
        __delay_ms(2000);
        d_latc_register.latc_p1=0x1;
        d_latc_register.latc_p3=0x1;
        d_latc_register.latc_p5=0x1;
        d_latc_register.latc_p7=0x1;
        __delay_ms(2000);
    }
    /*
    while(1)
    {
        AHMED_LATC = (0x00);
        __delay_ms(2000);
        set(AHMED_LATC,_LATC_LATC0_POSN);
        set(AHMED_LATC,_LATC_LATC7_POSN);
        __delay_ms(2000);
        clear(AHMED_LATC,_LATC_LATC1_POSN);
        clear(AHMED_LATC,_LATC_LATC6_POSN);
        __delay_ms(2000);
        toggle(AHMED_LATC,_LATC_LATC2_POSN);
        toggle(AHMED_LATC,_LATC_LATC5_POSN);
        __delay_ms(2000);
    }
    */
    /* while(1)
    {
        AHMED_LATC=0x00;
        AHMED_LATC |=(1<<_LATC_LATC2_POSN);
        __delay_ms(2000);
        AHMED_LATC &=~(1<<_LATC_LATC2_POSN);
        __delay_ms(2000);
        AHMED_LATC |=(_LATC_LATC4_MASK);
        AHMED_LATC ^=(_LATC_LATC5_MASK);
        __delay_ms(2000);
    }*/
    
    
    
//    return (EXIT_SUCCESS);
//}

