/* 
 * File:   Application.c
 * Author: Youssef M.Makram
 *
 * Created on July 20, 2023, 5:47 AM
 */


#include "application.h"

const uint8 customChar1[] = {0x04,0x0A,0x11,0x11,0x11,0x11,0x1F,0x00};
const uint8 customChar2[] = {0x04,0x0A,0x11,0x11,0x1F,0x1F,0x1F,0x00};
const uint8 customChar3[] = {0x04,0x0A,0x1F,0x1F,0x1F,0x1F,0x1F,0x00};
const uint8 customChar4[] = {0x04,0x0E,0x1F,0x1F,0x1F,0x1F,0x1F,0x00};
uint32 num = 0;
uint8 str[4];
int main() 
{
    ret = E_ok;
     
       application_intialize();
      
      
       
       
       
       
       
       while(1)
       {
           
           
            
       }
       
       
        
           
    return (EXIT_SUCCESS);
}
void application_intialize()
{
    ret = E_ok;
    ret = lcd_4_bit_intialize(&lcd_1);
    ret = lcd_8_bit_intialize(&lcd_2);
    
}
