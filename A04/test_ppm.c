#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"

int main() {
  int w;
  int h;
  struct ppm_pixel** image;
  image=read_ppm_2d("File name",&w,&h);
  for(int i=0;i<h;i++){
    free(image[i]);
  }
  for(int i=0;i<h;i++){
    for(int o=0;o<w;o++){
      printf("( %hhu %hhu %hhu )", image[i][o].red, image[i][o].green, image[i][o].blue);
   }
   printf("\n");
  }
    
  free(image);
  return 0;
}

