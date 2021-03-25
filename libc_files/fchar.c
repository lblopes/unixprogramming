#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  /* open file, exit if fail */
  FILE*   file = fopen(argv[1], "r");
  if ( file == NULL ) {
    printf("error: could not open %s\n", argv[1]);
    exit(EXIT_FAILURE); // ends the program
  }

  /* read file, char by char, print to terminal */
  char c;
  int  nchars = 0;
  while ( (c = fgetc(file)) != EOF ) {
    printf("%c", c);
    nchars++;
  }
  printf("-----------------------\n");    
  printf("total chars: %d\n", nchars);
  printf("-----------------------\n");  

  /* close file */
  fclose(file);

  /* return gracefully */  
  exit(EXIT_SUCCESS);
}
