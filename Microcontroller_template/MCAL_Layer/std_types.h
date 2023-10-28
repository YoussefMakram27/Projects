/* 
 * File:   std_types.h
 * Author: GAMING STORE
 *
 * Created on July 20, 2023, 7:09 AM
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H
/*section includes*/
#include "compiler.h"
#include "std_libraries.h"
#include <string.h>
/*section macro declaration*/
#define std_high 0x01
#define std_low  0x00

#define std_on  0x01
#define std_off 0x00

#define std_active 0x01
#define std_idle   0x01

#define E_ok      (std_returntype)0x01
#define E_nok     (std_returntype)0x00
/*section function like macro*/


/*data type declaration*/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;

typedef uint8 std_returntype;


/*section function declaration*/




#endif	/* STD_TYPES_H */

