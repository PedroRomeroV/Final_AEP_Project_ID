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

#ifndef VISUALINDICATORS_H                               /* To avoid double inclusion */
#define VISUALINDICATORS_H
#include "LED.h"
#include "GPIO.h"
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


/* Functions macros */


/* Exported defines */

#define OFF     0
#define ON      1
#define TOGGLE  2


#define GAS		PORTC9
#define BREAK	PORTC8	
#define BEAMS	PORTC12
#define DOOR	PORTC13
#define CHIME	PORTC14
#define BELT	PORTC15

///b 0 5   4   ,
typedef 
	struct VSINDCTOR
	{
		T_UBYTE GasIndctr:1;
		T_UBYTE BreakIndctr:1;
		T_UBYTE BeamsIndctr:1;
		T_UBYTE DoorIndctr:1;
		T_UBYTE ChimeIndctr:2;
		T_UBYTE BeltIndctr:2;
	} T_VSINDCTOR;



void Visual_Indicator_Init(void);
void Visual_Indicator_SetPetition(void);
void Visual_Indicator_UpdateState(void);

#endif


