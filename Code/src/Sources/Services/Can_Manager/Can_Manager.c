/*~A*/
/*~+:Module Header*/
/*******************************************************************************/
/**
\file       Can_Manager.c
\brief      Provide Can Services
\author     Francisco Martinez
\version    1.0
\date       16/08/2015
*/
/*******************************************************************************/
/*~E*/
/*~A*/
/*~+:Import*/
#include "Can_Manager.h"

/*~+:Defines*/

/*~+:Variables*/
struct CanTest
{
	uint8_t     can_test_enable;
}CanTestStruct;
/* Temporary CAN Messages */
uint8_t dummy_msg4[8] = {0xCA,0x83,0x15,0x77,0x19,0x56,0x65,0x00};
uint8_t dummy_msg5[8] = {0x00,0x65,0x56,0x19,0x77,0x15,0x83,0xCA};
uint8_t dummy_msg6[8] = {0x33,0x44,0x55,0x66,0x88,0x89,0x45,0x4C};
uint8_t dummy_msg7[8] = {0x99,0x44,0x55,0x66,0x88,0x89,0x45,0x4C};

CAN_PduType    pdu_handler4 = { 4, 8, dummy_msg4};
CAN_PduType    pdu_handler5 = { 5, 6, dummy_msg5};
CAN_PduType    pdu_handler6 = { 6, 2, dummy_msg6};
CAN_PduType    pdu_handler7 = { 7, 1, dummy_msg7};

uint32_t PduHandlerCnt0 = 0;
uint32_t PduHandlerCnt6 = 0;

/*~+:Can Manager Callbacks*/
CAN_MessageDataType CanMessage_PduHandler0;
CAN_MessageDataType CanMessage_PduHandler1;
CAN_MessageDataType CanMessage_PduHandler2;
CAN_MessageDataType CanMessage_PduHandler3;
CAN_MessageDataType CanMessage_PduHandler4;
CAN_MessageDataType CanMessage_PduHandler5;
CAN_MessageDataType CanMessage_PduHandler6;
CAN_MessageDataType CanMessage_PduHandler7;

/* Rx Callback*/
void Can_Manager_PduHandler0(CAN_MessageDataType CanMessage)
{

 T_UBYTE to = CanMessage.msg_dlc_field;
	CAN_PduType    pdu_handlerx = { 4, 2, dummy_msg7 };///CanMessage.msg_data_field
	CanMessage_PduHandler0 = CanMessage;
	CAN_SendFrame(pdu_handlerx);

}

void Can_Manager_PduHandler1(CAN_MessageDataType CanMessage)
{
	CanMessage_PduHandler1 = CanMessage;
	CAN_SendFrame(pdu_handler5);

}

void Can_Manager_PduHandler2(CAN_MessageDataType CanMessage)
{
	CanMessage_PduHandler2 = CanMessage;
	CAN_SendFrame(pdu_handler6);

}

void Can_Manager_PduHandler3(CAN_MessageDataType CanMessage)
{
	CanMessage_PduHandler3 = CanMessage;
	CAN_SendFrame(pdu_handler7);

}


/* Tx Callback*/
void Can_Manager_PduHandler4(CAN_MessageDataType CanMessage)
{
	CanMessage_PduHandler4 = CanMessage;
}

void Can_Manager_PduHandler5(CAN_MessageDataType CanMessage)
{
		CanMessage_PduHandler5 = CanMessage;
}

void Can_Manager_PduHandler6(CAN_MessageDataType CanMessage)
{
		CanMessage_PduHandler6 = CanMessage;
}

void Can_Manager_PduHandler7(CAN_MessageDataType CanMessage)
{
		CanMessage_PduHandler7 = CanMessage;
}

/*~+:Can Manager Periodic Functions*/

void CanManager_SendMessage_12p5ms(void)
{
	CAN_SendFrame(pdu_handler4);
	CAN_SendFrame(pdu_handler5);
	if (CanTestStruct.can_test_enable)
	{
	CanTestStruct.can_test_enable = 0;
	}
}


void CanManager_SendMessage_25ms(void)
{
	CAN_SendFrame(pdu_handler6);
}

