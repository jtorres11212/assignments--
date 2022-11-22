#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include "rand.h"

#define ROUNDS 3
#define BUFFER 5
#define LOOP 10

struct chunk {
  int size;
  int used;
  struct chunk *next;
};

void memstats(struct chunk* freelist, void* buffer[], int len) {
  int ta=0;
  int tb=0;
  int usa=0;
  int usb=0;
  int fa=0;
  int fb=0;
  int un=0;
  struct chunk *f=freelist;
  while(f!=NULL){
    fb++;
    fb=fb+f->size;
    f=f->next;
  }
  for(int i=0;i<len;i++){
    if(buffer[i]!=NULL){
      usa++;
      struct chunk *cnk=(struct chunk*)((struct chunk*)buffer[i]-1);
    }
  }
  tb=usb+fb;
  float unut=(float)un/tb;
  ta=fa+usa;
  printf("Total b̷̧̧̧̼̙̬̤̝̻̐̋̀̓̍̓͑̓̿̑͠ḽ̶̃̍̒̋o̶̡̨͈̰̬̞͎̥̲̓̍͐̉̈͜͜ͅc̷̛͖̹̘̈́̃̏̏͂͂͊͊̍́́̌̚͝k̵̖̲̪̤͑͛̆̿͂s̷͎̗͈̺̗̰̹̞͚͓̩͕̗̠̒̇͑͆̒͆:%d \nFree b̷̧̧̧̼̙̬̤̝̻̐̋̀̓̍̓͑̓̿̑͠ḽ̶̃̍̒̋o̶̡̨͈̰̬̞͎̥̲̓̍͐̉̈͜͜ͅc̷̛͖̹̘̈́̃̏̏͂͂͊͊̍́́̌̚͝k̵̖̲̪̤͑͛̆̿͂s̷͎̗͈̺̗̰̹̞͚͓̩͕̗̠̒̇͑͆̒͆:%d\nUsed b̷̧̧̧̼̙̬̤̝̻̐̋̀̓̍̓͑̓̿̑͠ḽ̶̃̍̒̋o̶̡̨͈̰̬̞͎̥̲̓̍͐̉̈͜͜ͅc̷̛͖̹̘̈́̃̏̏͂͂͊͊̍́́̌̚͝k̵̖̲̪̤͑͛̆̿͂s̷͎̗͈̺̗̰̹̞͚͓̩͕̗̠̒̇͑͆̒͆:%d \nTotal memory allocated:%d \nFreed memory:%dUsed memory:%d \nUnderutilized Memory:%.2f \n",ta,fa,usa,tb,fb,usb,unut);
}

int main ( int argc, char* argv[]) {

  printf("Starting test..\n");

  srand(100);

  double timer;
  struct timeval tstart, tend;

  gettimeofday(&tstart, NULL);

  void *buffer[BUFFER];
  for (int i = 0; i < BUFFER; i++) {
    buffer[i] = NULL;
  }

  void *init = sbrk(0);
  void *current;
  printf("The initial top of the heap is %p.\n", init);
  for (int j = 0 ; j < ROUNDS; j++) {
    printf("---------------\n%d\n" , j);

    for (int i= 0 ; i < LOOP ; i++) {
      int index = rand() % BUFFER;
      if (buffer[index] != NULL) {
        free(buffer[index]);
        buffer[index] = NULL;
        printf("Freeing index %d\n", index);
      } 
      else {
        size_t size = (size_t) randExp(8, 4000); 
        int *memory = NULL;
        memory = malloc(size);

        if (memory == NULL) {
          fprintf(stderr, "malloc failed\n");
          return(1);
        } 
        *memory = 123;
        buffer[index] = memory;
        printf("Allocating %d bytes at index %d\n", (int) size, index);
      }
    }
    extern struct chunk* flist;
    current = sbrk(0);
    int allocated = current - init;
    init = current;

    printf("The new top of the heap is %p.\n", current);
    printf("Increased by %d (0x%x) bytes\n", allocated, allocated);
    memstats(flist, buffer, BUFFER);
  }

  for (int i = 0; i < BUFFER; i++) {
    free(buffer[i]); 
  }
  gettimeofday(&tend, NULL);
  timer = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;
  printf("Time is %g\n", timer);

  return 0 ;
}
