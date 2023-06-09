#include <xc.h>
#include<pic18f4550.h>
#include<stdio.h>
void main(void) {
    int a = 0x04;
    int b = 0x06;
    
    int c = 0x00 ;
    
//    c = a*b;
    c = b/a;
    TRISD = 0 ;
    PORTD = c;
    
    return;
}
