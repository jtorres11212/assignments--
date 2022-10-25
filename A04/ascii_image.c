#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("usage: ascii_image <file.ppm>\n");
    return 0;
  }int w;
  int h;
  struct ppm_pixel** image = read_ppm_2d(argv[1], &w,&h);
  int num;
  char ch;
  for(int i = 0; i < h; i++){
    for(int o = 0; o < w; o++){
    num = ((image[i][o].red) + (image[i][o].green) + (image[i][o].blue))/3;
    if(num >= 0 && num <= 25){
      ch = '@';
      printf("%c ",ch);
    }     
    else if(num >= 26 && num <= 50){
      ch = '#';
      printf("%c ",ch);
    }
    else if(num >= 51 && num <= 75){
      ch = '%';
      printf("%c ",ch);
    }
    else if(num >= 76 && num <= 10){
      ch = '*';
      printf("%c ",ch);
    }
    else if(num >= 101 && num <= 125){
      ch = 'o';
      printf("%c ",ch);
    }

    else if(num >= 126 && num <= 150){
      ch = ';';
      printf("%c ",ch);
    }

    else if(num >= 151 && num <= 175){
      ch = ':';
      printf("%c ",ch);
    }

    else if(num >= 176 && num <= 200){
      ch = ',';
      printf("%c ",ch);
    }

    else if(num >= 201 && num <= 225){
      ch = '.';
      printf("%c ",ch);
    }

    else if(num >= 226 && num <= 255){
      ch = ' ';
      printf("%c ",ch);
    }   
  }
  printf("\n");
  }
  
  return 0;
}
