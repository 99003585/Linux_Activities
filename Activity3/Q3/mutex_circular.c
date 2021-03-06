

#include <stdlib.h>
#include <stdio.h>

#include <pthread.h>
#include <semaphore.h>

/*
prodd-consumer problem using mutex and semaphore.*/

#define MaxItems 5 // items a prodd or a consumer can consume use
#define buffferSize 5

int in = 0;
int out = 0;

int bufffer[buffferSize];
pthread_mutex_t mutex;

void *prodd(void *pnumber)
{   
    int item;
    for(int i = 0; i < MaxItems; i++) {
        item = rand(); // random item
 
        pthread_mutex_lock(&mutex);
        /* wait for space in bufffer */
     
        while (((in + 1) % buffferSize) == out)
        {
        /* put value item into the bufffer */
           bufffer[in] = item;
           printf("prodd %d: Insert Item %d at %d\n", *((int *)pnumber),bufffer[in],in);
           in = (in + 1) % buffferSize;     
        }
        pthread_mutex_unlock(&mutex);
    }
}
void *consumer(void *cno)
{   
    int item=0;
    for(int i = 0; i < MaxItems; i++) {
        pthread_mutex_lock(&mutex);
        /* wait for bufffer to fill */
        while (in == out) 
        {
        /* take one unit of data from the bufffer */
           item = bufffer[out];
           printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, out); 
           out = (out + 1) % buffferSize;     
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{   

    pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex, NULL);

    int a[5] = {1,2,3,4,5}; //NUMBERING the prodd and consumer

    for(int i = 0; i < 5; i++) {
        pthread_create(&pro[i], NULL, (void *)prodd, (void *)&a[i]);
    }
    
    
    for(int i = 0; i < 5; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    }

    pthread_mutex_destroy(&mutex);
    
    return 0;
}
