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
        Device            :  PIC16LF18855
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
#define ADDR_TRIS                 TRISAbits.TRISA0
#define ADDR_LAT                  LATAbits.LATA0
#define ADDR_PORT                 PORTAbits.RA0
#define ADDR_WPU                  WPUAbits.WPUA0
#define ADDR_OD                   ODCONAbits.ODCA0
#define ADDR_ANS                  ANSELAbits.ANSA0
#define ADDR_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define ADDR_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define ADDR_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define ADDR_GetValue()           PORTAbits.RA0
#define ADDR_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define ADDR_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define ADDR_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define ADDR_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define ADDR_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define ADDR_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define ADDR_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define ADDR_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set ENCA aliases
#define ENCA_TRIS                 TRISBbits.TRISB0
#define ENCA_LAT                  LATBbits.LATB0
#define ENCA_PORT                 PORTBbits.RB0
#define ENCA_WPU                  WPUBbits.WPUB0
#define ENCA_OD                   ODCONBbits.ODCB0
#define ENCA_ANS                  ANSELBbits.ANSB0
#define ENCA_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define ENCA_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define ENCA_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define ENCA_GetValue()           PORTBbits.RB0
#define ENCA_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define ENCA_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define ENCA_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define ENCA_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define ENCA_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define ENCA_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define ENCA_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define ENCA_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set ENCB aliases
#define ENCB_TRIS                 TRISBbits.TRISB1
#define ENCB_LAT                  LATBbits.LATB1
#define ENCB_PORT                 PORTBbits.RB1
#define ENCB_WPU                  WPUBbits.WPUB1
#define ENCB_OD                   ODCONBbits.ODCB1
#define ENCB_ANS                  ANSELBbits.ANSB1
#define ENCB_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define ENCB_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define ENCB_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define ENCB_GetValue()           PORTBbits.RB1
#define ENCB_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define ENCB_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define ENCB_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define ENCB_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define ENCB_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define ENCB_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define ENCB_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define ENCB_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set BP3 aliases
#define BP3_TRIS                 TRISBbits.TRISB2
#define BP3_LAT                  LATBbits.LATB2
#define BP3_PORT                 PORTBbits.RB2
#define BP3_WPU                  WPUBbits.WPUB2
#define BP3_OD                   ODCONBbits.ODCB2
#define BP3_ANS                  ANSELBbits.ANSB2
#define BP3_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define BP3_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define BP3_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define BP3_GetValue()           PORTBbits.RB2
#define BP3_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define BP3_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define BP3_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define BP3_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define BP3_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define BP3_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define BP3_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define BP3_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set ACCUSE_RX aliases
#define ACCUSE_RX_TRIS                 TRISBbits.TRISB3
#define ACCUSE_RX_LAT                  LATBbits.LATB3
#define ACCUSE_RX_PORT                 PORTBbits.RB3
#define ACCUSE_RX_WPU                  WPUBbits.WPUB3
#define ACCUSE_RX_OD                   ODCONBbits.ODCB3
#define ACCUSE_RX_ANS                  ANSELBbits.ANSB3
#define ACCUSE_RX_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define ACCUSE_RX_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define ACCUSE_RX_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define ACCUSE_RX_GetValue()           PORTBbits.RB3
#define ACCUSE_RX_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define ACCUSE_RX_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define ACCUSE_RX_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define ACCUSE_RX_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define ACCUSE_RX_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define ACCUSE_RX_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define ACCUSE_RX_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define ACCUSE_RX_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set RECOMMANDER aliases
#define RECOMMANDER_TRIS                 TRISBbits.TRISB4
#define RECOMMANDER_LAT                  LATBbits.LATB4
#define RECOMMANDER_PORT                 PORTBbits.RB4
#define RECOMMANDER_WPU                  WPUBbits.WPUB4
#define RECOMMANDER_OD                   ODCONBbits.ODCB4
#define RECOMMANDER_ANS                  ANSELBbits.ANSB4
#define RECOMMANDER_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RECOMMANDER_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RECOMMANDER_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RECOMMANDER_GetValue()           PORTBbits.RB4
#define RECOMMANDER_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RECOMMANDER_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RECOMMANDER_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define RECOMMANDER_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define RECOMMANDER_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define RECOMMANDER_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define RECOMMANDER_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define RECOMMANDER_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISCbits.TRISC0
#define LED2_LAT                  LATCbits.LATC0
#define LED2_PORT                 PORTCbits.RC0
#define LED2_WPU                  WPUCbits.WPUC0
#define LED2_OD                   ODCONCbits.ODCC0
#define LED2_ANS                  ANSELCbits.ANSC0
#define LED2_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LED2_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define LED2_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define LED2_GetValue()           PORTCbits.RC0
#define LED2_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define LED2_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define LED2_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set BP2 aliases
#define BP2_TRIS                 TRISCbits.TRISC1
#define BP2_LAT                  LATCbits.LATC1
#define BP2_PORT                 PORTCbits.RC1
#define BP2_WPU                  WPUCbits.WPUC1
#define BP2_OD                   ODCONCbits.ODCC1
#define BP2_ANS                  ANSELCbits.ANSC1
#define BP2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define BP2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define BP2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define BP2_GetValue()           PORTCbits.RC1
#define BP2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define BP2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define BP2_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define BP2_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define BP2_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define BP2_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define BP2_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define BP2_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set BP1 aliases
#define BP1_TRIS                 TRISCbits.TRISC2
#define BP1_LAT                  LATCbits.LATC2
#define BP1_PORT                 PORTCbits.RC2
#define BP1_WPU                  WPUCbits.WPUC2
#define BP1_OD                   ODCONCbits.ODCC2
#define BP1_ANS                  ANSELCbits.ANSC2
#define BP1_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define BP1_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define BP1_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define BP1_GetValue()           PORTCbits.RC2
#define BP1_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define BP1_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define BP1_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define BP1_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define BP1_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define BP1_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define BP1_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define BP1_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISCbits.TRISC3
#define LED1_LAT                  LATCbits.LATC3
#define LED1_PORT                 PORTCbits.RC3
#define LED1_WPU                  WPUCbits.WPUC3
#define LED1_OD                   ODCONCbits.ODCC3
#define LED1_ANS                  ANSELCbits.ANSC3
#define LED1_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LED1_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LED1_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LED1_GetValue()           PORTCbits.RC3
#define LED1_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define LED1_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set TEST aliases
#define TEST_TRIS                 TRISCbits.TRISC5
#define TEST_LAT                  LATCbits.LATC5
#define TEST_PORT                 PORTCbits.RC5
#define TEST_WPU                  WPUCbits.WPUC5
#define TEST_OD                   ODCONCbits.ODCC5
#define TEST_ANS                  ANSELCbits.ANSC5
#define TEST_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define TEST_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define TEST_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define TEST_GetValue()           PORTCbits.RC5
#define TEST_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define TEST_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define TEST_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define TEST_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define TEST_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define TEST_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define TEST_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define TEST_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

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
    Interrupt on Change Handler for the IOCBF1 pin functionality
 * @Example
    IOCBF1_ISR();
 */
void IOCBF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF1_SetInterruptHandler() method.
    This handler is called every time the IOCBF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(IOCBF1_InterruptHandler);

*/
extern void (*IOCBF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF1_SetInterruptHandler() method.
    This handler is called every time the IOCBF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(IOCBF1_DefaultInterruptHandler);

*/
void IOCBF1_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF2 pin functionality
 * @Example
    IOCBF2_ISR();
 */
void IOCBF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF2_SetInterruptHandler() method.
    This handler is called every time the IOCBF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(IOCBF2_InterruptHandler);

*/
extern void (*IOCBF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF2_SetInterruptHandler() method.
    This handler is called every time the IOCBF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(IOCBF2_DefaultInterruptHandler);

*/
void IOCBF2_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF1 pin functionality
 * @Example
    IOCCF1_ISR();
 */
void IOCCF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_InterruptHandler);

*/
extern void (*IOCCF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_DefaultInterruptHandler);

*/
void IOCCF1_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF2 pin functionality
 * @Example
    IOCCF2_ISR();
 */
void IOCCF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF2_SetInterruptHandler() method.
    This handler is called every time the IOCCF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(IOCCF2_InterruptHandler);

*/
extern void (*IOCCF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF2_SetInterruptHandler() method.
    This handler is called every time the IOCCF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(IOCCF2_DefaultInterruptHandler);

*/
void IOCCF2_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/