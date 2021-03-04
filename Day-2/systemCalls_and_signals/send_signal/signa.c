#include "signa.h"


//childprocess
void processchild()
{ 
    int process_id; 
  
    // new child process

    if ((process_id = fork())<0) { 
        perror("fork"); 
        exit(1); 
    } 
  
    //child
    if (process_id == 0) { 
        
        signal(SIGHUP, sighup); 

        signal(SIGINT, sigint); 
        
        signal(SIGQUIT, sigquit); 
        
        for (;;) 
            ; // loop for ever 
    } 
  
    //parent

    else
    { 
        //process_id hold id of child
        
        printf("\nPARENT: sending SIGHUP\n\n"); 
        
        kill(process_id, SIGHUP); 
  

        // pause for 3 secs
        sleep(3); 
        
        printf("\nPARENT: sending SIGINT\n\n"); 
        
        kill(process_id, SIGINT); 
  
        
        // pause for 3 secs
        sleep(3); 
        
        printf("\nPARENT: sending SIGQUIT\n\n"); 
        
        kill(process_id, SIGQUIT); 
        
        sleep(3); 
    } 
} 

void sighup()   
{ 
    // reset signal

    signal(SIGHUP, sighup); 
    printf("CHILD: I have received a SIGHUP\n"); 
} 

void sigint() 
  
{ 
    // reset signal

    signal(SIGINT, sigint); 
    printf("CHILD: I have received a SIGINT\n"); 
} 
  
void sigquit() 
{ 
    // quit signal

    printf("My PARENT has Killed me!!!\n"); 
    exit(0); 
} 
