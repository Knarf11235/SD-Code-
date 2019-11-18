/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <stdio.h>
#include <stdlib.h>


#define POWER_CHIP_COMP             (0x74)
#define POWER_CHIP_HIGH_FAN         (0x75)
#define POWER_CHIP_LOW_FAN          (0x76)
#define POWER_CHIP_HEADER_BYTE      (0xA5)
#define POWER_CHIP_READ             (0x4E)
#define POWER_CHIP_WRITE            (0x4D)
#define POWER_CHIP_SET_ADD_PTR      (0x41)
#define POWER_CHIP_AUTO_GAIN_CAL    (0x5A)
#define POWER_CHIP_AUTO_FREQ_CAL    (0x7A)
#define POWER_CHIP_AUTO_REAC_GAIN   (0x41)
#define POWER_CHIP_GEN_HIGH_ADDRESS (0x0C)
#define POWER_CHIP_LOW_VRMS_ADDRESS (0x06)
#define POWER_CHIP_LOW_IRMS_ADDRESS (0x0E)
#define POWER_CHIP_AUTO_REAC_GAIN   (0x41)
#define POWER_CHIP_READ_REGISTER    (0x4E)
#define POWER_CHIP_CHECKSUM         (0x5E)


int main (void)
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    char str[50];
    uint32_t result;
    uint8_t resbyte4;
    uint8_t resbyte3;
    uint8_t resbyte2;
    uint8_t resbyte1;
    int i;
    GREEN_Write(0);
    CyDelay(1000);
    GREEN_Write(1);
    COMP_CB_Write(1);
    HF_CB_Write(1);
    LF_CB_Write(1);
    COMP_Relay_Write(0);
    HF_Relay_Write(0);
    LF_Relay_Write(0);
    
    BLUE_Write(0);
    RED_Write(0);
    CyDelay(1000);
    
    BLUE_Write(0);
    RED_Write(0);
    CyDelay(1000);
    VR_EN_Write(1);
    uint8_t powerAddresses[3] = {POWER_CHIP_COMP, POWER_CHIP_HIGH_FAN, POWER_CHIP_LOW_FAN};
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        for(i=0;i<3;i++){
            /* Place your application code here. */
            I2C_1_I2CMasterSendStart(powerAddresses[i], I2C_1_I2C_READ_XFER_MODE, 100u);
            I2C_1_I2CMasterWriteByte(POWER_CHIP_HEADER_BYTE, 100u);
            I2C_1_I2CMasterWriteByte(0x08, 100u);
            I2C_1_I2CMasterWriteByte(POWER_CHIP_SET_ADD_PTR, 100u);
            I2C_1_I2CMasterWriteByte(POWER_CHIP_GEN_HIGH_ADDRESS, 100u);
            I2C_1_I2CMasterWriteByte(POWER_CHIP_LOW_IRMS_ADDRESS, 100u);
            I2C_1_I2CMasterWriteByte(POWER_CHIP_READ_REGISTER, 100u);
            I2C_1_I2CMasterWriteByte(0x04, 100u);
            I2C_1_I2CMasterWriteByte(POWER_CHIP_CHECKSUM, 100u);
            I2C_1_I2CMasterReadByte(I2C_1_I2C_NAK_DATA,(uint8 *) &resbyte4,100u);
            I2C_1_I2CMasterReadByte(I2C_1_I2C_NAK_DATA,(uint8 *) &resbyte3,100u);
            I2C_1_I2CMasterReadByte(I2C_1_I2C_NAK_DATA,(uint8 *) &resbyte2,100u);
            I2C_1_I2CMasterReadByte(I2C_1_I2C_NAK_DATA,(uint8 *) &resbyte1,100u);
            I2C_1_I2CMasterSendStop(100u);
            result = (resbyte4 << 24) || (resbyte4 << 16) || (resbyte4 << 8) || resbyte1;
            if(i == 0){
                sprintf(str, "COMP Current is: %lu\n", result);
                MyUART_1_PutString(str);
            }
            else if(i == 1){
                sprintf(str, "HIGH FAN Current is: %lu\n", result);
                MyUART_1_PutString(str);
            }
            else if(i == 2){
                sprintf(str, "LOW FAN Current is: %lu\n\n", result);
                MyUART_1_PutString(str);
            }
            CyDelay(1000);
        }
    }
}

/* [] END OF FILE */
