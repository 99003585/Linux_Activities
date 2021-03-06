#include <stdio.h> 
#include <stdio.h>

#include <stdlib.h>
#include <string.h>

#include <fcntl.h>


int main()
{
	FILE *file1;
	int f_server,f_client;
	char *ch;
	char *buff;


	if(fork() == 0){
		while(1){   
			f_server = open("f_server",O_RDWR);

			read(f_server,ch,sizeof(ch));
			printf("%s\n",ch);
			close(f_server);
		}
	}
	else{
		while(1)
		{   
			buff = malloc(10*sizeof(char));  
			scanf("%s",buff);
			f_client = open("f_client",O_RDWR);
			write(f_client,buff,sizeof(buff)); 
			close(f_client);
		}
	}


close(f_server);
close(f_client);
}
