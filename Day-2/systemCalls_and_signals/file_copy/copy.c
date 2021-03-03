#include "copy.h"

//function to copy copy one file contents to other

bool cpyfile()
{
	int fdd,fdd1,no, flag;

	//file1 in readonly
	fdd=open("file1.txt",O_RDONLY); 

	//file2 in writeonly
	fdd1=open("file2.txt",O_WRONLY|O_CREAT, 0666);
	
	//open error
	if(fdd<0 || fdd1<0)
	{
		perror("open file!");
		exit(1);
	}

	int maximum_len=128;
	char buf[maximum_len];

	//read error
	no=read(fdd,buf,maximum_len);
	if(no<0)
	{
		perror("read file!");
		exit(2);
	}

	flag = write(fdd1,buf,no);

	//close
	close(fdd);
	close(fdd1);


	if(flag)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
		





