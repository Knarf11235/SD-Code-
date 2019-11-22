/*******************************************************************************
* File Name: VR_EN.h  
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

#if !defined(CY_PINS_VR_EN_ALIASES_H) /* Pins VR_EN_ALIASES_H */
#define CY_PINS_VR_EN_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define VR_EN_0			(VR_EN__0__PC)
#define VR_EN_0_PS		(VR_EN__0__PS)
#define VR_EN_0_PC		(VR_EN__0__PC)
#define VR_EN_0_DR		(VR_EN__0__DR)
#define VR_EN_0_SHIFT	(VR_EN__0__SHIFT)
#define VR_EN_0_INTR	((uint16)((uint16)0x0003u << (VR_EN__0__SHIFT*2u)))

#define VR_EN_INTR_ALL	 ((uint16)(VR_EN_0_INTR))


#endif /* End Pins VR_EN_ALIASES_H */


/* [] END OF FILE */
