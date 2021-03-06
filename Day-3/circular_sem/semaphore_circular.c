#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>



#define MaxItems 5 // Maximum items a prodd can produce or a consumer can consume
#define buffferSize 5 // Size of the bufffer

sem_t empty;
sem_t full;

int in = 0;
int out = 0;
int bufffer[buffferSize];

void *prodd(void *pnumber)
{   
    int item;
    for(int i = 0; i < MaxItems; i++) {
        item = rand(); // random item
        sem_wait(&empty);


        while (((in + 1) % buffferSize) == out)
        {
        /* put value item into the bufffer */
           bufffer[in] = item;
           printf(" %d: %d at %d\n", *((int *)pnumber),bufffer[in],in);
           in = (in + 1) % buffferSize;     
        }
        sem_post(&full);
    }
}
void *consumer(void *cno)
{   
    int item=0;
    for(int i = 0; i < MaxItems; i++) {
        sem_wait(&full);
        /* wait for bufffer to fill */
        while (in == out) 
        {
        /* take one unit */
           item = bufffer[out];
           printf("%d: Remove Item %d from %d\n",*((int *)cno),item, out); 
           out = (out + 1) % buffferSize;     
        }
        sem_post(&empty);
    }
}

int main()
{   

    pthread_t pro[5],con[5];
    sem_init(&empty,0,buffferSize);
    sem_init(&full,0,0);

    int a[5] = {1,2,3,4,5}; //numbering the prodd and consumer

    for(int i = 0; i < 5; i++) {
        pthread_create(&pro[i], NULL, (void *)prodd, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(con[i], NULL);
    }

    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}