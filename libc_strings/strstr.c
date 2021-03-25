#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * simple string manipulation: strdup, strstr
 */

int main(int argc, char *argv[]) {
  char* needle   = strdup(argv[1]);
  char* haystack = strdup(argv[2]);

  char* ptr = haystack;
  while( (ptr = strstr(ptr, needle)) != NULL ) {
    int pos = strlen(haystack) - strlen(ptr);
    printf("[%s @ %d]\n", needle, pos);
    ptr++;
  }
  free(needle);
  free(haystack);  
  exit(EXIT_SUCCESS);
}
