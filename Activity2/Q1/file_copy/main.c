#include "copy.h"

int main()
{
    bool copy;
    copy = cpyfile();

    if(copy)
    {
        printf("Copy Successfull\n");
    }
    else
    {
        printf("Content copy unsuccessfull\n");
    }
  
    return 0;
}
