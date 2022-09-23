#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int len;
  char words[32];
  printf("JSNFJN Pause Length:");
  scanf("%d",&len);
  printf("GIMME WORDS\n");
  scanf("%s",words);
  char *lot=NULL;
  lot= malloc(sizeof(char)*32);
  int woo=0;
  int boo=0;
  while(boo<strlen(words)){
  lot[woo]=words[boo];
  boo=boo+1;
  for(int i=1; i<=len; i++){
    lot[woo+i]='.';
  }
  woo=woo+1+len;
  }
  printf("%s\n",lot);
  free(lot);
  return 0;
}
