
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h> 



int main()
{
	int file1,file3;
	int fd1;

	char str[256];
	char temp[4];
	char temp1[4];

	file1 = mkfifo("f_server",0666); 

	file3 = mkfifo("f_client",0666);

	printf("created!\n ");
}
