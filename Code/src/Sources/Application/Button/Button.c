/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         Button.c
* Instance:         RPL_1
* %version:         1 
* %created_by:      Pedro Romero Vargas
* %date_created:    Fri Jul 24  14:38:03 2015 
*=============================================================================*/
/* DESCRIPTION : C source Button Driver                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source from the Button driver */
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

#include "Button.h"
#include "GPIO.h"





/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	Button_Init
 *  Description          : Initialize a Button Type
 *  Parameters           : S_BUTTON_TYPE *  , T_UBYTE 
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/

T_UBYTE BtnDbnc = 0;

void Button_Init(uint8_t channel)
{
    /* Data Port A initialization */ 
	GPIO_InitChannel(channel,GPIO_INPUT, GPIO_OPEN_DRAIN_DISABLE);  	
}



extern void Button_DriverInit( void )
{
Button_Init(  BUTTON1 );
}

/**************************************************************
 *  Name                 :	Button_GetStatus
 *  Description          :	Get the Statuus of a button
 *  Parameters           :  S_BUTTON_TYPE* 
 *  Return               :	T_UBYTE
 *  Critical/explanation :	No
 **************************************************************/

T_UBYTE Button_GetStatus( T_UBYTE lub_ButtonID )
{
	return GPIO_GetStatusInput(lub_ButtonID);
}

T_UBYTE Button_Debounce( T_UBYTE lub_Button_State )
{
	static T_UBYTE rub_DebounceCounter = 0;
	static T_UBYTE rub_Button_Prev_State = 0;
	if(lub_Button_State == rub_Button_Prev_State)
	{
		rub_DebounceCounter++;
		if(rub_DebounceCounter>=DEBOUNCE_COUNTER)
		{
		return lub_Button_State;
		rub_DebounceCounter--;
		}
		else
		{
		
		}
	}
	else
	{
		rub_DebounceCounter=0;
		rub_Button_Prev_State=lub_Button_State;
	}
	return 0;
	
}
