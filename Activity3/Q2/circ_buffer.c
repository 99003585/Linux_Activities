#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>

#include<stdio.h>
#include <stdio.h>

# define max 8

sem_t empty;
sem_t full;

int circular_queue[max];

int fro = -1;
int rearr = -1;

void insert(int item);
void delete();

void* pd(void* pp)
{ 
   int item;
   sem_wait(&empty);
   scanf("%d",&item);
   

   insert(item);
   printf("\n");
   sem_post(&full);
}
void* cd(void* pp)
{
 sem_wait(&full);
  delete();
   sem_post(&empty);
}

void insert(int item)
{

if((fro == 0 && rearr == max-1) || (fro == rearr+1))
{
printf("Queuee  Overflow n");
return;
}

if(fro == -1)
{
fro = 0;
rearr = 0;
}

else
{
if(rearr == max-1)
rearr = 0;
else
rearr = rearr+1;
}

circular_queue[rearr] = item ;
printf("%d\n",item);
}



void delete()
{
if(fro == -1)
{
printf("underflow");
return ;
}
printf(" %d\n",circular_queue[fro]);
if(fro == rearr)
{
fro = -1;
rearr=-1;
}
else
{
if(fro == max-1)
fro = 0;
else
fro = fro+1;
}
}


int main()
{
  int item;
   sem_init(&empty,0,max);
    sem_init(&full,0,0);
    pthread_t pro[8],con[8];
   printf("Enter  the  items \n ");
   for(int i = 0; i < 8; i++) {
    pthread_create(&pro[i], NULL, (void *)pd, NULL);
    }
     for(int i = 0; i < 8; i++) {
        pthread_create(&con[i], NULL, (void *)cd,NULL);
    }
     for(int i = 0; i < 8; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 8; i++) {
        pthread_join(con[i], NULL);
    }
       sem_destroy(&empty);
    sem_destroy(&full);
    
return 0;
}
