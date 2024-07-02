#include <stdlib.h>
#include <stdio.h>

int main()
{
  int i,j,k;
  void *ptrs[1000];
  void *ptrs2[1000];
  void *ptrs3[1000];

  for(i=0;i<1000;i++)
  {
    ptrs[i]=malloc(1000);
    if(ptrs[i]==NULL)
    {
      printf("Error\n");
      exit(1);
    }
    for (j=0;j<100;j++)
    {
      *((char*)ptrs[i]+j)=(char)i;
    }
  }
  for(k=0;k<1000;k+=2)
  {
    free(ptrs[k]);
  }

  for(i=0;i<1000;i++)
  {
    ptrs2[i]=malloc(512);
    if(ptrs2[i]==NULL)
    {
      printf("Error\n");
      exit(1);
    }
    for (j=0;j<100;j++)
    {
      *((char*)ptrs2[i]+j)=(char)i;
    }
  }
  for(k=1;k<1000;k+=2)
  {
    free(ptrs[k]);
  }
   for(i=0;i<1000;i++)
  {
    ptrs3[i]=malloc(750);
    if(ptrs3[i]==NULL)
    {
      printf("Error\n");
      exit(1);
    }
    for (j=0;j<100;j++)
    {
      *((char*)ptrs3[i]+j)=(char)i;
    }
  }
  for(k=0;k<1000;k++)
  {
    free(ptrs2[k]);
  }
  for(k=0;k<1000;k++)
  {
    free(ptrs3[k]);
  }
  return 0;
}
