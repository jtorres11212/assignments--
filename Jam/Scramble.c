#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  unsigned char wrd[200];
  unsigned char fourth;
  unsigned char third;
  unsigned char mask = 0xf3;
  printf("GIMME WORD\n");
  scanf("%[^\n]%*c", wrd);
  for(int i=0;i<strlen(wrd);i++){
    fourth = (wrd[i] & (0x1u << 3)) >>1;
    third = (wrd[i] & (0x1u <<2) )<< 1;
    wrd[i] = (mask & wrd[i]);
    printf("mask&word: %x\n",   wrd[i]);
    wrd[i] = (wrd[i] | fourth | third );
    printf("&4th: %x\n",  wrd[i]);
  }
  printf("HERE YA GO %s\n", wrd);
  return 0;
}