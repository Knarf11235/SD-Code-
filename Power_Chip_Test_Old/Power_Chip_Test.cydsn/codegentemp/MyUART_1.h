/*******************************************************************************
* File Name: MyUART_1.h
* Version 1.50
*
* Description:
*  This file provides constants and parameter values for the Software Transmit
*  UART Component.
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef CY_SW_TX_UART_MyUART_1_H
#define CY_SW_TX_UART_MyUART_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"

#define MyUART_1_BAUD_RATE                      (9600u)
#define MyUART_1_PIN_STATIC_MODE                (1u)


/***************************************
*        Function Prototypes
***************************************/
#if(MyUART_1_PIN_STATIC_MODE == 1u)
    void MyUART_1_Start(void) ;
#else
    void MyUART_1_StartEx(uint8 port, uint8 pin) ;
#endif /* (MyUART_1_PIN_STATIC_MODE == 1u) */

void MyUART_1_Stop(void) ;
void MyUART_1_PutChar(uint8 txDataByte) ;
void MyUART_1_PutString(const char8 string[]) ;
void MyUART_1_PutArray(const uint8 array[], uint32 byteCount) ;
void MyUART_1_PutHexByte(uint8 txHexByte) ;
void MyUART_1_PutHexInt(uint16 txHexInt) ;
void MyUART_1_PutCRLF(void) ;

#endif /* CY_SW_TX_UART_MyUART_1_H */


/* [] END OF FILE */
