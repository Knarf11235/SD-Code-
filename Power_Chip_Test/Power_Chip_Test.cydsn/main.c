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
#define POWER_CHIP_GEN_HIGH_ADDRESS (0x00)
#define POWER_CHIP_LOW_VRMS_ADDRESS (0x06)
#define POWER_CHIP_LOW_IRMS_ADDRESS (0x0E)
#define POWER_CHIP_AUTO_REAC_GAIN   (0x41)
#define POWER_CHIP_READ_REGISTER    (0x4E)
#define POWER_CHIP_WRITE_REGISTER   (0x4D)
#define POWER_CHIP_CHECKSUM         (0x5E)
#define POWER_CHIP_LOW_ID_ADDRESS   (0x04)
#define POWER_CHIP_LOW_IG_ADDRESS   (0x60)
#define POWER_CHIP_LOW_VG_ADDRESS   (0x62)

uint16_t VRMS_Read(uint8_t address);
uint16_t IRMS_Read(uint8_t address);
void VRMS_Gain_Write(uint8_t address, uint8_t Send_High_Byte, uint8_t Send_Low_Byte, uint8_t checksum);
void IRMS_Gain_Write(uint8_t address, uint8_t Send_High_Byte, uint8_t Send_Low_Byte, uint8_t checksum);


int main (void)
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    CyDelay(500);
    char str[50];
    int result;
    uint8_t ack, numBytes,Send_High_Byte, Send_Low_Byte;
    uint16_t checksum;
    uint16_t Gain = 0;
    uint16_t VGAIN_checksum = POWER_CHIP_HEADER_BYTE + 0x10 + POWER_CHIP_SET_ADD_PTR + POWER_CHIP_LOW_VG_ADDRESS + POWER_CHIP_WRITE_REGISTER + 0x02;
    uint16_t IGAIN_checksum = POWER_CHIP_HEADER_BYTE + 0x10 + POWER_CHIP_SET_ADD_PTR + POWER_CHIP_LOW_IG_ADDRESS + POWER_CHIP_WRITE_REGISTER + 0x02;
    //uint32_t resbyte4;
    //uint32_t resbyte3;
    uint32_t resbyte2;
    uint32_t resbyte1;
    //int i;
    HF_Relay_Write(1);
    LF_Relay_Write(1);
    COMP_Relay_Write(0);
    GREEN_Write(0);
    CyDelay(1000);
    GREEN_Write(1);
    COMP_CB_Write(1);
    HF_CB_Write(1);
    LF_CB_Write(1);
    HF_Relay_Write(1);
    LF_Relay_Write(0);
    
    BLUE_Write(0);
    RED_Write(0);
    CyDelay(1000);
    
    BLUE_Write(0);
    RED_Write(0);
    CyDelay(1000);
    VR_EN_Write(1);
    uint8_t powerAddresses[3] = {POWER_CHIP_COMP, POWER_CHIP_HIGH_FAN, POWER_CHIP_LOW_FAN};
    uint16_t VRMS;
    uint32_t IRMS;
    
    COMP_Relay_Write(1);
    //Send_High_Byte = 0x00;
    //Send_Low_Byte = 0x04;
    //Comp Vrms gain is 4
    //COMP IRMS Gain is 6
    //High Fan VRMS Gain is 4
    //High Fan IRMS Gain is 6
    //Low Fan VRMS Gain is 4
    //Low Fan Vrms gain is 6
     CyGlobalIntEnable;  /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
    //Check correct gain
    //VGAIN_checksum = (VGAIN_checksum + Send_High_Byte + Send_Low_Byte) % 0x100;
    
    //VRMS_Gain_Write(powerAddresses[0], Send_Low_Byte, Send_High_Byte, VGAIN_checksum);
    
        Gain++;
        Send_High_Byte = (uint8_t) (Gain >> 8);
        Send_Low_Byte = (Gain & 0x00FF);
    
        
        
        
        
        /*
        VGAIN_checksum = (VGAIN_checksum + Send_High_Byte + Send_Low_Byte) % 0x100;
        VRMS_Gain_Write(powerAddresses[1], Send_High_Byte, Send_Low_Byte, VGAIN_checksum);
        
        VRMS = VRMS_Read(powerAddresses[1]);
        
        sprintf(str, "Gain is: %u\t", Gain);
        MyUART_1_PutString(str);
        
        sprintf(str, "COMP Voltage is: %u\n", VRMS);
        MyUART_1_PutString(str);
        */
        
        IGAIN_checksum = (IGAIN_checksum + Send_High_Byte + Send_Low_Byte) % 0x100;
        IRMS_Gain_Write(powerAddresses[2], Send_High_Byte, Send_Low_Byte, IGAIN_checksum);
        
        IRMS = IRMS_Read(powerAddresses[2]);
        
        sprintf(str, "Gain is: %u\t", Gain);
        MyUART_1_PutString(str);
        
        sprintf(str, "COMP Current is: %u\n", IRMS);
        MyUART_1_PutString(str);   
        
        
            
            
            
            
            //HF_Relay_Write(0);
            //LF_Relay_Write(0);
            //COMP_Relay_Write(0);
            /*
            
            
            
            if(i == 0){
                sprintf(str, "COMP ID is: %u\n", result);
                MyUART_1_PutString(str);
            }
            else if(i == 1){
                sprintf(str, "HIGH FAN ID is: %u\n", result);
                MyUART_1_PutString(str);
            }
            else if(i == 2){
                sprintf(str, "LOW FAN ID is: %u\n\n", result);
                MyUART_1_PutString(str);
            }*/
        //}
        if(Gain == 0x00FF)
            CyDelay(30000);
    }
}

/* [] END OF FILE */


uint16_t VRMS_Read(uint8_t address){
    uint16_t ack, checksum, numBytes, resbyte2, resbyte1;
    uint16_t VRMS;
    I2C_1_I2CMasterSendStart(address, I2C_1_I2C_WRITE_XFER_MODE, 100u);
    I2C_1_I2CMasterWriteByte(POWER_CHIP_HEADER_BYTE, 100u);
    I2C_1_I2CMasterWriteByte(0x08, 100u);//# in frame
    I2C_1_I2CMasterWriteByte(POWER_CHIP_SET_ADD_PTR, 100u);
    I2C_1_I2CMasterWriteByte(POWER_CHIP_GEN_HIGH_ADDRESS, 100u);
    I2C_1_I2CMasterWriteByte(POWER_CHIP_LOW_VRMS_ADDRESS, 100u);
    I2C_1_I2CMasterWriteByte(POWER_CHIP_READ_REGISTER, 100u);
    I2C_1_I2CMasterWriteByte(0x02, 100u);//# to read
    I2C_1_I2CMasterWriteByte(0x44, 100u);
    I2C_1_I2CMasterSendStop(100u);
    
    I2C_1_Sleep();
    I2C_1_Wakeup();
    
    I2C_1_I2CMasterSendStart(address, I2C_1_I2C_READ_XFER_MODE, 100u);
    I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA, (uint8_t*) &ack,100u);
    I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA, (uint8_t*) &numBytes,100u);
    I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA, (uint8_t*) &resbyte2,100u);
    I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA, (uint8_t*) &resbyte1,100u);
    I2C_1_I2CMasterReadByte(I2C_1_I2C_NAK_DATA, (uint8_t*) &checksum,100u);
    I2C_1_I2CMasterSendStop(100u);
    
    VRMS = (resbyte2 << 8) | resbyte1;
    return VRMS;
}

void VRMS_Gain_Write(uint8_t address, uint8_t Send_High_Byte, uint8_t Send_Low_Byte, uint8_t checksum){
    
    I2C_1_I2CMasterSendStart(address, I2C_1_I2C_WRITE_XFER_MODE, 100u);
    I2C_1_I2CMasterWriteByte(POWER_CHIP_HEADER_BYTE, 100u);
    I2C_1_I2CMasterWriteByte(0x10, 100u);//# in frame
    I2C_1_I2CMasterWriteByte(POWER_CHIP_SET_ADD_PTR, 100u);
    I2C_1_I2CMasterWriteByte(POWER_CHIP_GEN_HIGH_ADDRESS, 100u);
    I2C_1_I2CMasterWriteByte(POWER_CHIP_LOW_VG_ADDRESS, 100u);
    I2C_1_I2CMasterWriteByte(POWER_CHIP_WRITE_REGISTER, 100u);
    I2C_1_I2CMasterWriteByte(0x02, 100u);//# to read
    I2C_1_I2CMasterWriteByte(Send_High_Byte, 100u);
    I2C_1_I2CMasterWriteByte(Send_Low_Byte, 100u);
    I2C_1_I2CMasterWriteByte(checksum, 100u);
    I2C_1_I2CMasterSendStop(100u);
    
}


uint16_t IRMS_Read(uint8_t address){
    uint16_t ack, checksum, numBytes, resbyte2, resbyte1;
    uint32_t resbyte4, resbyte3;
    uint16_t IRMS;
    I2C_1_I2CMasterSendStart(address, I2C_1_I2C_WRITE_XFER_MODE, 100u);
    I2C_1_I2CMasterWriteByte(POWER_CHIP_HEADER_BYTE, 100u);
    I2C_1_I2CMasterWriteByte(0x08, 100u);//# in frame
    I2C_1_I2CMasterWriteByte(POWER_CHIP_SET_ADD_PTR, 100u);
    I2C_1_I2CMasterWriteByte(POWER_CHIP_GEN_HIGH_ADDRESS, 100u);
    I2C_1_I2CMasterWriteByte(POWER_CHIP_LOW_IRMS_ADDRESS, 100u);
    I2C_1_I2CMasterWriteByte(POWER_CHIP_READ_REGISTER, 100u);
    I2C_1_I2CMasterWriteByte(0x02, 100u);//# to read
    I2C_1_I2CMasterWriteByte(0x4C, 100u);
    I2C_1_I2CMasterSendStop(100u);
    
    I2C_1_Sleep();
    I2C_1_Wakeup();
    
    I2C_1_I2CMasterSendStart(address, I2C_1_I2C_READ_XFER_MODE, 100u);
    I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA, (uint8_t*) &ack,100u);
    I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA, (uint8_t*) &numBytes,100u);
    I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA, (uint8_t*) &resbyte4,100u);
    I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA, (uint8_t*) &resbyte3,100u);
    I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA, (uint8_t*) &resbyte2,100u);
    I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA, (uint8_t*) &resbyte1,100u);
    I2C_1_I2CMasterReadByte(I2C_1_I2C_NAK_DATA, (uint8_t*) &checksum,100u);
    I2C_1_I2CMasterSendStop(100u);
    
    IRMS = (resbyte4 << 24) | (resbyte3 <<16 ) | (resbyte2 << 8) | resbyte1;
    return IRMS;
}

void IRMS_Gain_Write(uint8_t address, uint8_t Send_High_Byte, uint8_t Send_Low_Byte, uint8_t checksum){
    
    I2C_1_I2CMasterSendStart(address, I2C_1_I2C_WRITE_XFER_MODE, 100u);
    I2C_1_I2CMasterWriteByte(POWER_CHIP_HEADER_BYTE, 100u);
    I2C_1_I2CMasterWriteByte(0x10, 100u);//# in frame
    I2C_1_I2CMasterWriteByte(POWER_CHIP_SET_ADD_PTR, 100u);
    I2C_1_I2CMasterWriteByte(POWER_CHIP_GEN_HIGH_ADDRESS, 100u);
    I2C_1_I2CMasterWriteByte(POWER_CHIP_LOW_IG_ADDRESS, 100u);
    I2C_1_I2CMasterWriteByte(POWER_CHIP_WRITE_REGISTER, 100u);
    I2C_1_I2CMasterWriteByte(0x02, 100u);//# to read
    I2C_1_I2CMasterWriteByte(Send_High_Byte, 100u);
    I2C_1_I2CMasterWriteByte(Send_Low_Byte, 100u);
    I2C_1_I2CMasterWriteByte(checksum, 100u);
    I2C_1_I2CMasterSendStop(100u);
    
}