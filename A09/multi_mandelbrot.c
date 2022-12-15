#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include "read_ppm.h"
#include "write_ppm.h"

void compmbrot(struct ppm_pixel *pixels, int start_col , int end_col, int start_row, int end_row, struct ppm_pixel *palette, int size, int maxIterations, float xmin, float ymin, float xmax, float ymax){
for(int i= start_row; i<end_row; i++){
  for(int j=start_col; j<end_col; j++){
    float xfrac = ((float) (j))/size;
    float yfrac = ((float) (i))/size;
    float x0 = xmin + xfrac * (xmax - xmin);
    float y0 = ymin + yfrac * (ymax - ymin);
    float x = 0.0;
    float y = 0.0;
    int iter = 0;
    while (iter < maxIterations && x*x + y*y < 2*2){
      float xtmp = x*x - y*y + x0;
      y = 2*x*y + y0;
      x = xtmp;
      iter++;
    }
    if(iter < maxIterations){ //escaped
      pixels[i][j] = palette[iter];
    }
    else{
      pixels[i][j].red = 0;
      pixels[i][j].green = 0;
      pixels[i][j].blue = 0;
    }
  }
}
}
int main(int argc, char* argv[]) {
  int size = 480;
  float xmin = -2.0;
  float xmax = 0.47;
  float ymin = -1.12;
  float ymax = 1.12;
  int maxIterations = 1000;
  int #process = 4;
  int opt;
  while ((opt = getopt(argc, argv, ":s:l:r:t:b:p:")) != -1) {
    switch (opt) {
      case 's': size = atoi(optarg); break;
      case 'l': xmin = atof(optarg); break;
      case 'r': xmax = atof(optarg); break;
      case 't': ymax = atof(optarg); break;
      case 'b': ymin = atof(optarg); break;
      case '?': printf("usage: %s -s <size> -l <xmin> -r <xmax> "
        "-b <ymin> -t <ymax> -p <#process>\n", argv[0]); break;
    }
  }
  printf("Generating mandelbrot w/ size %dx%d\n", size, size);
  printf("# processes = %d\n", #process);
  printf("x range = [%.4f,%.4f]\n", xmin, xmax);
  printf("y range = [%.4f,%.4f]\n", ymin, ymax);

int SHMIDL;
SHMIDL= shmget(IPC_PRIVATE, sizeof(struct ppm_pixel) * maxIterations, 0644 | IPC_CREAT);
if (SHMIDL == -1) {
  perror("Error: cannot initialize shared memory\n");
  exit(1);
}
struct ppm_pixel *palette = shmat(SHMIDL, NULL, 0);
for(int i=0; i<maxIterations; i++){
  palette[i].red = rand() % 255;
  palette[i].green = rand() %255;
  palette[i].blue = rand()% 255;
}
int shmid;
shmid= shmget(IPC_PRIVATE, sizeof(struct ppm_pixel) * size * size, 0644 | IPC_CREAT);
if (shmid == -1) {
  perror("Error: cannot initialize shared memory\n");
  exit(1);
}
struct ppm_pixel *pixels = shmat(shmid, NULL, 0);
if(pixels ==(void*)-1){
  perror("Error: cannot access shared memory\n");
    exit(1);
}
double timer;
struct timeval tstart, tend; 
gettimeofday(&tstart, NULL);long id1 = 1, id2 = 2; 
long* retval1 = NULL, retval2 = NULL; 
pthread_t thread1, thread2, thread3, thread4; 
pthread_create(&thread1, NULL, pixels, &id1); 
pthread_create(&thread2, NULL, pixels, &id2);
pthread_create(&thread3, NULL, pixels, &id3);
pthread_create(&thread4, NULL, pixels, &id4);  
pthread_join(thread1, NULL); 
pthread_join(thread2, NULL);
pthread_join(thread3, NULL);
pthread_join(thread4, NULL);
gettimeofday(&tend, NULL);

timer = tend.tv_sec - tstart.tv_sec + (tend.tv_usec-tstart.tv_usec)/1.e6;
int timestamp = time(0);
printf("Computed mandelbrot set (%dx%d) in %f seconds\n", size, size,timer);
  char fp[100];
  sprintf(fp, "multi-mandelbrot-%d-%d.ppm", size, timestamp);
  printf("Writing file: %s\n", fp);
  write_ppm(fp, pixels, size, size);
  if (shmdt(pixels) == -1) {
    perror("Error: cannot detatch from shared memory\n");
    exit(1);
  }
  if (shmctl(shmid, IPC_RMID, 0) == -1) {
    perror("Error: cannot remove shared memory\n");
    exit(1);
  } 

  if (shmdt(palette) == -1) {
    perror("Error: cannot detatch from shared memory\n");
    exit(1);
  }

  if (shmctl(SHMIDL, IPC_RMID, 0) == -1) {
    perror("Error: cannot remove shared memory\n");
    exit(1);
  } 
}  