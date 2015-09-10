/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        Button.h
* Instance:         RPL_1
* %version:         1 
* %created_by:      Pedro Romero Vargas
* %date_created:    Fri JUL 24  07:41:01 2015 
*=============================================================================*/
/* DESCRIPTION : Header file Button Driver                                    */
/*============================================================================*/
/* FUNCTION COMMENT : contains  typedef T_BUTTON_TYPE which are exported      */
/* and prototype of Button Functios                                           */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 24/07/2015  | SAR/SIF/SCN_xxx               | Pedro R. V.      */
/* Integration under Continuus CM                                             */
/*============================================================================*/

#ifndef BUTTON_H                               /* To avoid double inclusion */
#define BUTTON_H

/* Includes */
/* -------- */
#include "typedefs.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */


/* Button */




/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */


/* Functions prototypes */
extern void Button_DriverInit( void );
extern void Button_Init(uint8_t channel);
extern T_UBYTE Button_GetStatus( T_UBYTE lub_ButtonID );
T_UBYTE Button_Debounce( T_UBYTE lub_Button_State );

/* Exported defines */
#define BUTTON_UP			(T_UBYTE)64
#define BUTTON_DOWN			(T_UBYTE)65
#define BUTTON_ANTIPINCH	(T_UBYTE)66


#define DEBOUNCE_COUNTER	(T_UBYTE)4
 


#endif


