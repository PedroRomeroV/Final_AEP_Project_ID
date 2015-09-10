/*******************************************************************************/
/**
\file       GPIO.c
\brief      General purpose IO functions
\author     Abraham Tezmol
\version    1.0
\date       31/10/2008
*/
/****************************************************************************************************/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Core modules */
/** MCU derivative information */
#include "MCU_derivative.h"
/** Variable types and common definitions */
#include "typedefs.h"

/** Own headers */
/* GPIO routines prototypes */ 
#include "GPIO.h"

/** Used modules */


/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide FUNCTIONs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/


/****************************************************************************************************/
/**
* \brief    Configures individual GPIO pins to either input or output functionality.  
* \author   Abraham Tezmol
* \param    uint8_t channel - GPIO channel to be configured
* \param    uint8_t input_output - selection of input/output functionality (has impact on output impedance selection)
* \param    uint8_t Open_drain - Push pull or open drain selection modes 
* \return   void
*/

/*
void vfnGPIO_Init_channel(uint8_t channel, uint8_t input_output, uint8_t Open_drain)
{
    if (input_output == GPIO_OUTPUT)
    {
    	SIU.PCR[channel].B.PA  = 0;  				
    	SIU.PCR[channel].B.OBE = 1;					
    	if (Open_drain == GPIO_OPEN_DRAIN_ENABLE)
    	{
    		SIU.PCR[channel].B.ODE = 1;					
    	}
    	else
    	{	
    		SIU.PCR[channel].B.ODE = 0;				
    	}
    }
    else if (input_output == GPIO_INPUT)
    {
    	SIU.PCR[channel].B.PA  = 0;  			
    	SIU.PCR[channel].B.IBE = 1;				
    }

}
*/	

/****************************************************************************************************/
/**
* \brief    Configures individual GPIO pins to either input or output functionality.  
* \author   Abraham Tezmol
* \param    uint8_t channel - GPIO channel to be configured
* \param    uint8_t input_output - selection of input/output functionality (has impact on output impedance selection)
* \param    uint8_t Open_drain - Push pull or open drain selection modes 
* \return   void
*/


/****************************************************************************************************/
/**
* \brief    Turn a combination of 3 LEDs with a unique blinking pattern, this funcation shall be 
* \brief    called periodically to operate. 
* \author   Abraham Tezmol
* \param    void
* \return   void
*/
/****************************************************************************************************/
/**
* \brief    Initialize GPIO port connected to LEDs on eval board
* \author   Abraham Tezmol
* \param    void 
* \return   void
*/


/****************************************************************************************************/

void GPIO_Init(void)
{

GPIO_InitChannel(PORTC4,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);
GPIO_InitChannel(PORTC5,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);
GPIO_InitChannel(PORTC6,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);
GPIO_InitChannel(PORTC7,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);

GPIO_SetHigh(PORTC4);
GPIO_SetHigh(PORTC5);
GPIO_SetHigh(PORTC6);
GPIO_SetHigh(PORTC7);

}


void GPIO_InitChannel(T_UBYTE lub_Channel, T_UBYTE lub_InputOutput, T_UBYTE lub_OpenDrain)
{
    if (lub_InputOutput == GPIO_OUTPUT)
    {
    	SIU.PCR[lub_Channel].B.PA  = 0;  				/* GPIO */
    	SIU.PCR[lub_Channel].B.OBE = 1;					/* Output buffer enable */
    	if (lub_OpenDrain == GPIO_OPEN_DRAIN_ENABLE)
    	{
    		SIU.PCR[lub_Channel].B.ODE = 1;				/* Open drain option enable */	
    	}
    	else
    	{	
    		SIU.PCR[lub_Channel].B.ODE = 0;				/* Push-pull option enable */	
    	}
    }
    else if (lub_InputOutput == GPIO_INPUT)
    {
    	SIU.PCR[lub_Channel].B.PA  = 0;  				/* GPIO */
    	SIU.PCR[lub_Channel].B.IBE = 1;					/* Input buffer enable */	
    }

}

void GPIO_InitPort(T_UBYTE lub_PORT, T_UBYTE lub_InputOutput, T_UBYTE lub_OpenDrain)
{
	T_UBYTE lub_Channel=0;
	for(lub_Channel = lub_PORT;lub_Channel < lub_PORT+SIZEPORT  ; lub_Channel++)
	{
	    if (lub_InputOutput == GPIO_OUTPUT)
	    {
	    	SIU.PCR[lub_Channel].B.PA  = 0;  				/* GPIO */
	    	SIU.PCR[lub_Channel].B.OBE = 1;					/* Output buffer enable */
	    	if (lub_OpenDrain == GPIO_OPEN_DRAIN_ENABLE)
	    	{
	    		SIU.PCR[lub_Channel].B.ODE = 1;				/* Open drain option enable */	
	    	}
	    	else
	    	{	
	    		SIU.PCR[lub_Channel].B.ODE = 0;				/* Push-pull option enable */	
	    	}
	    }
	    else if (lub_InputOutput == GPIO_INPUT)
	    {
	    	SIU.PCR[lub_Channel].B.PA  = 0;  				/* GPIO */
	    	SIU.PCR[lub_Channel].B.IBE = 1;					/* Input buffer enable */	
	    }
	}
}

void GPIO_SetOutputChannel(T_UBYTE lub_Channel, T_UBYTE ub_LogicalValue)
{
    SIU.GPDO[lub_Channel].B.PDO  = ub_LogicalValue;  		/* Drive the logical output value to the pin */

}

void GPIO_SetOutputPORT(T_UBYTE lub_PORT, T_UWORD luw_Value)
{
	switch(lub_PORT)
	{
		case PORTA:
			SIU.PGPDO[PORT_AB].R = (T_ULONG)luw_Value<<16;  
		break;
		case PORTB:
			SIU.PGPDO[PORT_AB].R = (T_ULONG)luw_Value;
		break;
		case PORTC:
			SIU.PGPDO[PORT_CD].R = (T_ULONG)luw_Value<<16;
		break;
		case PORTD:
			SIU.PGPDO[PORT_CD].R = (T_ULONG)luw_Value;
		break;
		case PORTE:
			SIU.PGPDO[PORT_EF].R = (T_ULONG)luw_Value<<16;
		break;
		case PORTF:
			SIU.PGPDO[PORT_EF].R = (T_ULONG)luw_Value;
		break;
		case PORTG:
			SIU.PGPDO[PORT_GH].R = (T_ULONG)luw_Value<<16;
		break;
		case PORTH:
			SIU.PGPDO[PORT_GH].R = (T_ULONG)luw_Value;
		break;
		default:
		break;
		 
	}                      
}


 void GPIO_SetHigh(T_UBYTE lub_Channel)
{
	SIU.GPDO[lub_Channel].B.PDO =  1;		
}

 void GPIO_SetLow(T_UBYTE lub_Channel)
{
	SIU.GPDO[lub_Channel].B.PDO =  0;		
}


T_UBYTE GPIO_GetStatusOutput(T_UBYTE lub_Channel)
{
	return SIU.GPDO[lub_Channel].B.PDO;		
}


T_UBYTE GPIO_GetStatusInput(T_UBYTE lub_Channel)
{
	return !SIU.GPDI[lub_Channel].R;		
}