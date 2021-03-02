#include "number.h"
int factorial(int n)
{
  if (n == 0) // Base case
    return 1;
  else
    return (n*factorial(n-1));
}

int isPrime(int a)
{
   int c;
 
   for ( c = 2 ; c <= a - 1 ; c++ )
   { 
      if ( a%c == 0 )
     return 0;
   }
   return 1;
}
 

int ispalindrome(int n){
    int r,sum=0,temp;
    temp=n;
    while(n>0)    
    {    
        r=n%10;    
        sum=(sum*10)+r;    
        n=n/10;    
    }    
    if(temp==sum)    
       return 1; 
    else     
       return 0;  

}

/*
int main(){
    return 0;
}
*/