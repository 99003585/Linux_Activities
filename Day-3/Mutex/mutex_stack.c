#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define MaxItems 5 
#define buffferSize 5 

int in = 0;
int out = 0;
int item=0;
int bufffer[buffferSize];
pthread_mutex_t mutex;

void *producer(void *pnumber)
{   
    if(in==buffferSize-1)
    {
        printf("producer Stack is full \n");
    }
    else
    {
     for(int i = 0; i < MaxItems; i++) {
        item = rand(); 
        // Produce a random item
        pthread_mutex_lock(&mutex);
        /* put value into the bufffer */
        bufffer[in] = item;
        printf("prodd %d: Insert Item %d at %d\n", *((int *)pnumber),bufffer[in],in);
        in = (in + 1) % buffferSize;     
        pthread_mutex_unlock(&mutex);
     }
    }
}
void *consumer(void *consumernumber)
{   
    if(out==buffferSize-1)
    {
        printf("consumer stack is full\n");
    }
    else
    {
     int item=0;
     for(int i = 0; i < MaxItems; i++) {
        pthread_mutex_lock(&mutex);
        /* take one unit of data from the bufffer */
        item = bufffer[out];
        printf("consumer %d: reemove Item %d from %d\n",*((int *)cno),item, out); 
        out = (out + 1) % buffferSize;     
        pthread_mutex_unlock(&mutex);
     }
    }
}

int main()
{   

    pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex, NULL);

    int a[5] = {1,2,3,4,5}; 
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

    pthread_mutex_destroy(&mutex);

    return 0;
}