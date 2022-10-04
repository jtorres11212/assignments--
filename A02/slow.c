#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int len;
  char wrds[32];
  printf("Pause Length:");
  scanf("%d",&len);
  printf("GIMME WORDS\n");
  scanf("%s",wrds);
  char *lot=NULL;
  lot= malloc(sizeof(char)*strlen(wrds)*(len+1)+1);
  int WOO=0;
  int BOO=0;
  while(BOO<strlen(wrds)){
  lot[WOO]=wrds[BOO];
  BOO=BOO+1;
  for(int i=1; i<=len; i++){
    lot[WOO+i]='.';
  }
  WOO=WOO+1+len;
  }
  lot[WOO]='\0';
  printf("%s\n",lot);
  free(lot);
  return 0;\
}
