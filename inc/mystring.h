#include<string.h>
#ifndef __MYSTRING_H
#define __MYSTRING_H
size_t mystrlen(const char *str);
char* mystrcpy(char* dest, const char* src);
char* mystrcat(char *destination, const char *source);
int mystrcmp(const char *leftStr, const char *rightStr );
#endif