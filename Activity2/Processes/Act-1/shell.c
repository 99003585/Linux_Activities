#include "shell.h"

#define lengt 1024

void MiniShell() {

  //** get command line
  char line[lengt]; 

  // ** user command
  char *argv[100];      

  // ** set path at bin
  char *path = "/bin/";

   // ** full file path  
  char progpath[20];    

   // ** arg count
  int argc;             


  while (1) {

    // ** print shell prompt
    printf("My shell>> "); 


    if (!fgets(line, lengt, stdin))
      break;

    size_t length = strlen(line);

    if (line[length - 1] == '\n')
      line[length - 1] = '\0';

    if (strcmp(line, "exit") == 0) { 
      
      
      // ** check if command is exit
      break;
    }

    char *token; 
    
    // ** split command into separate strings
    token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
      argv[i] = token;
      token = strtok(NULL, " ");
      i++;
    }

    // ** set last value to NULL for execvp
    argv[i] = NULL; 

    argc = i; 
    
    // ** get arg count
    for (i = 0; i < argc; i++) {

      // ** print command/args
      printf("%s\n", argv[i]); 
    }

    // ** copy /bin/ to file path
    strcpy(progpath, path);    
    
    // ** add program to path
    strcat(progpath, argv[0]); 

    for (i = 0; i < strlen(progpath); i++) {
      
       // ** delete newline
      if (progpath[i] == '\n') {
        progpath[i] = '\0';
      }
    }
    int process_id = fork(); 
    //** fork child

    if (process_id == 0) { 
      
      // ** Child
      execvp(progpath, argv);
      fprintf(stderr, "Child process could not do execvp\n");

    }
    
     else { 
       
       //** Parent
      wait(NULL);
      printf("Child exited\n");
    }
  }
}
