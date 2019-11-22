/*******************************************************************************
* File Name: HF_CB.h  
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

#if !defined(CY_PINS_HF_CB_ALIASES_H) /* Pins HF_CB_ALIASES_H */
#define CY_PINS_HF_CB_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define HF_CB_0			(HF_CB__0__PC)
#define HF_CB_0_PS		(HF_CB__0__PS)
#define HF_CB_0_PC		(HF_CB__0__PC)
#define HF_CB_0_DR		(HF_CB__0__DR)
#define HF_CB_0_SHIFT	(HF_CB__0__SHIFT)
#define HF_CB_0_INTR	((uint16)((uint16)0x0003u << (HF_CB__0__SHIFT*2u)))

#define HF_CB_INTR_ALL	 ((uint16)(HF_CB_0_INTR))


#endif /* End Pins HF_CB_ALIASES_H */


/* [] END OF FILE */
