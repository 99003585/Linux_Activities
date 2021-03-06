

#include <stdlib.h>
#include <stdio.h>

#include <pthread.h>
#include <semaphore.h>

/*
producer-consumer problem using mutex and semaphore.*/

#define MaxItems 5 // items a producer or a consumer can consume use
#define BufferSize 5

int in = 0;
int out = 0;

int buffer[BufferSize];
pthread_mutex_t mutex;

void *producer(void *pno)
{   
    int item;
    for(int i = 0; i < MaxItems; i++) {
        item = rand(); // Produce a random item
        pthread_mutex_lock(&mutex);
        /* wait for space in buffer */
        while (((in + 1) % BufferSize) == out)
        {
        /* put value item into the buffer */
           buffer[in] = item;
           printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[in],in);
           in = (in + 1) % BufferSize;     
        }
        pthread_mutex_unlock(&mutex);
    }
}
void *consumer(void *cno)
{   
    int item=0;
    for(int i = 0; i < MaxItems; i++) {
        pthread_mutex_lock(&mutex);
        /* wait for buffer to fill */
        while (in == out) 
        {
        /* take one unit of data from the buffer */
           item = buffer[out];
           printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, out); 
           out = (out + 1) % BufferSize;     
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{   

    pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex, NULL);

    int a[5] = {1,2,3,4,5}; //NUMBERING the producer and consumer

    for(int i = 0; i < 5; i++) {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    }
    
    
    for(int i = 0; i < 5; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    }

    pthread_mutex_destroy(&mutex);
    
    return 0;
}
