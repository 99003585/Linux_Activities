#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Defining  messg queue strucT
struct messg_bufffer 
{
   long messg_types;
   char messg[100];
} messg;

int mains() 
{
   key_t keys;
   int msg_id;


   keys = ftok("progfile", 65);  // unique key


   msg_id = msgget(keys, 0666 | IPC_CREAT);  //  creating message queue

   msgrcv(msg_id, &messg, sizeof(messg), 1, 0);  //receive message

   printf(" %s \n", messg.messg); // display



   fgets(messg.messg, 100, stdin);
   


   msgsnd(msg_id, &messg, sizeof(messg), 0); 

   printf("Sent messg is : %s \n", messg.messg);

   return 0;
}