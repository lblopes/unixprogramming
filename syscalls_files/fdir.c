#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main (int argc, char** argv) {

  /* check if argument is given */
  if (argc != 2) {
    fprintf (stderr, "usage: %s dirname\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  /* try to open directory */
  DIR* q = opendir (argv[1]);
  if (q == NULL) {
    fprintf (stderr, "%s: Cannot open directory '%s'\n", argv[0], argv[1]);
    exit(EXIT_FAILURE);
  }

  /* list contents of directory */
  printf ("%s/\n", argv[1]);
  struct dirent* p = readdir(q);
  while (p != NULL) {
    printf ("\t%s\n", p->d_name);
    p = readdir(q);    
  }

  /* close directory */
  closedir (q);

  /* return gracefully */
  exit(EXIT_SUCCESS);
}
