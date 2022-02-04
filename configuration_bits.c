/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#define __XC

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>    /* C18 General Include File */
#endif
#include "system.h"

#ifdef p18f8722
  // PIC18F8722 Configuration Bit Settings

  // CONFIG1H
  #pragma config OSC = HS         // Oscillator Selection bits (HS oscillator)
  #pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
  #pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Two-Speed Start-up disabled)

  // CONFIG2L
  #pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
  #pragma config BOREN = OFF      // Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
  #pragma config BORV = 3         // Brown-out Voltage bits (Minimum setting)

  // CONFIG2H
  #pragma config WDT = OFF        // Watchdog Timer (WDT disabled (control is placed on the SWDTEN bit))
  #pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

  // CONFIG3L
  #pragma config MODE = MC        // Processor Data Memory Mode Select bits (Microcontroller mode)
  #pragma config ADDRBW = ADDR20BIT// Address Bus Width Select bits (20-bit Address Bus)
  #pragma config DATABW = DATA16BIT// Data Bus Width Select bit (16-bit External Bus mode)
  #pragma config WAIT = OFF       // External Bus Data Wait Enable bit (Wait selections are unavailable for table reads and table writes)

  // CONFIG3H
  #pragma config CCP2MX = PORTC   // CCP2 MUX bit (ECCP2 input/output is multiplexed with RC1)
  #pragma config ECCPMX = PORTE   // ECCP MUX bit (ECCP1/3 (P1B/P1C/P3B/P3C) are multiplexed onto RE6, RE5, RE4 and RE3 respectively)
  #pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
  #pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RG5 input pin disabled)

  // CONFIG4L
  #pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
  #pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
  #pragma config BBSIZ = BB2K     // Boot Block Size Select bits (1K word (2 Kbytes) Boot Block size)
  #pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

  // CONFIG5L
  #pragma config CP0 = OFF        // Code Protection bit Block 0 (Block 0 (000800, 001000 or 002000-003FFFh) not code-protected)
  #pragma config CP1 = OFF        // Code Protection bit Block 1 (Block 1 (004000-007FFFh) not code-protected)
  #pragma config CP2 = OFF        // Code Protection bit Block 2 (Block 2 (008000-00BFFFh) not code-protected)
  #pragma config CP3 = OFF        // Code Protection bit Block 3 (Block 3 (00C000-00FFFFh) not code-protected)
  #pragma config CP4 = OFF        // Code Protection bit Block 4 (Block 4 (010000-013FFFh) not code-protected)
  #pragma config CP5 = OFF        // Code Protection bit Block 5 (Block 5 (014000-017FFFh) not code-protected)
  #pragma config CP6 = OFF        // Code Protection bit Block 6 (Block 6 (01BFFF-018000h) not code-protected)
  #pragma config CP7 = OFF        // Code Protection bit Block 7 (Block 7 (01C000-01FFFFh) not code-protected)

  // CONFIG5H
  #pragma config CPB = OFF        // Boot Block Code Protection bit (Boot Block (000000-0007FFh) not code-protected)
  #pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

  // CONFIG6L
  #pragma config WRT0 = OFF       // Write Protection bit Block 0 (Block 0 (000800, 001000 or 002000-003FFFh) not write-protected)
  #pragma config WRT1 = OFF       // Write Protection bit Block 1 (Block 1 (004000-007FFFh) not write-protected)
  #pragma config WRT2 = OFF       // Write Protection bit Block 2 (Block 2 (008000-00BFFFh) not write-protected)
  #pragma config WRT3 = OFF       // Write Protection bit Block 3 (Block 3 (00C000-00FFFFh) not write-protected)
  #pragma config WRT4 = OFF       // Write Protection bit Block 4 (Block 4 (010000-013FFFh) not write-protected)
  #pragma config WRT5 = OFF       // Write Protection bit Block 5 (Block 5 (014000-017FFFh) not write-protected)
  #pragma config WRT6 = OFF       // Write Protection bit Block 6 (Block 6 (01BFFF-018000h) not write-protected)
  #pragma config WRT7 = OFF       // Write Protection bit Block 7 (Block 7 (01C000-01FFFFh) not write-protected)

  // CONFIG6H
  #pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
  #pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-007FFF, 000FFF or 001FFFh) not write-protected)
  #pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

  // CONFIG7L
  #pragma config EBTR0 = OFF      // Table Read Protection bit Block 0 (Block 0 (000800, 001000 or 002000-003FFFh) not protected from table reads executed in other blocks)
  #pragma config EBTR1 = OFF      // Table Read Protection bit Block 1 (Block 1 (004000-007FFFh) not protected from table reads executed in other blocks)
  #pragma config EBTR2 = OFF      // Table Read Protection bit Block 2 (Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks)
  #pragma config EBTR3 = OFF      // Table Read Protection bit Block 3 (Block 3 (00C000-00FFFFh) not protected from table reads executed in other blocks)
  #pragma config EBTR4 = OFF      // Table Read Protection bit Block 4 (Block 4 (010000-013FFFh) not protected from table reads executed in other blocks)
  #pragma config EBTR5 = OFF      // Table Read Protection bit Block 5 (Block 5 (014000-017FFFh) not protected from table reads executed in other blocks)
  #pragma config EBTR6 = OFF      // Table Read Protection bit Block 6 (Block 6 (018000-01BFFFh) not protected from table reads executed in other blocks)
  #pragma config EBTR7 = OFF      // Table Read Protection bit Block 7 (Block 7 (01C000-01FFFFh) not protected from table reads executed in other blocks)

  // CONFIG7H
  #pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-007FFF, 000FFF or 001FFFh) not protected from table reads executed in other blocks)
#endif

#ifdef p18f4520
  #include <p18F4520.h>

  // CONFIG1H
  #pragma config OSC = HS         // Oscillator Selection bits (HS oscillator)
  #pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
  #pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

  // CONFIG2L
  #pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
  #pragma config BOREN = OFF      // Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
  #pragma config BORV = 3         // Brown Out Reset Voltage bits (Minimum setting)

  // CONFIG2H
  #pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
  #pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

  // CONFIG3H
  #pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
  #pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
  #pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
  #pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

  // CONFIG4L
  #pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
  #pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
  #pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

  // CONFIG5L
  #pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) not code-protected)
  #pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) not code-protected)
  #pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) not code-protected)
  #pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) not code-protected)

  // CONFIG5H
  #pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
  #pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

  // CONFIG6L
  #pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) not write-protected)
  #pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) not write-protected)
  #pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) not write-protected)
  #pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) not write-protected)

  // CONFIG6H
  #pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
  #pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) not write-protected)
  #pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

  // CONFIG7L
  #pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
  #pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
  #pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
  #pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

  // CONFIG7H
  #pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) not protected from table reads executed in other blocks)
#endif

#ifdef dsPIC33CK256MP508
    
    // FSEC
    #pragma config BWRP = OFF    //Boot Segment Write-Protect bit->Boot Segment may be written
    #pragma config BSS = DISABLED    //Boot Segment Code-Protect Level bits->No Protection (other than BWRP)
    #pragma config BSEN = OFF    //Boot Segment Control bit->No Boot Segment
    #pragma config GWRP = OFF    //General Segment Write-Protect bit->General Segment may be written
    #pragma config GSS = DISABLED    //General Segment Code-Protect Level bits->No Protection (other than GWRP)
    #pragma config CWRP = OFF    //Configuration Segment Write-Protect bit->Configuration Segment may be written
    #pragma config CSS = DISABLED    //Configuration Segment Code-Protect Level bits->No Protection (other than CWRP)
    #pragma config AIVTDIS = OFF    //Alternate Interrupt Vector Table bit->Disabled AIVT

    // FBSLIM
    #pragma config BSLIM = 8191    //Boot Segment Flash Page Address Limit bits->8191

    // FOSCSEL
    #pragma config FNOSC = PRIPLL    //Oscillator Source Selection->Primary Oscillator with PLL module (XT + PLL, HS + PLL, EC + PLL)
    #pragma config IESO = ON    //Two-speed Oscillator Start-up Enable bit->Start up device with FRC, then switch to user-selected oscillator source

    // FOSC
    #pragma config POSCMD = XT    //Primary Oscillator Mode Select bits->XT Crystal Oscillator Mode
    #pragma config OSCIOFNC = ON    //OSC2 Pin Function bit->OSC2 is general purpose digital I/O pin
    #pragma config FCKSM = CSDCMD    //Clock Switching Mode bits->Both Clock switching and Fail-safe Clock Monitor are disabled
    #pragma config PLLKEN = ON    //PLL Lock Status Control->PLL lock signal will be used to disable PLL clock output if lock is lost
    #pragma config XTCFG = G3    //XT Config->24-32 MHz crystals
    #pragma config XTBST = ENABLE    //XT Boost->Boost the kick-start

    // FWDT
    #pragma config RWDTPS = PS1    //Run Mode Watchdog Timer Post Scaler select bits->1:1
    #pragma config RCLKSEL = LPRC    //Watchdog Timer Clock Select bits->Always use LPRC
    #pragma config WINDIS = OFF    //Watchdog Timer Window Enable bit->Watchdog Timer in Window mode
    #pragma config WDTWIN = WIN25    //Watchdog Timer Window Select bits->WDT Window is 25% of WDT period
    #pragma config SWDTPS = PS1    //Sleep Mode Watchdog Timer Post Scaler select bits->1:1
    #pragma config FWDTEN = ON_SW    //Watchdog Timer Enable bit->WDT controlled via SW, use WDTCON.ON bit

    // FPOR
    #pragma config BISTDIS = DISABLED    //Memory BIST Feature Disable->mBIST on reset feature disabled

    // FICD
    #pragma config ICS = PGD3    //ICD Communication Channel Select bits->Communicate on PGC1 and PGD1
    #pragma config JTAGEN = OFF    //JTAG Enable bit->JTAG is disabled
    #pragma config NOBTSWP = DISABLED    //BOOTSWP instruction disable bit->BOOTSWP instruction is disabled

    // FDMTIVTL
    #pragma config DMTIVTL = 0    //Dead Man Timer Interval low word->0

    // FDMTIVTH
    #pragma config DMTIVTH = 0    //Dead Man Timer Interval high word->0

    // FDMTCNTL
    #pragma config DMTCNTL = 0    //Lower 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF)->0

    // FDMTCNTH
    #pragma config DMTCNTH = 0    //Upper 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF)->0

    // FDMT
    #pragma config DMTDIS = OFF    //Dead Man Timer Disable bit->Dead Man Timer is Disabled and can be enabled by software

    // FDEVOPT
    #pragma config ALTI2C1 = OFF    //Alternate I2C1 Pin bit->I2C1 mapped to SDA1/SCL1 pins
    #pragma config ALTI2C2 = OFF    //Alternate I2C2 Pin bit->I2C2 mapped to SDA2/SCL2 pins
    #pragma config ALTI2C3 = OFF    //Alternate I2C3 Pin bit->I2C3 mapped to SDA3/SCL3 pins
    #pragma config SMBEN = SMBUS    //SM Bus Enable->SMBus input threshold is enabled
    #pragma config SPI2PIN = PPS    //SPI2 Pin Select bit->SPI2 uses I/O remap (PPS) pins

    // FALTREG
    #pragma config CTXT1 = OFF    //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 1 bits->Not Assigned
    #pragma config CTXT2 = OFF    //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 2 bits->Not Assigned
    #pragma config CTXT3 = OFF    //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 3 bits->Not Assigned
    #pragma config CTXT4 = OFF    //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 4 bits->Not Assigned

    // FBTSEQ
    #pragma config BSEQ = 4095    //Relative value defining which partition will be active after device Reset; the partition containing a lower boot number will be active->4095
    #pragma config IBSEQ = 4095    //The one's complement of BSEQ; must be calculated by the user and written during device programming.->4095

    // FBOOT
    #pragma config BTMODE = SINGLE    //Device Boot Mode Configuration->Device is in Single Boot (legacy) mode


#endif