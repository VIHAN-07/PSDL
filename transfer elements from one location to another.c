#include <xc.h>
#include<pic18f4550.h>
#include<stdio.h>
void main(void) {
    
    
    int source[4]={1,2,3,4};
    int dest[4]={0,0,0,0};
    
    for(int i =0; i<4; i++)
    {
        dest[i]=source[i];
    }
    TRISD = 0 ;
    
    for(int i = 0 ; i < 4 ; i++ )
    {
        PORTD = dest[i];
        for(int j = 0 ; j < 1000; j++)
        {
            for(int k = 0 ; k < 500 ; k ++)
            {
                
            }
        }
    }
    return;
}
