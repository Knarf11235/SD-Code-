/*******************************************************************************
* File Name: COMP_Relay.h  
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

#if !defined(CY_PINS_COMP_Relay_ALIASES_H) /* Pins COMP_Relay_ALIASES_H */
#define CY_PINS_COMP_Relay_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define COMP_Relay_0			(COMP_Relay__0__PC)
#define COMP_Relay_0_PS		(COMP_Relay__0__PS)
#define COMP_Relay_0_PC		(COMP_Relay__0__PC)
#define COMP_Relay_0_DR		(COMP_Relay__0__DR)
#define COMP_Relay_0_SHIFT	(COMP_Relay__0__SHIFT)
#define COMP_Relay_0_INTR	((uint16)((uint16)0x0003u << (COMP_Relay__0__SHIFT*2u)))

#define COMP_Relay_INTR_ALL	 ((uint16)(COMP_Relay_0_INTR))


#endif /* End Pins COMP_Relay_ALIASES_H */


/* [] END OF FILE */
