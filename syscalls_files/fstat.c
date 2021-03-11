#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {

  /* check if argument is given */  
  if (argc != 2) {
    fprintf(stderr, "usage: %s file\n", getprogname());
    return EXIT_FAILURE;
  }

  /* get file size & block info */
  struct stat sb;
  if (stat(argv[1], &sb) == -1) {
    fprintf(stderr, "fsize: Can't stat %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  /* print file size & block info */
  printf("%s size: %d bytes, disk_blocks: %d\n",
	 argv[1], (int)sb.st_size, (int)sb.st_blocks);

  /* return cleanly */
  return EXIT_SUCCESS;
}
