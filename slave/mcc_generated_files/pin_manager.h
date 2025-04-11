/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F18855
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set ADDR aliases
#define ADDR_TRIS                 TRISBbits.TRISB0
#define ADDR_LAT                  LATBbits.LATB0
#define ADDR_PORT                 PORTBbits.RB0
#define ADDR_WPU                  WPUBbits.WPUB0
#define ADDR_OD                   ODCONBbits.ODCB0
#define ADDR_ANS                  ANSELBbits.ANSB0
#define ADDR_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define ADDR_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define ADDR_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define ADDR_GetValue()           PORTBbits.RB0
#define ADDR_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define ADDR_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define ADDR_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define ADDR_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define ADDR_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define ADDR_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define ADDR_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define ADDR_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set COCA aliases
#define COCA_TRIS                 TRISBbits.TRISB1
#define COCA_LAT                  LATBbits.LATB1
#define COCA_PORT                 PORTBbits.RB1
#define COCA_WPU                  WPUBbits.WPUB1
#define COCA_OD                   ODCONBbits.ODCB1
#define COCA_ANS                  ANSELBbits.ANSB1
#define COCA_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define COCA_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define COCA_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define COCA_GetValue()           PORTBbits.RB1
#define COCA_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define COCA_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define COCA_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define COCA_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define COCA_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define COCA_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define COCA_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define COCA_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RHUM aliases
#define RHUM_TRIS                 TRISBbits.TRISB2
#define RHUM_LAT                  LATBbits.LATB2
#define RHUM_PORT                 PORTBbits.RB2
#define RHUM_WPU                  WPUBbits.WPUB2
#define RHUM_OD                   ODCONBbits.ODCB2
#define RHUM_ANS                  ANSELBbits.ANSB2
#define RHUM_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RHUM_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RHUM_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RHUM_GetValue()           PORTBbits.RB2
#define RHUM_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RHUM_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RHUM_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define RHUM_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define RHUM_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define RHUM_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define RHUM_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define RHUM_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set BP1 aliases
#define BP1_TRIS                 TRISBbits.TRISB3
#define BP1_LAT                  LATBbits.LATB3
#define BP1_PORT                 PORTBbits.RB3
#define BP1_WPU                  WPUBbits.WPUB3
#define BP1_OD                   ODCONBbits.ODCB3
#define BP1_ANS                  ANSELBbits.ANSB3
#define BP1_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define BP1_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define BP1_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define BP1_GetValue()           PORTBbits.RB3
#define BP1_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define BP1_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define BP1_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define BP1_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define BP1_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define BP1_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define BP1_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define BP1_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set INFO aliases
#define INFO_TRIS                 TRISBbits.TRISB4
#define INFO_LAT                  LATBbits.LATB4
#define INFO_PORT                 PORTBbits.RB4
#define INFO_WPU                  WPUBbits.WPUB4
#define INFO_OD                   ODCONBbits.ODCB4
#define INFO_ANS                  ANSELBbits.ANSB4
#define INFO_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define INFO_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define INFO_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define INFO_GetValue()           PORTBbits.RB4
#define INFO_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define INFO_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define INFO_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define INFO_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define INFO_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define INFO_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define INFO_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define INFO_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF3 pin functionality
 * @Example
    IOCBF3_ISR();
 */
void IOCBF3_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF3 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF3 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF3_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF3_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF3 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF3_SetInterruptHandler() method.
    This handler is called every time the IOCBF3 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF3_SetInterruptHandler(IOCBF3_InterruptHandler);

*/
extern void (*IOCBF3_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF3 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF3_SetInterruptHandler() method.
    This handler is called every time the IOCBF3 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF3_SetInterruptHandler(IOCBF3_DefaultInterruptHandler);

*/
void IOCBF3_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/