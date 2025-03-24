#include <xc.h>
#include <pic18f458.h>

void main(void) {
    unsigned char a = 2;  // Use 8-bit type (saves memory)
    unsigned char b = 2;
    unsigned char c = a + b;

    TRISD = 0;   // Set PORTD as output
    PORTD = c;   // Store sum in PORTD

    while(1);    // Infinite loop to prevent execution issues
}
