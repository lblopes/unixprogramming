#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  ssize_t read;
  size_t  size = 0;  
  char*   line = NULL;

  /* open file, exit if fail */
  FILE*   file = fopen(argv[1], "r");
  if ( file == NULL ) {
    printf("error: could not open %s\n", argv[1]);
    exit(EXIT_FAILURE); // ends the program
  }

  /* read file, line by line */
  int lineno = 1;
  while ((read = getline(&line, &size, file)) != -1) {
    printf("[%5d]: %s", lineno, line);
    lineno++;
  }

  /* close file */
  fclose(file);

  /* return gracefully */
  exit(EXIT_SUCCESS);
}
