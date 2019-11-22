/*******************************************************************************
* File Name: HF_CB.h  
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

#if !defined(CY_PINS_HF_CB_H) /* Pins HF_CB_H */
#define CY_PINS_HF_CB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "HF_CB_aliases.h"


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
} HF_CB_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   HF_CB_Read(void);
void    HF_CB_Write(uint8 value);
uint8   HF_CB_ReadDataReg(void);
#if defined(HF_CB__PC) || (CY_PSOC4_4200L) 
    void    HF_CB_SetDriveMode(uint8 mode);
#endif
void    HF_CB_SetInterruptMode(uint16 position, uint16 mode);
uint8   HF_CB_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void HF_CB_Sleep(void); 
void HF_CB_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(HF_CB__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define HF_CB_DRIVE_MODE_BITS        (3)
    #define HF_CB_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - HF_CB_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the HF_CB_SetDriveMode() function.
         *  @{
         */
        #define HF_CB_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define HF_CB_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define HF_CB_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define HF_CB_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define HF_CB_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define HF_CB_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define HF_CB_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define HF_CB_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define HF_CB_MASK               HF_CB__MASK
#define HF_CB_SHIFT              HF_CB__SHIFT
#define HF_CB_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in HF_CB_SetInterruptMode() function.
     *  @{
     */
        #define HF_CB_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define HF_CB_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define HF_CB_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define HF_CB_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(HF_CB__SIO)
    #define HF_CB_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(HF_CB__PC) && (CY_PSOC4_4200L)
    #define HF_CB_USBIO_ENABLE               ((uint32)0x80000000u)
    #define HF_CB_USBIO_DISABLE              ((uint32)(~HF_CB_USBIO_ENABLE))
    #define HF_CB_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define HF_CB_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define HF_CB_USBIO_ENTER_SLEEP          ((uint32)((1u << HF_CB_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << HF_CB_USBIO_SUSPEND_DEL_SHIFT)))
    #define HF_CB_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << HF_CB_USBIO_SUSPEND_SHIFT)))
    #define HF_CB_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << HF_CB_USBIO_SUSPEND_DEL_SHIFT)))
    #define HF_CB_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(HF_CB__PC)
    /* Port Configuration */
    #define HF_CB_PC                 (* (reg32 *) HF_CB__PC)
#endif
/* Pin State */
#define HF_CB_PS                     (* (reg32 *) HF_CB__PS)
/* Data Register */
#define HF_CB_DR                     (* (reg32 *) HF_CB__DR)
/* Input Buffer Disable Override */
#define HF_CB_INP_DIS                (* (reg32 *) HF_CB__PC2)

/* Interrupt configuration Registers */
#define HF_CB_INTCFG                 (* (reg32 *) HF_CB__INTCFG)
#define HF_CB_INTSTAT                (* (reg32 *) HF_CB__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define HF_CB_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(HF_CB__SIO)
    #define HF_CB_SIO_REG            (* (reg32 *) HF_CB__SIO)
#endif /* (HF_CB__SIO_CFG) */

/* USBIO registers */
#if !defined(HF_CB__PC) && (CY_PSOC4_4200L)
    #define HF_CB_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define HF_CB_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define HF_CB_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define HF_CB_DRIVE_MODE_SHIFT       (0x00u)
#define HF_CB_DRIVE_MODE_MASK        (0x07u << HF_CB_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins HF_CB_H */


/* [] END OF FILE */
