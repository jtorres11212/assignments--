#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"
#include <math.h>

int dec(int arr[]){
int value = 0;
for (int i = 7; i >= 0; i--){
    value = value + arr[i]*pow(2.0,(double)(7-i));
  }
printf("%c",(char)(value));
return value;
}
int main(int argc, char** argv) {
  if (argc != 2) {
    printf("usage: decode <file.ppm>\n");
    return 0;
  }
  int w, h;
  int idx = 0;
  int b[1000];
  struct ppm_pixel* pixels = read_ppm(argv[1],&w,&h);
  for(int i = 0; i < h; i++){
    for(int x = 0; x < w; x++){
      b[idx] = (pixels[i*(w)+x].red & 0b1);
      idx = idx +1;
      b[idx] = (pixels[i*(w)+x].green & 0b1);
      idx = idx +1;
      b[idx] = (pixels[i*(w)+x].blue & 0b1);
      idx = idx +1;
    }
  }
  
  for(int x = 0; x < idx; x++){
      printf("%d",b[x]);
  }
  int dc[8];
  printf("\n");
  for (int x =0;x<idx;x+= 8){
    dc[0]=b[x];
    dc[1]=b[x+1];
    dc[2]=b[x+2];
    dc[3]=b[x+3];
    dc[4]=b[x+4];
    dc[5]=b[x+5];
    dc[6]=b[x+6];
    dc[7]=b[x+7];
    dec(dc);
  }
  free(pixels);
  return 0;
}
