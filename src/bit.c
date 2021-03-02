#include "bit.h"

int set(int num,int x) 
{ 
    return (num | (1 << (x - 1))); 
} 


// Function for clearing the ith bit of num 

int clear(int num, int i) 
{ 
    return (num & (~(1 << (i - 1)))); 
} 
  
// Function to toggle the kth bit of n 
int flip(int num, int i) 
{ 
    return (num ^ (1 << (i - 1))); 
} 
