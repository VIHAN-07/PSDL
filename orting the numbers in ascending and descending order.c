#include <xc.h>
#include<pic18f4550.h>
#include<stdio.h>
void main(void) {
    // sorting array in ascending order  
   /* int array[4]={4,3,2,1};
    
    for(int  i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            int temp;
            if(array[j]>array[j+1])
            {
                temp = array[j];
                array[j]=array[j+1];
                array[j+1] = temp ; 
                
            }
        }
    }
    TRISD = 0 ;
    for (int s = 0 ; s < 4 ; s++)
    {
        PORTD = array[s];
        for(int f = 0 ; f < 1000 ; f ++)
        {
            for(int r = 0 ; r < 300 ; r ++)
            {
                
            }
        }
    }
    */
//    sorting array in descending order.
    int array[4] = {1,2,3,4};
     for(int  i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            int temp;
            if(array[j]>array[j+1])
            {
                temp = array[j];
                array[j]=array[j+1];
                array[j+1] = temp ; 
                
            }
        }
    }
    TRISD = 0 ;
    for (int s = 3 ; s >=0 ; s--)
    {
        PORTD = array[s];
        for(int f = 0 ; f < 1000 ; f ++)
        {
            for(int r = 0 ; r < 300 ; r ++)
            {
                
            }
        }
    }
    
    return;
}
