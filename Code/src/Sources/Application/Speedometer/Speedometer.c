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
#include "Speedometer.h"

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

T_UWORD rub_Speed;

void Speedometer_Init(void)
{
StepperMotor_Init();
Speedometer_Reset();
 StepperMotor_SetPosition(0);
 rub_Speed=0;
}
void Speedometer_Set(T_UWORD lub_Speed)
{
//en caso de que la velocidad viniera en otro formato se trasnforma
	if(lub_Speed>SPEED_LIMIT)
	{	
		rub_Speed=SPEED_LIMIT;
	}
	else
	{
		rub_Speed=lub_Speed;
	}

}
T_UBYTE Speedometer_UpdateSpeedometer(void)
{
	T_UBYTE lub_StepToGo=0;
	lub_StepToGo=(STEP_LIMIT_RANGE*rub_Speed)/SPEED_LIMIT;
	//aqui podemos hacer redonde para mas precision
	return StepperMotor_GotoStep(lub_StepToGo);
}

void Delay(T_ULONG ul_Delay)
{
while(ul_Delay--)
{}
}


void Speedometer_Reset(void)
{
	T_UBYTE ub_Counter=0;
	for(;ub_Counter< STEP_LIMIT_RANGE; ub_Counter++)
	{	
		StepperMotor_StepsCCW();
		Delay(250000);
	}

}

