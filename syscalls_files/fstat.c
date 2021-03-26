#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char* argv[]) {

  /* check if argument is given */  
  if (argc != 2) {
    fprintf(stderr, "usage: %s file\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  /* get file size & block info */
  struct stat info;
  if (stat(argv[1], &info) == -1) {
    fprintf(stderr, "fsize: Can't stat %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  /* print file name, owner, size & block info */
  printf("file name              : %s\n", argv[1]);
  printf("owner uid              : %d\n", (int)info.st_uid);  
  printf("size                   : %d bytes\n", (int)info.st_size);
  printf("disk blocks            : %d blocks\n", (int)info.st_blocks);

  /* last access, modification and status change times */
  printf("last access            : %s", ctime(&(info.st_atim.tv_sec)));
  printf("last data modification : %s", ctime(&(info.st_mtim.tv_sec)));
  printf("last file status change: %s", ctime(&(info.st_ctim.tv_sec)));
 
  /* return gracefully */
  exit(EXIT_SUCCESS);
}
