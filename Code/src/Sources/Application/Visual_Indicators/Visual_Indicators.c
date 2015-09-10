/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %template.c%
* Instance:         RPL_1
* %version:         2 %
* %created_by:      uid02495 %
* %date_created:    Fri Jan  9 14:38:03 2004 %
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source template according to  */
/* the new software platform                                                  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  |                               | Mr. Template     */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */
#include "Visual_Indicators.h"


/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */



/* Exported functions prototypes */
/* ----------------------------- */

/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : inline_func	2
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : private_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
extern rub_Speed;
T_VSINDCTOR Indc_State;
T_VSINDCTOR Indc_Petition;


void Visual_Indicator_Init(void)
{
GPIO_InitChannel(GAS,  GPIO_OUTPUT, GPIO_OPEN_DRAIN_DISABLE);
GPIO_InitChannel(BREAK,  GPIO_OUTPUT, GPIO_OPEN_DRAIN_DISABLE);
GPIO_InitChannel(BEAMS,  GPIO_OUTPUT, GPIO_OPEN_DRAIN_DISABLE);
GPIO_InitChannel(DOOR,  GPIO_OUTPUT, GPIO_OPEN_DRAIN_DISABLE);
GPIO_InitChannel(CHIME,  GPIO_OUTPUT, GPIO_OPEN_DRAIN_DISABLE);
GPIO_InitChannel(BELT,  GPIO_OUTPUT, GPIO_OPEN_DRAIN_DISABLE);
GPIO_SetOutputChannel(GAS, OFF);
GPIO_SetOutputChannel(BREAK, OFF);
GPIO_SetOutputChannel(BEAMS, OFF);
GPIO_SetOutputChannel(DOOR, OFF);
GPIO_SetOutputChannel(CHIME, OFF);
GPIO_SetOutputChannel(BELT, OFF);
Indc_State.GasIndctr=OFF;
Indc_State.BreakIndctr=OFF;
Indc_State.BeamsIndctr=OFF;
Indc_State.DoorIndctr=OFF;
Indc_State.ChimeIndctr=OFF;
Indc_State.BeltIndctr=OFF;

Indc_Petition.GasIndctr=OFF;
Indc_Petition.BreakIndctr=OFF;
Indc_Petition.BeamsIndctr=OFF;
Indc_Petition.DoorIndctr=OFF;
Indc_Petition.ChimeIndctr=OFF;
Indc_Petition.BeltIndctr=OFF;

}


void Visual_Indicator_SetPetition(void)
{
Indc_Petition.GasIndctr=ON;
Indc_Petition.BreakIndctr=ON;
Indc_Petition.BeamsIndctr=ON;
Indc_Petition.DoorIndctr=ON;
Indc_Petition.ChimeIndctr=ON;
Indc_Petition.BeltIndctr=ON;

}

void Visual_Indicator_UpdateState(void)
{
	static T_UBYTE ub_toggle=0; 
	static T_UBYTE ub_chimetoggle=0;
	if(Indc_Petition.GasIndctr != Indc_State.GasIndctr)
	{
		GPIO_SetOutputChannel(GAS,Indc_Petition.GasIndctr);
		Indc_State.GasIndctr = Indc_Petition.GasIndctr;
	}
	if(Indc_Petition.BreakIndctr != Indc_State.BreakIndctr)
	{
		GPIO_SetOutputChannel(BREAK,Indc_Petition.BreakIndctr);
		Indc_State.BreakIndctr = Indc_Petition.BreakIndctr;
	}
	if(Indc_Petition.BeamsIndctr != Indc_State.BeamsIndctr)
	{
		GPIO_SetOutputChannel(BEAMS,Indc_Petition.BeamsIndctr);
		Indc_State.BeamsIndctr = Indc_Petition.BeamsIndctr;
	}
	
	if( (Indc_Petition.ChimeIndctr != Indc_State.ChimeIndctr)  ||(Indc_State.ChimeIndctr == TOGGLE) )
	{
		if(Indc_Petition.ChimeIndctr!=OFF)
		{
		
			ub_chimetoggle++;	
			if(ub_chimetoggle == 1)
				{
					GPIO_SetOutputChannel(CHIME,OFF);
				}
				else
				{
					GPIO_SetOutputChannel(CHIME,ON);
					ub_chimetoggle=0;
				}
		
			Indc_State.ChimeIndctr = TOGGLE;
		}
		else
		{
			GPIO_SetOutputChannel(CHIME,OFF);
			Indc_State.BeltIndctr = OFF;
		}
	}
	
	if( (Indc_Petition.BeltIndctr != Indc_State.BeltIndctr) || (Indc_State.BeltIndctr == TOGGLE) )
	{
		if(Indc_Petition.BeltIndctr==OFF)
		{
			GPIO_SetOutputChannel(BELT,OFF);
			Indc_State.BeltIndctr = OFF;	
		}
		else
		{	
			if(rub_Speed < 10)//gearbox and drive and les than 10
			{
				GPIO_SetOutputChannel(BELT,ON);
				Indc_State.BeltIndctr = ON;
			}
			else if(rub_Speed > 10)//speed more than 10
			{
				if(ub_toggle < 127)
				{
					GPIO_SetOutputChannel(BELT,OFF);
				}
				else
				{
					GPIO_SetOutputChannel(BELT,ON);
				}
				ub_toggle++;	
				Indc_State.BeltIndctr = TOGGLE;
			}

		}
		
	}
	if( (Indc_Petition.DoorIndctr != Indc_State.DoorIndctr) || (rub_Speed < 5) )
	{
		if( (Indc_Petition.DoorIndctr == ON) && (rub_Speed > 5) )
		{	
			GPIO_SetOutputChannel(DOOR,ON);
			Indc_State.DoorIndctr = ON;
		}
		if(Indc_Petition.DoorIndctr == OFF)
		{
			GPIO_SetOutputChannel(DOOR,OFF);
			Indc_State.DoorIndctr = OFF;
		}
	}



}