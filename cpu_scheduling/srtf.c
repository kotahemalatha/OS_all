#include<stdio.h>
#include<limits.h>
int main()
{
  int n=6;
  int PID[]={1,2,3,4,5,6};
  int AT[]={0,1,2,3,4,5};
  int BT[]={8,5,1,2,1,4};
  int RBT[]={8,5,1,2,1,4};
  int vis[100]={0};
  int CT[100]={0};
  int TAT[100]={0};
  int WT[100]={0};
  int completed=0;
  int completion_time=0;
  int gs[100]={};
  int gsp=0;
  int ts[100];

  for(int i=0;i<n;i++)
  {
  for(int j=0;j<n-1;j++)
  {
    if(AT[j]>AT[j+1])
    {
      int temp=AT[j];
      AT[j]=AT[j+1];
      AT[j+1]=temp;
      int temp1=BT[j];
      BT[j]=BT[j+1];
      BT[j+1]=temp1;
      int temp2=PID[j];
      PID[j]=PID[j+1];
      PID[j+1]=temp2;
    }
  }
  }
printf("PID  AT  BT\n");
for(int i=0;i<n;i++)
{
  printf("%d  %d  %d\n",PID[i],AT[i],BT[i]);
}
  while(completed<n)
  {
    int min=INT_MAX;
    int index=-1;
    for(int i=0;i<n;i++)
    {
        if(AT[i]<=completion_time && vis[i]==0)
        {
          if(RBT[i]<min)
          {
            min=RBT[i];
            index=i;
            }
        }
    }

if(index!=-1)
{
  RBT[index]--;
  completion_time++;
 
  if(RBT[index]==0)
  {
    vis[index]=1;
    completed++;
    CT[index]=completion_time;
    TAT[index]=CT[index]-AT[index];
    WT[index]=TAT[index]-BT[index];
    
    
  }
  
gs[gsp]=PID[index];
ts[gsp++]=completion_time;
}
  else
  {
    completion_time++;
  }
  }
printf("\n PID  AT  BT  CT  TAT  WT  \n");
for(int i=0;i<n;i++)
{
  printf("\n%d  %d  %d  %d  %d  %d\n",PID[i],AT[i],BT[i],CT[i],TAT[i],WT[i]);
}  

for(int i=0;i<n;i++){
  printf("%d",ts[i]);
}


  



}