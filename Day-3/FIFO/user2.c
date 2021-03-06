#include <stdio.h> 
#include <stdio.h>

#include <fcntl.h>

#include <stdlib.h>
#include <string.h>


int main()
{
	FILE *file2;
	int fserver,fclient;

	
	char str[256];
	char *buff;
	char *ch;


	if(fork() == 0){   
		while(1){
			 ch = malloc(10*sizeof(char));
			 scanf("%s",ch);

			 fserver=open("fserver",O_RDWR);
			 write(fserver,ch,sizeof(ch));
		}    
	}

	else{
		
		while(1){
			fclient = open("fclient",O_RDWR);
			read(fclient,ch,sizeof(ch));
			printf("%s\n",ch);
		}
	}
	close(fserver); 
	close(fclient);  
}
