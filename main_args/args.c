#include <stdio.h>

int main(int argc, char* argv[]) {

  printf("command %s has %d arguments\n", argv[0], argc-1);

  for(int i = 1 ; i < argc ; i++)
      printf("argv[%d]: %s\n",i,argv[i]);
  
  for( int i = 1 ; i < argc ; /* in body */ ) {
    switch(argv[i][1]) {
    case 'l':
      printf("valid arg: %s\n", argv[i]);
      i += 1;
      break;
    case 'u':
      printf("valid arg: %s\n", argv[i]);
      i += 1;
      break;
    case 'f':
      printf("valid arg: %s, file is: %s\n", argv[i], argv[i+1]);
      i += 2;
      break;      
    default:
      printf("invalid arg: %s, usage: ./test [-l|-u] -f file\n", argv[i]);
      return 1;
    }
  }
  return 0;
}
