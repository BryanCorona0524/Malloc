#include <stdlib.h>
#include <stdio.h>

int main()
{
  char * ptr = (char*) malloc ( 100000 );
  char * ptrs[1000];

  int i;
  for ( i = 0; i < 1000; i+=2 )
  {
    ptrs[i] = ( char * ) malloc ( 1024 ); 
    
    ptrs[i] = ptrs[i];
  }

  free( ptr );

  for ( i = 1; i < 1000; i+=2 )
  {
    ptrs[i] = ( char * ) malloc ( 1024 ); 
    
    ptrs[i] = ptrs[i];
  }

  for(i=0;i<1000;i+=2)
  {
    free(ptrs[i]);
  }

  char * ptr2 = (char*) malloc ( 1234 );
  char * ptr3 = (char*) malloc ( 100000 );

  for(i=1;i<1000;i+=2)
  {
    free(ptrs[i]);
  }

  ptr = ( char * ) malloc ( 5000 );

  free(ptr); 
  free(ptr2);
  free(ptr3);
  return 0;
}
