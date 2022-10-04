#include <stdio.h>
#include <stdlib.h>

struct dres{
    char name[64];
    float rating;
    int open; 
    int close;
};

int main() {
  int nres;
  printf("UwU\nhow many restuaraunts?\n");
  scanf("%d%*c",&nres);
  struct dres *p;
  p = malloc(sizeof(struct dres)*nres);
  for(int i=1; i<=nres; i++){
    printf("Whats the name of the restaurant?\n");
    scanf(" %[^\n]%*c",p[i].name);
    printf("How well liked is this restaurant?(rating)\n");
    scanf("%g%*c",&p[i].rating);
    printf("When does the restaurant open?\n");
    scanf("%d%*c",&p[i].open);

    printf("When does the restaurant close?\n");
    scanf("%d%*c",&p[i].close);
  }
  for(int i=0; i<=nres; i++){
    printf("%d)  name:%s  open:%d close:%d  rating:%g\n",i,
    p[i].name, p[i].open, p[i].close, p[i].rating); }
  free(p);
  return 0;
}
