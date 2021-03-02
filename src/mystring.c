#include "mystring.h"
size_t mystrlen(const char *str){
    return strlen(str);
}
char* mystrcpy(char* dest, const char* src){
    return strcpy(dest,src);
}
char* mystrcat(char *destination, const char *source){
    return strcat(destination,source);
}
int mystrcmp(const char *leftStr, const char *rightStr ){
    return strcmp(leftStr,rightStr);
}

/*
int main(){
    return 0;
}
*/