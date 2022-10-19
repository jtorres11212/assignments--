#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_ppm.h"

// Choose *one* to implement

struct ppm_pixel** read_ppm_2d(const char* file, int* w, int* h) {
  char arr[1000];//remember to change
  FILE *fp;
  fp=fopen(file,"rb");
  fgets(arr,1000,fp);
  if(arr[0]!='P'||arr[1]!='6'){
    printf("You expect me to take a file like THAT?!?!");
    return NULL;
  }
  //can use fread to copy data row by row into array
  //print out thin
  fgets(arr,1000, fp);
  printf("\n%s",arr);
  fgets(arr,1000, fp);
  printf("\n%s",arr);
  sscanf(arr,"%d %d",w,h);
  printf("%d %d",*w,*h);
  fgets(arr,1000, fp);
  printf("\n%s",arr);
  struct ppm_pixel** image =malloc(sizeof(struct ppm_pixel*)*(*h));
  for(int i=0;i<*h;i++){
    struct ppm_pixel*array=malloc(sizeof(struct ppm_pixel)*(*w));
    image[i]=array;
    fread(array,sizeof(struct ppm_pixel),*w,fp);
  }
  

  fclose(fp);
  return image;
}
