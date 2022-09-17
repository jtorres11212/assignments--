#include <stdio.h>
#include <string.h>
#include <time.h>
#include "words.h" // header that defined chooseWord()

int main() {
  srand(time(0));
  const char* wrd = chooseWord();
  printf("cheat: %s\n", wrd);
  char try[5];
  int counter=0;
  while(counter <6){
    printf("GIMME WORD\n");
    scanf("%s", try);
    if(strcmp(try,wrd)==0){
      printf("DRATS YOU WON >:(\n");
      counter = 6;

    }
    else if(try!= wrd){
      for(int i=0; i<=5; i++){
        if(try[i]==wrd[i]){
          printf("%c is in the right spot\n",try[i]);}
        else if(try[i]!= wrd[0]&& try[i]==wrd[1]||wrd[2]||wrd[3]||wrd[4]){
          printf("%c is in the wrong spot silly!!\n",try[i]);}
        else if(try[i]!=wrd[0]&& wrd[1] && wrd[2] && wrd[3] && wrd[4]){
          printf("%c isnt in the word!!\n", try[i]);
        }
        }
      }
    
    counter=counter+1;
    }
   return 0; 
  }

