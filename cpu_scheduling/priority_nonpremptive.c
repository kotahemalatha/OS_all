#include<stdio.h>
#include<limits.h>
int main()
{
  int n=6;
  int PID[]={1,2,3,4,5,6};
  int AT[]={0,1,2,3,4,5};
  int BT[]={4,2,3,1,2,6};
  int priority[]={4,5,6,10,9,7};
  int prioritypref=1;
  int CT[100]={0};
  int TAT[100]={0};
  int WT[100]={0};
  int vis[100]={0};
  int completed=0;
  int completion_time=0;
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
      int temp3=priority[j];
      priority[j]=priority[j+1];
      priority[j+1]=temp3;
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
    int max=INT_MIN;
    int min=INT_MAX;
    int index=-1;
    for(int i=0;i<n;i++)
    {
      if(prioritypref==1)
      {
        if(AT[i]<=completion_time && vis[i]==0)
        {
          if(priority[i]>max)
          {
            max=priority[i];
            index=i;
          }
        } 
      }
      else if(prioritypref==0)
      {
        if(AT[i]<=completion_time && vis[i]==0)
        {
          if(priority[i]<min)
          {
            min=priority[i];
            index=i;
          }
        }
      }
    }
    if(index!=-1)
    {
      vis[index]=1;
      completed++;
      completion_time+=BT[index];
      CT[index]=completion_time;
      TAT[index]=CT[index]-AT[index];
      WT[index]=TAT[index]-BT[index];

    }
    else{
      completion_time++;
    }
  }
printf("PID  AT   BT   priority   CT   TAT   WT\n");
for(int i=0;i<n;i++)
{
  printf("\n %d %d %d %d %d %d %d\n",PID[i],AT[i],BT[i],priority[i],CT[i],TAT[i],WT[i]);
}
    
  

}