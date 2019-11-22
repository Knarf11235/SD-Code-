/*******************************************************************************
* File Name: LF_Relay.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "LF_Relay.h"

static LF_Relay_BACKUP_STRUCT  LF_Relay_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: LF_Relay_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet LF_Relay_SUT.c usage_LF_Relay_Sleep_Wakeup
*******************************************************************************/
void LF_Relay_Sleep(void)
{
    #if defined(LF_Relay__PC)
        LF_Relay_backup.pcState = LF_Relay_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            LF_Relay_backup.usbState = LF_Relay_CR1_REG;
            LF_Relay_USB_POWER_REG |= LF_Relay_USBIO_ENTER_SLEEP;
            LF_Relay_CR1_REG &= LF_Relay_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(LF_Relay__SIO)
        LF_Relay_backup.sioState = LF_Relay_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        LF_Relay_SIO_REG &= (uint32)(~LF_Relay_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: LF_Relay_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to LF_Relay_Sleep() for an example usage.
*******************************************************************************/
void LF_Relay_Wakeup(void)
{
    #if defined(LF_Relay__PC)
        LF_Relay_PC = LF_Relay_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            LF_Relay_USB_POWER_REG &= LF_Relay_USBIO_EXIT_SLEEP_PH1;
            LF_Relay_CR1_REG = LF_Relay_backup.usbState;
            LF_Relay_USB_POWER_REG &= LF_Relay_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(LF_Relay__SIO)
        LF_Relay_SIO_REG = LF_Relay_backup.sioState;
    #endif
}


/* [] END OF FILE */
