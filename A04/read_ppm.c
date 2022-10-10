#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_ppm.h"

// Choose *one* to implement

struct ppm_pixel** read_ppm_2d(const char* file, int* w, int* h) {
  unsigned char arr[1000];//remember to change
  FILE *fp;
  char p6[2];
  fp=fopen(file,"r");
  fgets(p6,2,file);
  printf("gimme the width and then the height\n");
  scanf("%d\nok now the height\n%d",&w,&h);
  if(p6!='P6'){
    return NULL;
    printf("You expect me to take a file like THAT?!?!");
    exit(0);
  }
  else{
    fscanf(fp);
  }
  fclose(fp);
  return NULL;
}
