#include "fcount.h"

int line_count, chara_count, word_count;


void filecount()
{
	int fdd1,no_bytes;
	char ch[100];

  fdd1=open("file1.txt",O_RDONLY);
	  if(fdd1<0)
	  {
		  perror("open");
		  exit(1);
	  }

  word_count = 0;
  line_count= 0;
    while(no_bytes=read(fdd1,ch,sizeof(ch)))
    {
        for(int i=0;i<no_bytes;i++)
        {
            // Check new line
            if (ch[i] == '\n')
               line_count++;
            /* Check word_count */
            if (ch[i] == ' ' || ch[i] == '\t' || ch[i] == '\n')
               word_count++;
        }
        chara_count=no_bytes;
    }
    /* Close files to release resources */
    close(fdd1);
}

int lineCount()
{
  return line_count;
}
int characterCount()
{
  return chara_count;
}
int wordCount()
{
  return word_count;
}
