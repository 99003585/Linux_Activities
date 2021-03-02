#include "mystring.h"

int mystrlen(const char *str)
{
    return strlen(str);
}

char* mystrcpy(char* String1, const char* String2)
{
    return strcpy(String1,String2);
}

char* mystrcat(char *String1, const char *String2)
{
    return strcat(String1,String2);
}

int mystrcmp(const char *String1, const char *String2)
{
    return strcmp(String1,String2);
}
