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


int main (void)
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Place your application code here. */
        
        Red_Write(0);
        CyDelay(1000);
        Red_Write(1);
        Green_Write(0);
        CyDelay(1000);
        Green_Write(1);
        Blue_Write(0);
        CyDelay(1000);
        Green_Write(0);
        Blue_Write(0);
        Red_Write(0);
        CyDelay(1000);
        Green_Write(1);
        Blue_Write(1);
        Red_Write(1);
    }
}

/* [] END OF FILE */
