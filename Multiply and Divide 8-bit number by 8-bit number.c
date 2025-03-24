#include <xc.h>
#include <pic18f458.h>

// Multiplication function
int mul(int num1, int num2) {
    int res = 0;
    for(int i = 0; i < num2; i++) {
        res += num1;
    }
    return res; // Return result instead of writing to PORTD
}

// Division function
int divide(int num1, int num2) {
    int quotient = 0;
    int remainder = num1;

    while (remainder >= num2) {
        remainder -= num2;
        quotient++;
    }
    return quotient; // Return result instead of writing to PORTB
}

void main(void) {
    TRISD = 0; // Set PORTD as output
    TRISB = 0; // Set PORTB as output

    int result1 = mul(2, 2);
    int result2 = divide(8, 2);

    PORTD = result1 & 0xFF; // Store only lower 8 bits
    PORTB = result2 & 0xFF; // Store only lower 8 bits

    while(1); // Infinite loop to keep output stable
}
