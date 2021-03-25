#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {

  /* open file, exit if fail */
  FILE*   file = fopen(argv[1], "r");
  if ( file == NULL ) {
    printf("error: could not open %s\n", argv[1]);
    exit(EXIT_FAILURE); // ends the program
  }

  /* read file, print it to terminal */
  int  nchars;
  char buffer[BUFFER_SIZE];
  while ( (nchars = fread(buffer, sizeof(char), BUFFER_SIZE, file)) != 0 ) 
    fwrite(buffer, sizeof(char), nchars, stdout);

  /* close file */
  fclose(file);

  /* return gracefully */  
  exit(EXIT_SUCCESS);
}
