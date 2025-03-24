#include <xc.h>
#include <pic18f4550.h>

// Configuration Bits
#pragma config FOSC = HS        // High-Speed Oscillator
#pragma config WDT = OFF        // Watchdog Timer Disabled
#pragma config LVP = OFF        // Low Voltage Programming Disabled
#pragma config BOR = OFF        // Brown-out Reset Disabled

#define _XTAL_FREQ 8000000      // Set system frequency to 8MHz

// Global variable to store relay state
volatile unsigned char relayState = 0;

// Function to initialize INT1 (External Interrupt on RB1)
void initINT1(void) {
    TRISBbits.TRISB1 = 1;      // Set RB1 as input (Switch)
    INTCON3bits.INT1IE = 1;    // Enable INT1 interrupt
    INTCON3bits.INT1IF = 0;    // Clear INT1 interrupt flag
    INTCON2bits.INTEDG1 = 0;   // Interrupt on falling edge (button press)
    RCONbits.IPEN = 1;         // Enable Interrupt Priorities
    INTCONbits.GIEH = 1;       // Enable high-priority interrupts
}

// Function to initialize Relay (RA4 pin)
void initRelay(void) {
    TRISAbits.TRISA4 = 0;  // Set RA4 as output (Relay control)
    LATAbits.LATA4 = 0;    // Initially turn off the relay (Change to 1 if relay is active-low)
}

// Interrupt Service Routine (ISR) for INT1
void __interrupt(high_priority) ISR(void) {
    if (INTCON3bits.INT1IF) {  // Check if INT1 caused the interrupt
        relayState = !relayState;   // Toggle relay state
        LATAbits.LATA4 = relayState; // Update relay output
        
        INTCON3bits.INT1IF = 0;    // Clear INT1 interrupt flag
    }
}

void main(void) {
    initINT1();   // Initialize External Interrupt
    initRelay();  // Initialize Relay Output

    while (1) {
        // Main loop can perform other tasks if needed
        // Relay is controlled by interrupt
    }
}
