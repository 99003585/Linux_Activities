

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// structure - messg queue

struct msg_bufffer 

{
   long messg_types;
   char messg[100];
} messg;

int main() 
{
   key_t keys;
   int msg_id;

   keys = ftok("progfile", 65);  // unique key

   msg_id = msgget(keys, 0666 | IPC_CREAT);  // messg queue 
   
   messg.messg_types = 1;

   fgets(messg.messg, 100, stdin);

   printf(" %s \n", messg.messg);
   
   msgsnd(msg_id, &messg, sizeof(messg), 0);  // send  messg
   
   msgrcv(msg_id, &messg, sizeof(messg), 1, 0);  // receive messg

   printf("%s \n", messg.messg); // display messg 
   
   return 0;
}