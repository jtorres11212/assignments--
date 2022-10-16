#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc,char*argv[]) {
  FILE* txt;
  if (argc>2){//checks for too many args
    for(int i=0;i<sizeof(&argv);i++){
    printf("%s",argv[i]);
    exit(1);
    }
  }
  txt=fopen(argv[1],"r");
  char stack[sizeof(txt)];
  char data;
  int top=-1;
  char c;
  if (txt==NULL){
    printf("\nOpening this is beyond my power");
  }

  int psh(char p);{
    top=top+1;
    data=stack[top];
  }

  int pop(char p);{
    data=stack[top];
    top=top-1;
    return data;
  }
int newlc;
  while((c=fgetc(txt))!=EOF){
    if(c="{"){
      //push to stack
    }
    if(c="}"){
      //pop to stack
    }
    if(c="\n"){
      newlc=newlc+1;
    }
    return newlc;
  }
  fclose(txt);
  return 0;
}
