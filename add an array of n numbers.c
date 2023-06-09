#include <xc.h>
#include<stdio.h>
#include<pic18f4550.h>
void main(void) {
    
    int a = 0x04;
    int add=0x00;
    
    int array[0x04]={ 0x01,0x02,0x03,0x04};
    int i = 0x00;
    for(i = 0; i< a ; i++)
    {
        add=add+array[i];
    }
    TRISD=0;
    PORTD=add;
    return;
}
