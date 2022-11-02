#include <stdio.h>

int main() {
  unsigned long img;
  unsigned long track;
  scanf(" %lx", &img);
  printf("Image (unsigned long): %lx\n", img);
  for(int i=63;i>0;i--){
    track=(img &(0x1ul <<i))>>i;
    if(track>0){
    printf("@");
    }
  
    else{
      printf(" ");
  }
    if((i%8)==0){
      printf("\n");
  }}
  return 0;
}
