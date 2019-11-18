/*******************************************************************************
* File Name: LF_Relay.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_LF_Relay_ALIASES_H) /* Pins LF_Relay_ALIASES_H */
#define CY_PINS_LF_Relay_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LF_Relay_0			(LF_Relay__0__PC)
#define LF_Relay_0_PS		(LF_Relay__0__PS)
#define LF_Relay_0_PC		(LF_Relay__0__PC)
#define LF_Relay_0_DR		(LF_Relay__0__DR)
#define LF_Relay_0_SHIFT	(LF_Relay__0__SHIFT)
#define LF_Relay_0_INTR	((uint16)((uint16)0x0003u << (LF_Relay__0__SHIFT*2u)))

#define LF_Relay_INTR_ALL	 ((uint16)(LF_Relay_0_INTR))


#endif /* End Pins LF_Relay_ALIASES_H */


/* [] END OF FILE */
