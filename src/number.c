#include "number.h"

int factorial(int num)
{
    if(num == 0) // Base case
      return 1;
    else
      return (num*factorial(num-1));
}


int isPrime(int num)
{
    int x; 
    for ( x = 2 ; x <= num - 1 ; x++ )
    { 
      if ( num%x == 0 )
        return 0;
    }
    return 1;
}
 

int ispalindrome(int num)
{
    int rem,sum=0,tempo;
    tempo=num;
    while(num>0)    
    {    
        rem=num%10;    
        sum=(sum*10)+rem;    
        num=num/10;    
    }    
    if(tempo==sum) 
    {   
       return 1; 
    }
    else     
       return 0;  

}
