#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Resturaunts {
    char name[64];
    int open;
    int close;
    float rating;
};

int main() {
  struct Resturaunts Res1, Res2, Res3;
  strcpy(Res1.name, "Sweet Moment");  
      Res1.open = 10;                  
      Res1.close = 20;                  
      Res1.rating = 4.5;

  strcpy(Res2.name, "Cats&Wine");  
      Res2.open = 18;                  
      Res2.close = 2;                  
      Res2.rating = 5;            

  strcpy(Res3.name, "McDonalds");  
      Res3.open = 12;                  
      Res3.close = 12;                  
      Res3.rating = 4.3;
  printf(" 1) name:%s open:%d close:%d, rating:%g\n 2) name:%s open:%d close:%d, rating:%g\n 3) name:%s open:%d close:%d, rating:%g\n", 
  Res1.name, Res1.open, Res1.close, Res1.rating, Res1.name, Res2.open, Res2.close, Res2.rating, Res3.name, Res3.open, Res3.close, Res3.rating); 
  printf("whats the time (in military time)?");
  int time;
  scanf("%d",&time);
    if (time >=Res1.open && time <Res1.close){
    printf("%s is open!\n",Res1.name);}  
    if (time >=Res2.open && time <Res2.close){
    printf("%s is open!\n",Res2.name);}
    if (time >=Res3.open && time <Res3.close){
    printf("%s is open!\n",Res3.name);}
    if (time >Res1.open){
    printf("%s opens at %d!\n",Res1.name,Res1.open);}
    if (time >Res2.open){
    printf("%s opens at %d!\n",Res2.name,Res1.open);}
    if (time >Res3.open){
    printf("%s opens at %d!\n",Res3.name,Res3.open);}
    if (time <Res1.open){
    printf("%s closed at %d:(\n",Res1.name,Res1.close);}
    if (time <Res2.open){
    printf("%s closed at %d :(\n",Res2.name,Res2.close);}
    if (time <Res3.open){
    printf("%s Never closes!:(\n",Res3.name);}
  return 0;
}
