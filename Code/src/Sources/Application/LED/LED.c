/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         LED.c
* Instance:         RPL_1
* %version:         1 
* %created_by:      Pedro Romero Vargas
* %date_created:    Fri Jul 24  14:38:03 2015 
*=============================================================================*/
/* DESCRIPTION : C source LED Driver                                          */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source from the LED driver    */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 24/07/2015  |                               | Pedro R. V.      */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */
#include "LED.h"
#include "GPIO.h"


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 



/* Exported functions prototypes */
/* ----------------------------- */


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	LED_Init
 *  Description          :	Initialize a LED type
 *  Parameters           :  T_LED_TYPE * , T_UBYTE
 *  Return               :	void
 *  Critical/explanation :  No
 **************************************************************/
void LED_Init( uint8_t channel,  uint8_t Open_drain)
{
	GPIO_InitChannel(channel,GPIO_OUTPUT,Open_drain);  
	GPIO_SetOutputChannel (channel, 1);	
}


/**************************************************************
 *  Name                 :	LED_ON
 *  Description          :	Turn ON a LED
 *  Parameters           :  T_LED_TYPE*
 *  Return               :	void
 *  Critical/explanation :  No
 **************************************************************/
void LED_ON(T_UBYTE lub_Led)
{
	GPIO_SetHigh(lub_Led);
}


/**************************************************************
 *  Name                 :	LED_OFF
 *  Description          :	Turn OFF a LED
 *  Parameters           :  T_LED_TYPE*
 *  Return               :	void
 *  Critical/explanation :  No
 **************************************************************/
void LED_OFF(T_UBYTE lub_Led)
{
	GPIO_SetLow(lub_Led);
}




/**************************************************************
 *  Name                 :	LED_GetStatus
 *  Description          :	Get the status of a LED
 *  Parameters           :  T_LED_TYPE*
 *  Return               :	T_UBYTE
 *  Critical/explanation :  No
 **************************************************************/
T_UBYTE LED_GetStatus(T_UBYTE lub_Led)
{
	return GPIO_GetStatusOutput(lub_Led);
}




void LED_Driver_Init(void)
{
	  LED_Init(LED1,GPIO_OPEN_DRAIN_ENABLE);
//    LED_Init(LED2,GPIO_OPEN_DRAIN_ENABLE);
 //-   LED_Init(PORTA0,GPIO_OPEN_DRAIN_DISABLE);
//    LED_Init(PORTA1,GPIO_OPEN_DRAIN_DISABLE);
//-    LED_OFF(PORTA0);
//    LED_ON(PORTA1);
    LED_ON(LED1);
//    LED_OFF(LED2);

//GPIO_InitPort(PORTA,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);
//GPIO_SetOutputPORT(PORTA, 0xFFFF);


 LED_Init(PORTB0,GPIO_OPEN_DRAIN_DISABLE); 
 LED_Init(PORTB1,GPIO_OPEN_DRAIN_DISABLE);
 LED_Init(PORTB2,GPIO_OPEN_DRAIN_DISABLE);
 LED_Init(PORTB3,GPIO_OPEN_DRAIN_DISABLE);
 LED_Init(PORTB6,GPIO_OPEN_DRAIN_DISABLE);
  LED_ON(PORTB0); 
  LED_ON(PORTB1); 
  LED_ON(PORTB2); 
  LED_ON(PORTB3);
  LED_ON(PORTB6); 
}

