/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %template.h%
* Instance:         RPL_1
* %version:         1 %
* %created_by:      uid02495 %
* %date_created:    Fri Feb 28 13:41:01 2003 %
*=============================================================================*/
/* DESCRIPTION : Header file template                                         */
/*============================================================================*/
/* FUNCTION COMMENT : contains only symbols which are exported to internal    */
/* platform modules. This will not be delivered with the library              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  | SAR/SIF/SCN_xxx               | Mr. Template     */
/* Integration under Continuus CM                                             */
/*============================================================================*/

#ifndef STEPPERMOTOR_H                               /* To avoid double inclusion */
#define STEPPERMOTOR_H

/* Includes */
/* -------- */


/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */


/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTES */


/* WORDS */


/* LONGS and STRUCTURES */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */


/* Functions macros  */


/* Exported defines */


#include "GPIO.h"


#define STEP_1   1
#define STEP_2   2
#define STEP_3   3
#define STEP_4   4

#define TRANSITION_TIME 0
#define NUMBER_OF_STEPS 48


#define COIL_1   PORTC4
#define COIL_2   PORTC5
#define COIL_3   PORTC6
#define COIL_4   PORTC7



void StepperMotor_Init(void);
void StepperMotor_Speed(T_UBYTE lub_Steps);
void StepperMotor_Step(T_UBYTE lub_Steps);
void StepperMotor_StepsCW(void);
void StepperMotor_StepsCCW(void);
T_UBYTE StepperMotor_GotoStep(T_UBYTE lub_Position);

#endif


