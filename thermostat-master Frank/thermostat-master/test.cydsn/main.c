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

#define ADDR (0x70)
#define REG_INPUT (0x00)
#define REG_CONFIG (0x03)





int main (void)
{
    
    RED_Write(1);
    GREEN_Write(1);
    BLUE_Write(1);
    CyDelay(200);
    GREEN_Write(0);
    CyDelay(200);
    GREEN_Write(1);
    CyDelay(200);
    GREEN_Write(0);
    CyDelay(200);
    GREEN_Write(0);
    CyDelay(200);
    GREEN_Write(1);
    CyDelay(200);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */ 
    
    //I2C_1_EnableInt(); 
    //I2C_MasterClearStatus();
    //CYGlobalIntEnable; 
    //CEPIN_Write(1);
    
    uint8 write_buff[2] ={REG_CONFIG, 0xFF};
    I2C_1_Start();
    
    int status = I2C_1_I2CMasterWriteBuf(ADDR, (uint8 *) write_buff, 2, I2C_1_I2C_MODE_COMPLETE_XFER);
    if(status == I2C_1_I2C_MSTR_NO_ERROR){
        RED_Write(0); 
        CyDelay(200);
    }
    if(status == I2C_1_I2C_MSTR_BUS_BUSY){
        RED_Write(0); 
        GREEN_Write(0);
        CyDelay(200);
    }
    if(status == I2C_1_I2C_MSTR_NOT_READY){
        RED_Write(0); 
        GREEN_Write(0);
        BLUE_Write(0);
        CyDelay(200);
    }
    RED_Write(1); 
    GREEN_Write(1);
    BLUE_Write(1);
    while((I2C_1_I2CMasterStatus() & I2C_1_I2C_MSTAT_WR_CMPLT)){}
    write_buff[0] = REG_INPUT;
    uint8 read_buff[1] = {0};
    for(;;)
    {
    I2C_1_I2CMasterWriteBuf(ADDR, (uint8 *) write_buff, 1, I2C_1_I2C_MODE_NO_STOP);    
    status = I2C_1_I2CMasterReadBuf(ADDR, (uint8 *) read_buff, 1, I2C_1_I2C_MODE_COMPLETE_XFER);
    if(status == I2C_1_I2C_MSTR_NO_ERROR){
        RED_Write(0); 
        CyDelay(200);
    }
    if(status == I2C_1_I2C_MSTR_BUS_BUSY){
        RED_Write(0); 
        GREEN_Write(0);
        CyDelay(200);
    }
    if(status == I2C_1_I2C_MSTR_NOT_READY){
        RED_Write(0); 
        GREEN_Write(0);
        BLUE_Write(0);
        CyDelay(200);
    }
    while((I2C_1_I2CMasterStatus() & I2C_1_I2C_MSTAT_RD_CMPLT)){}
    
    
    if(read_buff[0] == 0){RED_Write(0);}
    else if ((read_buff[0] & 0x01)==1){BLUE_Write(0);}      //PIN 0
    else if((read_buff[0]&0x02)==1){GREEN_Write(0);}       // PIN 1
    else if((read_buff[0]&0x04)==1){GREEN_Write(0); BLUE_Write(0);} //Cyan    PIN 2
    else if((read_buff[0]&0x08)==1){GREEN_Write(0); RED_Write(0); } //yellow   PIN 3
    else if((read_buff[0]&0x10)==1){BLUE_Write(0); RED_Write(0); } //purple   PIN 4
    
    CyDelay(200);
    RED_Write(1);
    GREEN_Write(1);
    BLUE_Write(1);
    
    
    }
    
    
}

/* [] END OF FILE */
