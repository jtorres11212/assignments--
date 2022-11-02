#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_ppm.h"
#include "write_ppm.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("usage: glitch <file.ppm>\n");
    return 0;
  }
  int w;
  int h;
  struct ppm_pixel* pixels=read_ppm(argv[1],&w,&h);
  for(int i=0;i<h;i++){
    for (int x=0;x<w;x++){
      pixels[i*(w)+x].red=(pixels[i*(w)+x].red)<<(rand()%2);
      pixels[i*(w)+x].green=(pixels[i*(w)+x].green)<<(rand()%2);
      pixels[i*(w)+x].blue=(pixels[i*(w)+x].blue)<<(rand()%2);
    }
  }
  char* file=malloc(strlen(argv[1]+10));
  strcpy(file,argv[1]);
  file[strlen(file)-4]="\0";
  strcat(file,"-glitch.ppm");
  write_ppm(file,pixels,w,h);
  free(pixels);
  free(file);
  return 0;
}


