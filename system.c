/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/
#define __XC

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>    /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#endif

#include "system.h"

//PLEASE NOTE THESE FUNCTIONS ONLY WORK FOR 18F4520
void OpnUSART(void)
{
    /******************************************************************************/
    /* This just sets up the relevant parameters for the UART                     */
    /******************************************************************************/
    //-----SPBRG needs to be changed depending upon oscillator frequency-------
    unsigned long spbrg = 0;

    spbrg = SYS_FREQ/BAUD_RATE; // define these in system.h
    spbrg /= 64;
    spbrg -= 1;
    ClsUSART();    //Incase USART already opened
    writeEnConf = 0; //Set up TRIS register as output for write enable/disable
    writeEnable = 0;
    #ifdef p18f4520
        TXSTA = 0;           // Reset USART registers to POR state
        RCSTA = 0;

        TRISCbits.TRISC6 = 0; // Sets transmit pin as output
        TRISCbits.TRISC7 = 1; // Sets recieve pin as input

        TXSTAbits.SYNC = 0;  // Async mode
        TXSTAbits.TX9 = 0;   // 8-bit mode
        TXSTAbits.SENDB = 0; // Sync break option (not sure)
        TXSTAbits.BRGH = 0;  // Low speed

        RCSTAbits.CREN = 1;  //Continuous receive
        RCSTAbits.RX9 = 0;   //8-bit reception

        PIE1bits.RCIE = 1;   // Interrupt on receive
        PIE1bits.TXIE = 0;   // Interrupt on transmit

        BAUDCONbits.BRG16 = 0; // 8-bit Baud register
        SPBRG = spbrg;         // Write baudrate to SPBRG1

        TXSTAbits.TXEN = 1;  // Enable transmitter
        RCSTAbits.SPEN = 1;  // Enable receiver
    #endif
    #ifdef p18f8722
        TXSTA1 = 0;           // Reset USART registers to POR state
        RCSTA1 = 0;

        TRISCbits.TRISC6 = 0; // Sets transmit pin as output
        TRISCbits.TRISC7 = 1; // Sets recieve pin as input

        TXSTA1bits.SYNC = 0;  // Async mode
        TXSTA1bits.TX9 = 0;   // 8-bit mode
        TXSTA1bits.SENDB = 0; // Sync break option (not sure)
        TXSTA1bits.BRGH = 0;  // Low speed

        RCSTA1bits.CREN = 1;  //Continuous receive
        RCSTA1bits.RX9 = 0;   //8-bit reception

        PIE1bits.RCIE = 1;   // Interrupt on receive
        PIE1bits.TXIE = 0;   // Interrupt on transmit

        BAUDCON1bits.BRG16 = 0; // 8-bit Baud register
        SPBRG = spbrg;         // Write baudrate to SPBRG1

        TXSTA1bits.TXEN = 1;  // Enable transmitter
        RCSTA1bits.SPEN = 1;  // Enable receiver
    #endif
    
    #ifdef dsPIC33CK256MP508
        // URXEN disabled; RXBIMD RXBKIF flag when Break makes low-to-high transition after being low for at least 23/11 bit periods; UARTEN enabled; MOD Asynchronous 8-bit UART; UTXBRK disabled; BRKOVR TX line driven by shifter; UTXEN disabled; USIDL disabled; WAKE disabled; ABAUD disabled; BRGH enabled; 
        // Data Bits = 8; Parity = None; Stop Bits = 1 Stop bit sent, 1 checked at RX;
        U1MODE = (0x8080 & ~(1<<15));  // disabling UARTEN bit
        // STSEL 1 Stop bit sent, 1 checked at RX; BCLKMOD disabled; SLPEN disabled; FLO Off; BCLKSEL FOSC/2; C0EN disabled; RUNOVF disabled; UTXINV disabled; URXINV disabled; HALFDPLX disabled; 
        U1MODEH = 0x00;
        // OERIE disabled; RXBKIF disabled; RXBKIE disabled; ABDOVF disabled; OERR disabled; TXCIE disabled; TXCIF disabled; FERIE disabled; TXMTIE disabled; ABDOVE disabled; CERIE disabled; CERIF disabled; PERIE disabled; 
        U1STA = 0x00;
        // URXISEL RX_ONE_WORD; UTXBE enabled; UTXISEL TX_BUF_EMPTY; URXBE enabled; STPMD disabled; TXWRE disabled;         
        U1STAH = 0x0722;
        // BaudRate = 9600; Frequency = 75000000 Hz; BRG 1952; 
        U1BRG = 0x7A0;
        // BRG 0; 
        U1BRGH = 0x00;
        // P1 0; 
        U1P1 = 0x00;
        // P2 0; 
        U1P2 = 0x00;
        // P3 0; 
        U1P3 = 0x00;
        // P3H 0; 
        U1P3H = 0x00;
        // TXCHK 0; 
        U1TXCHK = 0x00;
        // RXCHK 0; 
        U1RXCHK = 0x00;
        // T0PD 1 ETU; PTRCL disabled; TXRPT Retransmit the error byte once; CONV Direct logic; 
        U1SCCON = 0x00;
        // TXRPTIF disabled; TXRPTIE disabled; WTCIF disabled; WTCIE disabled; BTCIE disabled; BTCIF disabled; GTCIF disabled; GTCIE disabled; RXRPTIE disabled; RXRPTIF disabled; 
        U1SCINT = 0x00;
        // ABDIF disabled; WUIF disabled; ABDIE disabled; 
        U1INT = 0x00;
    
        IEC0bits.U1RXIE = 1;
//        IFS0bits.U1RXIF = 0;
        
        U1MODEbits.UARTEN = 1;   // enabling UART ON bit
        U1MODEbits.UTXEN = 1;
        U1MODEbits.URXEN = 1;
    #endif
      
}

void ClsUSART(void)
{
    #ifdef p18f4520
        RCSTA &= 0b01001111;  // Disable the receiver
        TXSTAbits.TXEN = 0;   //  and transmitter
        PIE1 &= 0b11001111;   // Disable both interrupts
    #endif
    #ifdef p18f8722
        RCSTA1 &= 0b01001111;  // Disable the receiver
        TXSTA1bits.TXEN = 0;   //  and transmitter
        PIE1 &= 0b11001111;   // Disable both interrupts
    #endif

    #ifdef dsPIC33CK256MP508
        U1MODEbits.UARTEN = 0;
        U1MODEbits.UTXEN = 0; 
        U1MODEbits.URXEN = 0;
    #endif
}

void OpenTmr0(void)
{
    T1CONbits.TON = 0;      
    _T1IE = 0;

    //(Re-)Configure the timer for 1ms interrupt rate
    _T1IF = 0;
    _T1IP = 7;
    TMR1 = 0;
    PR1 = 0x2080;
    T1CONbits.TECS = 0b10;  //FRC
    T1CONbits.TCS = 1;      //clock source based on TECS value
    T1CONbits.TSYNC = 0;    //synchronize
    T1CONbits.TCKPS = 0; //1:8
    T1CONbits.TON = 1;      //Timer on

    _T1IE = 1;
    
//    
//    
//    T1CONbits.TON = 0;
//    
//    T1CONbits.TECS = 0x0002;
//    T1CONbits.TSYNC = 0x0000;
//    T1CONbits.TCS = 0x0001;
//    T1CONbits.TGATE = 0x0000;
//    T1CONbits.TCKPS = 0x0000;
//    
//    TMR1 = 0x0000;
//    PR1 = 0x2080;
//    
//    _T1IE = 0x0001;
//    _T1IF = 0x0000;
////    _T1IP = 0x0000;
//    
//    T1CONbits.TON = 1;


    //WriteTimer0(62935); // Setup for 1.04ms overflow.. 9600baud = 1.04mS/char
    //To work this out - FOSC/4 = TOSC, (1/TOSC)*(65535) = time to overflow
}

//void ConfigInterrupts(void)
//{
//    InterruptPriority   = 0; // disable interrupt priority
//    EnableInterrupt  = 1; // enable interrupts
//    PeripheralInterrupts = 1; // enable peripheral interrupts
//}

