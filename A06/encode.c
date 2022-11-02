#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_ppm.h"
#include "write_ppm.h"
int* bin(char* arr){
  int* binary = (int*)malloc(8*sizeof(arr));
  int num;
  for (int i = 0; i < 8*(sizeof(arr)); i+=8){
    num = arr[i/8];
    binary[i+7] = num%2;
    num = num/2;
    binary[i+6] = num%2;
    num = num/2;
    binary[i+5] = num%2;
    num = num/2;
    binary[i+4] = num%2;
    num = num/2;
    binary[i+3] = num%2;
    num = num/2;
    binary[i+2] = num%2;
    num = num/2;
    binary[i+1] = num%2;
    num = num/2;
    binary[i] = num%2;
  }
return binary;
}


int main(int argc, char** argv) {
  if (argc != 2) {
    printf("usage: encode <file.ppm>\n");
    return 0;
  }

  int w, h;
  int idx = 0;
  char m[100];
   
  struct ppm_pixel** pixels = read_ppm(argv[1],&w,&h);
  printf("m̴̛̜͎̭̰̮̾̐͊͐́͘͘̚͝͠m̶̞̟͓̭̂̊̃̓̾̈́̕͠m̸̨͇͇̺͍̳͈̜̱̣̘̈̉͗̒͆̀̈̿̌̕M̸̡̱̩̞̲̈́͆̃̈̇͂̓͒̄̚͝MESSAGE: ");
  scanf("%s", m);
  int *num = bin(m);
  int x = 0;
   for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      pixels[i][j].red = (pixels[i][j].red & 0b11111110) | num[x] ;
      x = x +1;
      pixels[i][j].green = (pixels[i][j].green & 0b11111110) | num[x];
      x = x +1;
      pixels[i][j].blue = (pixels[i][j].blue & 0b11111110) | num[x];
      x = x +1;
    }
  }
  
  char* nf = malloc(strlen(argv[1])+11);
  strcpy(nf,argv[1]);
  nf[strlen(nf)-4] = '\0';
  strcat(nf,"-new.ppm");

  write_ppm(nf, pixels, w, h);

  free(pixels);
  free(nf);
  return 0;
}
