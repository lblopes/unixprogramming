#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

  printf("command %s has %d arguments\n", argv[0], argc-1);

  for(int i = 1 ; i < argc ; i++)
      printf("argv[%d]: %s\n",i,argv[i]);
  
  for( int i = 1 ; i < argc ; /* in body */ ) {
    if( strcmp(argv[i], "-l") == 0 ) {
      printf("l-option, valid arg: %s\n", argv[i]);
      i += 1;
    }
    else
    if( strcmp(argv[i], "-u") == 0 ) {
      printf("u-option, valid arg: %s\n", argv[i]);
      i += 1;
    }
    else
    if( strcmp(argv[i], "-f") == 0 ) {      
      printf("f-option, valid arg: %s, file is: %s\n", argv[i], argv[i+1]);
      i += 2;
    }
    else {
      printf("invalid arg: %s, usage: ./test [-l|-u] -f file\n", argv[i]);
      exit(EXIT_FAILURE);
    }
  }
  exit(EXIT_SUCCESS);
}
