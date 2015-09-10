/*~A*/
/*~+:Module Header*/
/*******************************************************************************/
/**
\file       SchM_Tasks.c
\brief      Application Tasks
\author     Francisco Martinez
\version    1.0
\date       08/07/2015
*/
/*******************************************************************************/
/*~E*/
/*~A*/
/*~+:Import*/
#include "SchM_Tasks.h"
#include "Can_Manager.h"
#include "dummy.h"
#include "StepperMotor.h"
#include "Button.h"
#include "Visual_Indicators.h"

/*~E*/
/*~A*/
/*~+:Scheduler Tasks*/
/*~A*/


void SchM_3p125ms_Task(void)
{

	if(Button_Debounce(Button_GetStatus( BUTTON1 )))
	{
	LED_OFF(LED1);
	Visual_Indicator_SetPetition();
	}
	else
	{
	LED_ON(LED1);
	}
Visual_Indicator_UpdateState();
}
/*~E*/
/*~A*/
/*~+:SchM_6p25ms_Task*/

void SchM_6p25ms_Task(void)
{
//	Test();

}
/*~E*/
/*~A*/
/*~+:SchM_12p5ms_Task*/

void SchM_12p5ms_Task(void)
{
//CanManager_SendMessage_12p5ms();
//StepperMotor_StepsCW();
//StepperMotor_GotoStep(32);
Speedometer_UpdateSpeedometer();

}
/*~E*/
/*~A*/
/*~+:SchM_25ms_Task*/

void SchM_25ms_Task(void)
{
//CanManager_SendMessage_25ms();

}
/*~E*/
/*~A*/
/*~+:SchM_50ms_Task*/

void SchM_50ms_Task(void)
{
	
	
}
/*~E*/
/*~A*/
/*~+:SchM_100ms_Task*/

void SchM_100ms_Task(void)
{


static T_UBYTE testito=0;
if(testito==10)
{
Speedometer_Set(100);
}
if(testito==50)
{
Speedometer_Set(75);
}
if(testito==120)
{
Speedometer_Set(200);
}
if(testito==180)
{
Speedometer_Set(100);
}
if(testito==200)
{
Speedometer_Set(0);
}
if(testito==254)
{
testito=253;
}
testito++;
}
/*~E*/
/*~E*/
