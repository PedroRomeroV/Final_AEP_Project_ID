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
#include "StepperMotor.h"


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



T_UBYTE rub_step;
T_UBYTE rub_Position;

void StepperMotor_StepMachine(void);
void StepperMotor_EnergizeCoilA(void);
void StepperMotor_EnergizeCoilB(void);
void StepperMotor_EnergizeCoilC(void);
void StepperMotor_EnergizeCoilD(void);

void StepperMotor_Init(void)
{
GPIO_InitChannel(COIL_1,  GPIO_OUTPUT, GPIO_OPEN_DRAIN_DISABLE);
GPIO_InitChannel(COIL_2,  GPIO_OUTPUT, GPIO_OPEN_DRAIN_DISABLE);
GPIO_InitChannel(COIL_3,  GPIO_OUTPUT, GPIO_OPEN_DRAIN_DISABLE);
GPIO_InitChannel(COIL_4,  GPIO_OUTPUT, GPIO_OPEN_DRAIN_DISABLE);
rub_step=STEP_1;
rub_Position=0;
}

void StepperMotor_Step(T_UBYTE lub_Steps)
{


}

void StepperMotor_SetPosition(T_UBYTE lub_Position)
{
rub_Position=lub_Position;
}

void StepperMotor_Speed(T_UBYTE lub_Steps)
{

}

T_UBYTE StepperMotor_GotoStep(T_UBYTE lub_Position)
{
	if(lub_Position <= NUMBER_OF_STEPS ) //validate number posible cambio por step range limit
	{
		if(rub_Position < lub_Position)
		{
			StepperMotor_StepsCW();
		}
		else if(rub_Position > lub_Position)
		{
			StepperMotor_StepsCCW();
		}
		else
		{
			return 1; 
		}
		return 0;
	}
	return 0;
}

void StepperMotor_StepsCCW(void)
{

		if(rub_step == STEP_1)
		{
			rub_step = STEP_4;
		}
		else
		{
			rub_step--;	
		}
		rub_Position--;
		StepperMotor_StepMachine();

}

void StepperMotor_StepsCW(void)
{


		if(rub_step == STEP_4)
		{
			rub_step = STEP_1;
		}
		else
		{
			rub_step++;	
		}
		StepperMotor_StepMachine();
		rub_Position++;

	
}

void StepperMotor_StepMachine(void)
{
	switch(rub_step)
	{
		case STEP_1:
			StepperMotor_EnergizeCoilA();
		break;
		
		case STEP_2:
			StepperMotor_EnergizeCoilB();
		break;
		
		case STEP_3:
			StepperMotor_EnergizeCoilC();
		break;
		case STEP_4:
			StepperMotor_EnergizeCoilD();
		break;
		
		default:
		break;	
	}	
	
}

void StepperMotor_EnergizeCoilA(void)
{
	GPIO_SetHigh(COIL_1);
	GPIO_SetLow(COIL_2);
	GPIO_SetLow(COIL_3);
	GPIO_SetLow(COIL_4);	
}

void StepperMotor_EnergizeCoilB(void)
{
	GPIO_SetLow(COIL_1);
	GPIO_SetHigh(COIL_2);
	GPIO_SetLow(COIL_3);
	GPIO_SetLow(COIL_4);
}

void StepperMotor_EnergizeCoilC(void)
{
	GPIO_SetLow(COIL_1);
	GPIO_SetLow(COIL_2);
	GPIO_SetHigh(COIL_3);
	GPIO_SetLow(COIL_4);
	
}

void StepperMotor_EnergizeCoilD(void)
{
	GPIO_SetLow(COIL_1);
	GPIO_SetLow(COIL_2);
	GPIO_SetLow(COIL_3);
	GPIO_SetHigh(COIL_4);

}


