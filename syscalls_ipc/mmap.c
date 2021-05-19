#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>


int main(int argc, char *argv[]) {

  /* ------ create and read matrix ------ */
  char* infile = argv[1]; 
  int   nprocs = atoi(argv[2]);
  int   threshold = atoi(argv[3]);
  
  FILE *fp;
  if((fp = fopen(infile,"r")) == NULL){
    perror("cannot open file");
    exit(EXIT_FAILURE);
  }
  size_t str_size = 0;
  char*  str = NULL;
  getline(&str, &str_size, fp);
  int n = atoi(str);
  int matrix[n][n];
  int i = 0, j = 0;
  while ( getline(&str, &str_size, fp) > 0 ) {
    char* token = strtok(str," ");
    while( token != NULL ) {
      matrix[i][j]=atoi(token);
      token=strtok(NULL," ");
      j++;
    }
    i++;
    j=0;
  }
  fclose(fp);

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  /* ------ setup shared memory ------ */

  int *partials = mmap(NULL, nprocs*sizeof(int), PROT_READ|PROT_WRITE,
		       MAP_SHARED|MAP_ANONYMOUS, 0, 0);
  
  if(partials == MAP_FAILED){
    perror("mmap");
    exit(EXIT_FAILURE);
  }

  for(i = 0; i < nprocs; i++)
    partials[i] = 0;

  /* ------ start nprocs and do work ------ */
    
  for(i = 0; i < nprocs; i++) {
    pid_t pid;
    if ((pid = fork()) < 0) {
      perror("fork");
      exit(EXIT_FAILURE);
    }
    if(pid == 0) {
      for(int j = 0; j < n; j++)
        if(j % nprocs == i) 
          for(int k = 0; k < n; k++) 
            if(matrix[j][k] > threshold)
	      partials[i]++;
      exit(EXIT_SUCCESS);
    }
  }

  /* ------ wait for nprocs to finish ------- */
  for(i = 0; i < nprocs; i++)  {   
    if ( waitpid(-1, NULL, 0) < 0) {
      perror("waitpid");
      exit(EXIT_FAILURE);
    }
  }    
  
  /* ler resultados enviados pelos processos filhos */
  int total = 0;
  for(i = 0; i < nprocs; i++)       
    total += partials[i];
  printf("%d\n",total);

  /* ------ release shared memory ------ */
  if (munmap(partials, sizeof(partials)) < 0) {
    perror("munmap");
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}
