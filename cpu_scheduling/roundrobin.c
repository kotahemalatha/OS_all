#include<stdio.h>
#include<limits.h>

int main()
{
  int n=4;
  int PID[]={1,2,3,4};
  int AT[]={0,1,2,3};
  int BT[]={7,4,1,3};
  int RBT[]={6,5,2,3};
  int TQ=2;
  int completed=0;
  int completion_time=0;
  int vis[100]={0};
  int CT[100]={0};
  int TAT[100]={0};
  int WT[100]={0};
  int RQ[100];
  int np=0;
  int k=0,p=0;
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
  for(int m=0;m<n;m++)
  {
    printf("%d  %d  %d\n",PID[m],AT[m],BT[m]);
  }

completion_time=AT[0];
for(int i=0;i<n;i++)
{
  if(AT[i]<=completion_time)
  {
    RQ[k++]=i;
    vis[i]=1;

  }
  
  
  
  
}
while(np<n)
{
  for(;p<k;p++)
  {
    if(RBT[RQ[p]]>TQ)
    {
      completion_time+=TQ;
      RBT[RQ[p]]-=TQ;
    }
    else
    {
      completion_time+=RBT[RQ[p]];

      np++;
      RBT[RQ[p]]=0;
      CT[RQ[p]]=completion_time;
      TAT[RQ[p]]=CT[RQ[p]]-AT[RQ[p]];
      WT[RQ[p]]=TAT[RQ[p]]-BT[RQ[p]];
    }
    for(int i=0;i<n;i++)
    {
      if(AT[i]<=completion_time  && vis[i]==0)
      {
        RQ[k++]=i;
        vis[i]=1;
      }
      
      
      
      
    }
    if(RBT[RQ[p]]!=0)
    {
      RQ[k++]=RQ[p];
    }
  }
}
printf("\n PID  AT  BT  CT  TAT  WT  \n");
for(int i=0;i<n;i++)
{
  printf("\n%d  %d  %d  %d  %d  %d\n",PID[i],AT[i],BT[i],CT[i],TAT[i],WT[i]);
}  





return 0;
}