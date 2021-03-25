#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * simple string manipulation: strdup, strcmp, strcpy, strcat
 */

int main(int argc, char* argv[]) {
  /* duplicate args for manipulation */
  char* p1 = strdup(argv[1]);
  char* p2 = strdup(argv[2]);  
  char* p3 = (char*)malloc(strlen(p1) + strlen(p2) + 1);
  char* p4 = (char*)malloc(strlen(p1) + strlen(p2) + 1);  
  
  int result = strcmp(p1,p2);
  if ( result == 0 )
    printf("the strings are the same\n");
  else if (result < 0)
    printf("%s < %s\n", p1, p2);
  else
    printf("%s > %s\n", p1, p2);

  strcpy(p3,p1);
  strcat(p3," ");
  strcat(p3,p2);

  strcpy(p4,p2);  
  strcat(p4," ");
  strcat(p4,p1);    

  printf("p1 holds: %s\n", p1);
  printf("p2 holds: %s\n", p2);
  printf("p3 holds: %s\n", p3);
  printf("p4 holds: %s\n", p4);  

  free(p1);
  free(p2);
  free(p3);
  free(p4);  
  exit(EXIT_SUCCESS);
}
