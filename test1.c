#include "number.h"
#include "bit.h"
#include "mystring.h"

#include <stdio.h>

int main()
{
  char s[]="Welcome!";

  int prime_no=7,palindrome_no=151,fact=4,num=5,k=1;
  

  printf("length of the string is %lu\n ",mystrlen(s));
  

  if(isPrime(prime_no))
      printf("the number is prime\n");

  if(ispalindrome(palindrome_no))
      printf("the number is palindrome\n");


  printf("factorial of %d is %d \n",fact,factorial(fact));

  printf("setting %d th of %d is %d \n",k,num,set(num,k));
  printf("setting %d th of %d is %d \n",k,num,clear(num,k));
  printf("setting %d th of %d is %d \n",k,num,flip(num,k));



  return 0;
}