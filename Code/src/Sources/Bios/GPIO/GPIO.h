/*******************************************************************************/
/**

\file       GPIO.h
\brief      Macro definitions for registers access and I/O handling
\author     Abraham Tezmol
\version    0.2
\date       09/05/2013
*/
/*******************************************************************************/

#ifndef _GPIO_H        /*prevent duplicated includes*/
#define _GPIO_H

/*-- Includes ----------------------------------------------------------------*/

/** Core modules */
/** MCU derivative information */
#include "MCU_derivative.h"
/** Variable types and common definitions */
#include "typedefs.h"

/*-- Variables ---------------------------------------------------------------*/

/*-- Types Definitions -------------------------------------------------------*/

/*-- Defines -----------------------------------------------------------------*/



#define GPIO_INPUT					0
#define GPIO_OUTPUT					1

#define GPIO_OPEN_DRAIN_DISABLE		0
#define GPIO_OPEN_DRAIN_ENABLE		1

#define SIZEPORT 16
#define PORT_AB 0

#define PORTA 0

#define PORTA0 0
#define PORTA1 1
#define PORTA2 2
#define PORTA3 3
#define PORTA4 4
#define PORTA5 5
#define PORTA6 6
#define PORTA7 7
#define PORTA8 8
#define PORTA9 9
#define PORTA10 10
#define PORTA11 11
#define PORTA12 12
#define PORTA13 13
#define PORTA14 14
#define PORTA15 15

#define PORTB 16

#define PORTB0 16
#define PORTB1 17
#define PORTB2 18
#define PORTB3 19
#define PORTB4 20
#define PORTB5 21
#define PORTB6 22
#define PORTB7 23
#define PORTB8 24
#define PORTB9 25
#define PORTB10 26
#define PORTB11 27
#define PORTB12 28
#define PORTB13 29
#define PORTB14 30
#define PORTB15 31

#define PORT_CD 1

#define PORTC  32

#define PORTC0 32
#define PORTC1 33
#define PORTC2 34
#define PORTC3 35
#define PORTC4 36
#define PORTC5 37
#define PORTC6 38
#define PORTC7 39
#define PORTC8 40
#define PORTC9 41
#define PORTC10 42
#define PORTC11 43
#define PORTC12 44
#define PORTC13 45
#define PORTC14 46
#define PORTC15 47

#define PORTD  48

#define PORTD0 48
#define PORTD1 49
#define PORTD2 50
#define PORTD3 51
#define PORTD4 52
#define PORTD5 53
#define PORTD6 54
#define PORTD7 55
#define PORTD8 56
#define PORTD9 57
#define PORTD10 58
#define PORTD11 59
#define PORTD12 60
#define PORTD13 61
#define PORTD14 62
#define PORTD15 63

#define PORT_EF 2

#define PORTE  64

#define PORTE0 64
#define PORTE1 65
#define PORTE2 66
#define PORTE3 67
#define PORTE4 68
#define PORTE5 69
#define PORTE6 70
#define PORTE7 71
#define PORTE8 72
#define PORTE9 73
#define PORTE10 74
#define PORTE11 75
#define PORTE12 76
#define PORTE13 77
#define PORTE14 78
#define PORTE15 79

#define PORTF  80

#define PORTF0 80
#define PORTF1 81
#define PORTF2 82
#define PORTF3 83
#define PORTF4 84
#define PORTF5 85
#define PORTF6 86
#define PORTF7 87
#define PORTF8 88
#define PORTF9 89
#define PORTF10 90
#define PORTF11 91
#define PORTF12 92
#define PORTF13 93
#define PORTF14 94
#define PORTF15 95

#define PORT_GH 3 

#define PORTG  96

#define PORTG0 96
#define PORTG1 97
#define PORTG2 98
#define PORTG3 99
#define PORTG4 100
#define PORTG5 101
#define PORTG6 102
#define PORTG7 103
#define PORTG8 104
#define PORTG9 105
#define PORTG10 106
#define PORTG11 107
#define PORTG12 108
#define PORTG13 109
#define PORTG14 110
#define PORTG15 111

#define PORTH  112

#define PORTH0 112
#define PORTH1 113
#define PORTH2 114
#define PORTH3 115
#define PORTH4 116
#define PORTH5 117
#define PORTH6 118
#define PORTH7 119
#define PORTH8 120
#define PORTH9 121
#define PORTH10 122
#define PORTH11 123


#define BUTTON1 64
#define NUTTON2 65
#define BUTTON3 66
#define BUTTON4 67

#define LED1 68 /* PE4 */
#define LED2 69
#define LED3 70
#define LED4 71

#define DIP1 102
#define DIP2 103
#define DIP3 104
#define DIP4 105

/* PCR[x] register

- 1 bit
- 1 bit. SMC. Safe Mode Control.
- 1 bit. APC. Analog Pad Control.
- 1 bit.
- 2 bits. PA. Pad Output Assignement.
- 1 bit. OBE. Output Buffer Enable.
- 1 bit. IBE. Input Buffer Enable.

- 2 bits.
- 1 bit. ODE. Open Drain Output Enable.
- 2 bits.
- 1 bit. SRC. Slew-rate Control.
- 1 bit. WPE. Weak Pull Up/Down Enable.
- 1 bit. WPS. Weak Pull Up/Down Select.

*/


/*-- Macros ------------------------------------------------------------------*/
/* Indicator LEDs handling */

/** Set LED */ 
//#define LED_ON(channel)                     (SIU.GPDO[channel].B.PDO =  0)
/** Clear LED */ 
//#define LED_OFF(channel)                    (SIU.GPDO[channel].B.PDO =  1)
/** Toggle LED */ 
//#define LED_TOGGLE(channel)                 (SIU.GPDO[channel].B.PDO ^= 1) 


/*-- Function Prototypes -----------------------------------------------------*/

void GPIO_Init(void);
void GPIO_InitChannel(uint8_t channel, uint8_t input_output, uint8_t Open_drain);
void GPIO_SetOutputChannel(uint8_t channel, uint8_t logical_value);
void GPIO_InitPort(T_UBYTE lub_PORT, T_UBYTE lub_InputOutput, T_UBYTE lub_OpenDrain);
void GPIO_SetOutputChannel(T_UBYTE lub_Channel, T_UBYTE ub_LogicalValue);
void GPIO_SetOutputPORT(T_UBYTE lub_PORT, T_UWORD luw_Value);
void GPIO_SetHigh(T_UBYTE lub_Channel);
void GPIO_SetLow(T_UBYTE lub_Channel);
T_UBYTE GPIO_GetStatusOutput(T_UBYTE lub_Channel);
T_UBYTE GPIO_GetStatusInput(T_UBYTE lub_Channel);
void vfnGPIO_FlashMainLED(void);
void vfnGPIO_LED_Init(void);


#endif /* _GPIO_H */

/*******************************************************************************/
