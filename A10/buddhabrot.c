#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>
#include <pthread.h>
#include "read_ppm.h"
#include "write_ppm.h"

int main(int argc, char* argv[]) {
  int size =480;
  float xmin=-2.0;
  float xmax= 0.47;
  float ymin= -1.12;
  float ymax = 1.12;
  int max=1000;
  int numProcesses=4;

  int opt;
  while ((opt = getopt(argc, argv, ":s:l:r:t:b:p:")) != -1) {
    switch (opt) {
      case 's': size = atoi(optarg); break;
      case 'l': xmin = atof(optarg); break;
      case 'r': xmax = atof(optarg); break;
      case 't': ymax = atof(optarg); break;
      case 'b': ymin = atof(optarg); break;
      case '?': printf("usage: %s -s <size> -l <xmin> -r <xmax> "
        "-b <ymin> -t <ymax> -p <numProcesses>\n", argv[0]); break;
    }
  }
  printf("Generatin  mandelbrot with size %dx%d\n", size, size);
  printf("  Num processes = %d\n", numProcesses);
  printf("  X range = [%.4f,%.4f]\n", xmin, xmax);
  printf("  Y range = [%.4f,%.4f]\n", ymin, ymax);
  srand(time(0));
  struct ppm_pixel *pal=malloc(sizeof(struct ppm_pixel)*max);
  for(int i=0;i<max; i++){
    pal[i].red=rand() %255;
    pal[i].green=rand() %255;
    pal[i].blue=rand() %255;
  }
  struct ppm_pixel *pix=malloc(sizeof(struct ppm_pixel)*size*size);
  int *mem,*count=malloc(sizeof(int)*size*size);
  for(int i=0;i<size;i++;){
    for(int i=0;i<size;i++;){
      count[i][j]=0
    }
  }
  int con=0;
  double t;
  struct timeval tstart,tend;
  gettimepfday(&tstart,NULL);
  pthread_t threads[4];
  pthread_mutex_init(&mutex, NULL);
  pthread_barrier_init(&barrier,NULL,4);
  struct thread_data data[4];
  for(int i=0;i<4;i++){
    if(i=0){
      printf("%d. Sub image block: collumns 0,240 to rows 0,240")
      data[i].id=1;
      data[i].pix=pix;
      data[i].strtcol=0;
      data[i].endcol=240;
      data[i].startrow=0;
      data[i].endrow=240;
      data[i].pal=pal;
      data[i].max=max;
      data[i].xmin=xmin;
      data[i].ymin=ymin;
      data[i].xmax=xmax;
      data[i].ymax=ymax;
      data[i].mem=mem;
      data[i].count=count;
      data[i].con=&con;
      pthread_create(&threads[i],NULL,do_formula,(void*)&data[i])
    }
    if(i=1){
      printf("%d. Sub image block: collumns 240,480 to rows 0,240")
      data[i].id=i;
      data[i].pix=pix;
      data[i].strtcol=0;
      data[i].endcol=240;
      data[i]start_row=0;
      data[i]end_row=240;
      data[i].pal=pal;
      data[i].max=max;
      data[i].xmin=xmin;
      data[i].ymin=ymin;
      data[i].xmax=xmax;
      data[i].ymax=ymax;
      data[i].mem=mem;
      data[i].count=count;
      data[i].con=&con;
      pthread_create(&threads[i],NULL,do_formula,(void*)&data[i])
    }
if(i=2){
      printf("%d. Sub image block: collumns 0,240 to rows 0,240")
      data[i].id=i;
      data[i].pix=pix;
      data[i].strtcol=0;
      data[i].endcol=240;
      data[i]start_row=240;
      data[i]end_row=480;
      data[i].pal=pal;
      data[i].max=max;
      data[i].xmin=xmin;
      data[i].ymin=ymin;
      data[i].xmax=xmax;
      data[i].ymax=ymax;
      data[i].mem=mem;
      data[i].count=count;
      data[i].con=&con;
      pthread_create(&threads[i],NULL,do_formula,(void*)&data[i])
    }
if(i=3){
      printf("%d. Sub image block: collumns 0,240 to rows 0,240")
      data[i].id=i;
      data[i].pix=pix;
      data[i].strtcol=240;
      data[i].endcol=480;
      data[i]start_row=240;
      data[i]end_row=480;
      data[i].pal=pal;
      data[i].max=max;
      data[i].xmin=xmin;
      data[i].ymin=ymin;
      data[i].xmax=xmax;
      data[i].ymax=ymax;
      data[i].mem=mem;
      data[i].count=count;
      data[i].con=&con;
      pthread_create(&threads[i],NULL,do_formula,(void*)&data[i])
    }
  }
  for(int i=0;i<4;){
    pthread_join(threads[i],NULL);
  }
  gettimeofday(&tend,NULL);
  t=tend.tv_sec-tstart.tv_sec+(tend.tv_usec-tstart.tv_usec)/1.e6;
  int timestamp=time(0)
  printf("Buddahbrot set %dx%d computed!It took %f seconds\n",size,size,t)
  write_ppm(fp,pix,size,size);
  pthread_mutex_destroy(&mutex);
  pthread_barrier_destroy(&barrier);
  free(pix);
  free(pal);
  free(mem);
  free(count);
  
}
