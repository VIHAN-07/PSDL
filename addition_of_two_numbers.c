#include <xc.h>
#include<pic18f4550.h>
#include<stdio.h>
//#include <pic18f4550.h>
void main(void) {
    int a = 0x02;
    int b = 0x02;
    int c=0x00;
    c= a+b;
    
    TRISD= 0;
    PORTD=c;
    return;
}
