#include <xc.h>
#include <pic18f4550.h>

#define Buzzer LATAbits.LATA5  // Define buzzer pin

unsigned int count = 0;

// Interrupt Service Routine (ISR)
void __interrupt() Timer1ISR(void) {
    if (TMR1IF == 1) {  // Check Timer1 Overflow Flag
        TMR1L = 0x20;   // Reload Timer1 Low Byte
        TMR1H = 0xD1;   // Reload Timer1 High Byte
        count++;        // Increment counter

        if (count >= 1000) {  // Toggle Buzzer every 1 second
            Buzzer = ~Buzzer;
            count = 0;  // Reset counter
        }
        TMR1IF = 0;  // Clear Interrupt Flag
    }
}

void main(void) {
    TRISB = 0;  // Set PORTB as output
    TRISAbits.TRISA5 = 0;  // Set RA5 (Buzzer) as output

    // Enable Interrupts
    GIE = 1;    // Global Interrupt Enable
    PEIE = 1;   // Peripheral Interrupt Enable
    TMR1IE = 1; // Timer1 Interrupt Enable

    // Configure Timer1
    T1CON = 0x80;  // 16-bit mode, No pre-scaler, Internal Clock
    TMR1L = 0x20;  // Load Timer1 Low Byte
    TMR1H = 0xD1;  // Load Timer1 High Byte
    TMR1ON = 1;    // Turn ON Timer1

    while (1) {
        // Main loop remains empty; ISR handles the toggling
    }
}
