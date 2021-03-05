#ifndef __SENDSIGNAL_H
#define __SENDSIGNAL_H

#include <stdio.h> 
#include <stdlib.h> 

#include <signal.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
void processchild();

void sighup(); 
void sigint(); 
void sigquit(); 

#endif