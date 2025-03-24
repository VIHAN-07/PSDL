#include <xc.h>
#include <pic18f458.h>
#include <stdio.h>

void delay(void) {
    for (int j = 0; j < 1000; j++) {
        for (int k = 0; k < 500; k++) {
            // Small delay
        }
    }
}

void main(void) {
    int source[4] = {1, 2, 3, 4};
    int dest[4]; // Destination array

    // Copy source array to destination array
    for (int i = 0; i < 4; i++) {
        dest[i] = source[i];
    }

    TRISD = 0; // Set PORTD as output

    // Display values on PORTD
    for (int i = 0; i < 4; i++) {
        PORTD = dest[i];
        delay(); // Call delay function
    }

    while (1); // Infinite loop to keep the program running
}
