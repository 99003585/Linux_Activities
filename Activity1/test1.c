#include "bit.h"
#include "mystring.h"
#include "number.h"

#include <stdio.h>

int main()
{

  int prime_no=23,palindrome_no=34143,fact=6,num=6,k=1;
  char strin[]="Welcome!";
  

  printf("Length : %d\n ",mystrlen(strin));
  
  if(isPrime(prime_no))
  {
      printf("Prime\n");
  }

  if(ispalindrome(palindrome_no))
  {
        printf("Palindrome\n");
  }


  printf("factorial of %d is %d \n",fact,factorial(fact));

  printf("%d th element is set to %d \n",k,set(num,k));
  
  printf("%d th element is set to %d \n",k,clear(num,k));
  
  printf("%d th element is set to %d \n",k,flip(num,k));
  return 0;
}