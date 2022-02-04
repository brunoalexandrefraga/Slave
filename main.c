/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#define __XC

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#endif

#include "system.h"        /* System funct/params, like osc/peripheral config */
//#include "user.h"          /* User funct/params, such as InitApp */
#include "modbus.h"
//#include <usart.h>
#include "adc.h"

/******************************************************************************/
/* Modbus Global Variable Declaration                                         */
/******************************************************************************/
volatile unsigned int  holdingReg[50] = { 0 };
volatile unsigned char coils[50] = { 0 };
extern volatile char modbusMessage;

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

//SAM NOT RECEIVING ANYTHING FROM TONYS GADGET..

int main(void)
{
    OpnUSART();
//    ConfigInterrupts();

//    TRISA = 0x001F;
//    TRISB = 0x03FD;
//    TRISC = 0xFFFF;
    TRISD = 0xEC0F;
    TRISE = 0x0004;
    
//    ICS_PGD1 = 
    
    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
    __builtin_write_RPCON(0x0000); // unlock PPS

    RPOR18bits.RP68R = 0x0001;    //RD4->UART1:U1TX
    RPINR18bits.U1RXR = 0x0043;    //RD3->UART1:U1RX

    __builtin_write_RPCON(0x0800); // lock PPS
    
    //Enable and configure the ADC so it can sample the potentiometer.
    ADC_SetConfiguration(ADC_CONFIGURATION_DEFAULT);
    ADC_ChannelEnable(ADC_CHANNEL_POTENTIOMETER);
    
    while (1) {
//        holdingReg[0] = 33;
        
        if (modbusMessage) {
            holdingReg[0] = ADC_Read(ADC_CHANNEL_POTENTIOMETER);
            decodeIt();
        }

        //Start code here... below is just an example
    }

}

