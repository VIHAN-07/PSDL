#include <xc.h>
#include <pic18f4550.h>

// Configuration Bits (Set according to your hardware, if needed)
// #pragma config statements can go here

void todelay(void)
{
    T0CON = 0b00000101; // Enable Timer0, 16-bit mode, Prescaler 1:64
    TMR0H = 0xF8;       // Load high byte for delay (~50ms at 4MHz clock)
    TMR0L = 0x30;       // Load low byte

    T0CONbits.TMR0ON = 1;  // Start Timer0
    INTCONbits.TMR0IF = 0; // Clear Timer0 overflow flag

    while(INTCONbits.TMR0IF == 0); // Wait for overflow

    T0CONbits.TMR0ON = 0;  // Stop Timer0
    INTCONbits.TMR0IF = 0; // Clear overflow flag again
}

void main(void)
{ 
    TRISD = 0; // Set PORTD as output

    while(1)
    {
        PORTD = 0xAA; // Toggle pattern
        todelay();
        PORTD = 0x00; // Turn off
        todelay();
    }
}
