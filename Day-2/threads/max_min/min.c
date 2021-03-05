#include "MaxMin.h"

int MinArray[1000] = {0}, minarr[10] = {0};


int findmin()
{
  
  int n=10, i, tempmin = 0;
  
  
  pthread_t ptrarr[n];

  srand(time(0));

  
  for(i=0; i<1000; i++)
  {

    
    MinArray[i] = random()%100;
  }
  
  
  for(i=0; i<n ; ++i)

    
    pthread_create(&ptrarr[i], NULL, task_body_min, (void*)(__intptr_t) i);
  }
  
  
  for(i=0; i<n ; ++i)
  {
    pthread_join(ptrarr[i], NULL);
  }
  /*for(i=0; i < n; ++i)
  {

    
    if(minarr[i] < tempmin)
    {
      tempmin = minarr[i];
    }
  }*/
  return tempmin;
}
