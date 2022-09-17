#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {
  char wrd[27];
  int scramble;
  printf("GIMME WORD\n");
  scanf("%s", wrd);
  printf("How scuffed do you want the word?!?\n");
  scanf("%d", &scramble);
  int i=0;
  while(i<strlen(wrd)){
    int xmas=wrd[i]+scramble;
    wrd[i]=xmas;
    i = i+1;
  }
  printf("HERE YA GO %s\n", wrd);
  return 0;
}
//
