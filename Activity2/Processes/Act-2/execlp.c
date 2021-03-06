#include "execlp.h"



void toCompile()
{
    
    process_id_t process_id=fork();
    
    int x;
    
    if (process_id==0)
    
    { 
        // child process
    	
        x=execlp("gcc","gcc","sample.c","-o", "sample.out",NULL);
        

        // only if execlp fails
        exit(127); 
    }
    else
    { 
        // process_id!=0; parent process
    	waitprocess_id(process_id,0,0);
        

         // wait for child to exit 
    	printf("Parent Process\n");
    }
}
