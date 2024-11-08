#include<stdio.h>
#include<stdlib.h>
int main()
{
  int requests[]={35,87,23,46,75,47,82,92,19};
  int n=sizeof(requests)/sizeof(requests[0]);
  int head=25;
  int disksize=100;
  int path[100];
  int index=0;
  path[index++]=head;
  int total_seek_time=0;
  int left[100],right[100];
  int left_count=0,right_count=0;
  
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n-1;j++)
    {
      if(requests[j]>requests[j+1])
      {
        int temp=requests[j];
        requests[j]=requests[j+1];
        requests[j+1]=temp;
      }
    }
  }
  for(int i=0;i<n;i++)
  {
    if(requests[i]<head)
    {
      left[left_count++]=requests[i];
    }
    else if(requests[i]>head)
    {
      right[right_count++]=requests[i];
    }
  }
      for(int i=0;i<right_count;i++)
    {
      total_seek_time+=abs(head-right[i]);
      head=right[i];
      path[index++]=head;
    }
      head=disksize-1;
      total_seek_time+=head;
      path[index++]=head;
      head=0;
      total_seek_time+=head;
      path[index++]=head;
    if(left_count>0)
      {
        for(int i=0;i<left_count;i++)
        {
          total_seek_time+=abs(head-left[i]);
          head=left[i];
          path[index++]=head;
        }
      }
  
  
  printf("total seektime is %d\n ",total_seek_time);
  for(int i=0;i<index;i++)
  {
    printf("%d ",path[i]);
  }
}
  
  
 
 
 
 
 



  
  
  

