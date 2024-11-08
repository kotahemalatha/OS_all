#include<stdio.h>
int main()
{
  int n=5;// number of processes
  int PID[5]={1,2,3,4,5};
  int mem_req[]={100,250,30,300,150};
  int m=6;// number of memory partitions
  int RAM[]={100,150,300,10,400,100};
  int internal_frag[]={100,150,300,10,400,100};
  int status[5]={0};
  int job[100]={-1};
  for(int i=0;i<n;i++)
  {
    int allocated=0;
    for(int j=0;j<m;j++)
    {
      if(RAM[j]>=mem_req[i] && status[j]==0)
      {
        status[j]=1;
        job[j]=i+1;
        internal_frag[j]=RAM[j]-mem_req[i];
        allocated=1;
        break;
      }
    }
    if(allocated==0)
    {
      printf("\nprocess %d with mem_req %d cannot be allocated\n",PID[i],mem_req[i]);

    }
  }
  // Output the allocation results
    printf("\nMemory Allocation Table:\n");
    printf("Partition  Size  Process  Internal Fragmentation  status\n");
    for (int i = 0; i < m; i++) {
        if (job[i] != -1) {
            printf("%d          %d      %d        %d     %d\n", i + 1, RAM[i], job[i], internal_frag[i],status[i]);
        }
         
        
    }
   
   
   
   


  }

