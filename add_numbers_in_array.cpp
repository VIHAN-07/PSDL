#include <xc.h>
#include <pic18f458.h>

void main(void) {
    unsigned char add = 0;  // Use 8-bit type (saves memory)
    const unsigned char array[] = {1, 2, 3, 4};  // Constant to store in Flash memory
    unsigned char i;

    // Sum calculation using 8-bit variables
    for(i = 0; i < sizeof(array); i++) {
        add += array[i];
    }

    TRISD = 0;   // Set PORTD as output
    PORTD = add; // Store sum in PORTD

    while(1);    // Infinite loop to prevent unexpected execution
}
