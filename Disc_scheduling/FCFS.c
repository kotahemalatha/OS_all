#include <stdio.h>
int main()
{
  int n=5;

  int requests[]={30,10,40,70,60};
  int initial_head=50;
  int distance=0;
  int total_seek_time=0;
  int current_position=initial_head;
  int path[]={ };
  path[0]=50;
  int k=1;
  for (int i=0;i<n;i++)
  {
    if(current_position>requests[i])
    {
      distance=current_position-requests[i];
    }
    else
    {
      distance=requests[i]-current_position;
    }
    total_seek_time+=distance;
    current_position=requests[i];
    path[i+1]=requests[i];

  }
  printf("total_seek_time is %d",total_seek_time);
  printf("the path sequence is:");
 

  for(int i=0;i<n-1;i++)
  {
    
    printf("%d->",path[i]);
  }
   printf("%d",path[n-1]);
}