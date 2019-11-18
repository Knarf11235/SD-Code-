/*******************************************************************************
* File Name: COMP_Relay.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_COMP_Relay_H) /* Pins COMP_Relay_H */
#define CY_PINS_COMP_Relay_H

#include "cytypes.h"
#include "cyfitter.h"
#include "COMP_Relay_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} COMP_Relay_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   COMP_Relay_Read(void);
void    COMP_Relay_Write(uint8 value);
uint8   COMP_Relay_ReadDataReg(void);
#if defined(COMP_Relay__PC) || (CY_PSOC4_4200L) 
    void    COMP_Relay_SetDriveMode(uint8 mode);
#endif
void    COMP_Relay_SetInterruptMode(uint16 position, uint16 mode);
uint8   COMP_Relay_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void COMP_Relay_Sleep(void); 
void COMP_Relay_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(COMP_Relay__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define COMP_Relay_DRIVE_MODE_BITS        (3)
    #define COMP_Relay_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - COMP_Relay_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the COMP_Relay_SetDriveMode() function.
         *  @{
         */
        #define COMP_Relay_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define COMP_Relay_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define COMP_Relay_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define COMP_Relay_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define COMP_Relay_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define COMP_Relay_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define COMP_Relay_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define COMP_Relay_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define COMP_Relay_MASK               COMP_Relay__MASK
#define COMP_Relay_SHIFT              COMP_Relay__SHIFT
#define COMP_Relay_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in COMP_Relay_SetInterruptMode() function.
     *  @{
     */
        #define COMP_Relay_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define COMP_Relay_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define COMP_Relay_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define COMP_Relay_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(COMP_Relay__SIO)
    #define COMP_Relay_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(COMP_Relay__PC) && (CY_PSOC4_4200L)
    #define COMP_Relay_USBIO_ENABLE               ((uint32)0x80000000u)
    #define COMP_Relay_USBIO_DISABLE              ((uint32)(~COMP_Relay_USBIO_ENABLE))
    #define COMP_Relay_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define COMP_Relay_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define COMP_Relay_USBIO_ENTER_SLEEP          ((uint32)((1u << COMP_Relay_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << COMP_Relay_USBIO_SUSPEND_DEL_SHIFT)))
    #define COMP_Relay_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << COMP_Relay_USBIO_SUSPEND_SHIFT)))
    #define COMP_Relay_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << COMP_Relay_USBIO_SUSPEND_DEL_SHIFT)))
    #define COMP_Relay_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(COMP_Relay__PC)
    /* Port Configuration */
    #define COMP_Relay_PC                 (* (reg32 *) COMP_Relay__PC)
#endif
/* Pin State */
#define COMP_Relay_PS                     (* (reg32 *) COMP_Relay__PS)
/* Data Register */
#define COMP_Relay_DR                     (* (reg32 *) COMP_Relay__DR)
/* Input Buffer Disable Override */
#define COMP_Relay_INP_DIS                (* (reg32 *) COMP_Relay__PC2)

/* Interrupt configuration Registers */
#define COMP_Relay_INTCFG                 (* (reg32 *) COMP_Relay__INTCFG)
#define COMP_Relay_INTSTAT                (* (reg32 *) COMP_Relay__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define COMP_Relay_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(COMP_Relay__SIO)
    #define COMP_Relay_SIO_REG            (* (reg32 *) COMP_Relay__SIO)
#endif /* (COMP_Relay__SIO_CFG) */

/* USBIO registers */
#if !defined(COMP_Relay__PC) && (CY_PSOC4_4200L)
    #define COMP_Relay_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define COMP_Relay_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define COMP_Relay_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define COMP_Relay_DRIVE_MODE_SHIFT       (0x00u)
#define COMP_Relay_DRIVE_MODE_MASK        (0x07u << COMP_Relay_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins COMP_Relay_H */


/* [] END OF FILE */
