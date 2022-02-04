/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#include <xc.h>
//#include "user.h"
#include "modbus.h"
#include "system.h"

/******************************************************************************/
/* Global Variables                                                           */
/******************************************************************************/
volatile unsigned char endOfMessage,newMessage = 1;
volatile unsigned char timerCount,messageLength,modbusMessage,z = 0;
volatile uint8_t response[125]; //Enough to return all holding-r's
volatile uint8_t received[125]; //Enough to write all holding-r's 

/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/

void __attribute__ (( interrupt, no_auto_psv )) _U1RXInterrupt(void) {
//    PORTE = 0xFFFF;
//    if (IFS0bits.U1RXIF) { // USART receive interrupt flag has been set
    while (!(U1STAHbits.URXBE == 1)) {   //Check for the RX Buffer not empty
        if (U1STAbits.OERR == 1) {
            U1STAbits.OERR=0;
        }
        
        if (!endOfMessage && !newMessage) {
            if (IFS0bits.U1TXIF) {     // check if the TXREG is empty
                received[z] = U1RXREG;
                z++;
                timerCount = 0;
            }
        }
        if (newMessage) {
            OpenTmr0();
            if (IFS0bits.U1TXIF) {     // check if the TXREG is empty
                
                received[z] = U1RXREG;
                z++;
                newMessage = 0;
                endOfMessage = 0;
                messageLength = 0;
                modbusMessage = 0;
                timerCount = 0;
//                return;
            }
        }
    }
    
    IFS0bits.U1RXIF = 0;
}

void __attribute__((__interrupt__, auto_psv)) _T1Interrupt( void ) {    
    TMR1 = 0x0000;
    
    timerCount++;
    if (timerCount > 4) {
        endOfMessage = 1;
        newMessage = 1;
        messageLength = z;
        modbusMessage = 1;
        for (z = messageLength; z != 125; z++) { //Clear rest of message
            received[z] = 0;
        }
        z = 0;
        T1CONbits.TON = 0; //Close timer0
        timerCount = 0;
    }
   
    _T1IF = 0;  // Clear flag
}