#include<stdio.h>
int main()
{
  int pages[]={1,2,3,4,1,2,5,1,2,3,4,5};
  int n=sizeof(pages)/sizeof(pages[0]);
  int frames[3];
  int pagefaults=0;
  int hits=0;
  int pointer=0;
  for(int i=0;i<3;i++)
  {
    frames[i]=-1;
  }
  for(int i=0;i<n;i++)
  {
    int found=0;
    for(int k=0;k<3;k++)
    {
        if(pages[i]==frames[k])
        {
          found=1;
          hits++;
          break;
        }
    }
    if(!found)
    {
      pagefaults++;
      if(frames[pointer]==-1)
      {
        frames[pointer]=pages[i];
      }
      else
      {
        frames[pointer]=pages[i];
      }
      pointer=(pointer+1)%3;
    }
    
    printf("the current frame is");
    for(int i=0;i<3;i++)
    {
      if(frames[i]!=-1)
      {
        printf("%d ",frames[i]);
      }
    }
    printf("\n");
  }
  printf("pagefaults is %d\n",pagefaults);
  printf("hits is %d",hits);

}