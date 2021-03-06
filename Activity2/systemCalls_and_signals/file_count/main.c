#include "fcount.h"

int main()
{
  //printf("Traverse file\n");

  filecount();
  
  printf("Lines Count : %d\n", lineCount());
  printf("Words Count : %d\n", wordCount());
  printf("Characters Count : %d\n", characterCount());
}
