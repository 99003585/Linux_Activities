#include "maxmin.h"

int Array[1000] = {0}, maxarr[10] = {0};

int findmax()
{
  int n=10, i, tempmax = 0;
  
  pthread_t ptrarr[n];

  srand(time(0));

  for(i=0; i<1000; i++)
  {
    /* Assigning random value to Array */
    //Array[i] = random()%100;
  }
  
  
  for(i=0; i<n ; ++i)
  {
    /* Create a thread to search 100 array values */
    pthread_create(&ptrarr[i], NULL, task_body_max, (void*)(__intptr_t) i);
  }
  
  
  for(i=0; i<n ; ++i)
  {
    
    pthread_join(ptrarr[i], NULL);
  
  }
  
  
  
  for(i=0; i < n; ++i)
  {
    /* Find Minimum from thread results*/
    if(maxarr[i] > tempmax)
    {
      tempmax = maxarr[i];
    }
  }
  return tempmax;
}
