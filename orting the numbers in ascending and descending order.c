#include <xc.h>
#include <pic18f458.h>

// Configuration Bits (if required for MPLAB simulation)

// Delay function
void delay_ms(unsigned int ms) {
    for(unsigned int i = 0; i < ms; i++) {
        for(unsigned int j = 0; j < 300; j++) {
            // Rough delay loop (not precise)
        }
    }
}

void main(void) {
    int array[4] = {1, 2, 3, 4}; // Array to be sorted in descending order
    
    // Descending order sorting (Bubble Sort)
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            if(array[j] < array[j+1]) {  // Change condition for descending order
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    TRISD = 0; // Set PORTD as output

    // Display sorted values on PORTD
    for (int s = 0; s < 4; s++) {
        PORTD = array[s]; // Output sorted value to PORTD
        delay_ms(500);    // Delay for better visibility
    }
    
    while(1); // Keep the program running
}
