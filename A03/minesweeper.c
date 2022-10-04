#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  srand(time(0));
  int row;
  row = atoi(argv[1]);
  int col;
  col = atoi(argv[2]);
  float p;
  p = atof(argv[3]);
  int *swp = malloc(row*col*sizeof(int));
  printf("Good luck!\n");
  srand(time(0));
  for(int i = 0; i<row; i++){
    for(int j = 0; j<col; j++){   
      float mine = (float)rand()/RAND_MAX;
      if (mine <=p){    
        swp[i*col + j] = 'X';   
      }
      else {
        swp[i*col + j] = '.';      
      }
      printf("%c",swp[i*col + j]);
    }   
    printf("\n");     
  }

  int *adj = malloc(row*col*sizeof(int));
  for(int i = 0; i<row; i++){
    for(int j = 0; j<col; j++){
        adj[i*col + j] = '0'; 
    } 
  }

char add = '1';
  for(int i = 0; i<row-1; i++){
    for(int j = 0; j<col; j++){
      if (swp[(i*col +1) + j] == 'X'){    
        adj[i*col + j] = (int)(adj[i*col + j]-'0') + (int)(add-'0'); 
        adj[i*col + j] = adj[i*col + j] +'0';
      }  
    }
  }

  for(int i = 1; i<row; i++){
    for(int j = 0; j<col; j++){
      if (swp[(i*col -1) + j] == 'X'){    
        adj[i*col + j] = (int)(adj[i*col + j]-'0') + (int)(add-'0'); 
        adj[i*col + j] = adj[i*col + j] +'0';
      }  
    }
  }

  for(int i = 0; i<row; i++){
    for(int j = 1; j<col; j++){     
      if (swp[i*col + (j-1)] == 'X'){    
        adj[i*col + j] = (int)(adj[i*col + j]-'0') + (int)(add-'0');
        adj[i*col + j] = adj[i*col + j] +'0';
      }  
    }
  }

  for(int i = 0; i<row; i++){
    for(int j = 0; j<col-1; j++){
      if (swp[i*col + (j+1)] == 'X'){    
        adj[i*col + j] = (int)(adj[i*col + j]-'0') + (int)(add-'0');
        adj[i*col + j] = adj[i*col + j] +'0';
      }  
    }
  }

  for(int i = 1; i<row; i++){
    for(int j = 1; j<col; j++){
      if (swp[(i*col -1)+ (j-1)] == 'X'){    
        adj[i*col + j] = (int)(adj[i*col + j]-'0') + (int)(add-'0');
        adj[i*col + j] = adj[i*col + j] +'0';
      }  
    }
  }

  for(int i = 0; i<row-1; i++){
    for(int j = 1; j<col; j++){
      if (swp[(i*col +1) + (j-1)] == 'X'){    
        adj[i*col + j] = (int)(adj[i*col + j]-'0') + (int)(add-'0');
        adj[i*col + j] = adj[i*col + j] +'0';
      }  
    }
  }
  for(int i = 1; i<row; i++){
    for(int j = 0; j<col-1; j++){
      if (swp[(i*col -1) + (j+1)] == 'X'){    
        adj[i*col + j] = (int)(adj[i*col + j]-'0') + (int)(add-'0');
        adj[i*col + j] = adj[i*col + j] +'0';
      }  
    }
  }

  for(int i = 0; i<row-1; i++){
    for(int j = 0; j<col-1; j++){
      if (swp[(i*col +1) + (j+1)] == 'X'){    
        adj[i*col + j] = (int)(adj[i*col + j]-'0') + (int)(add-'0');
        adj[i*col + j] = adj[i*col + j] +'0';
      }  
    }
  }

 for(int i = 0; i<row; i++){
    for(int j = 0; j<col; j++){
      if (swp[i*col + j] == 'X'){    
        adj[i*col + j] = 'X'; 
      }  
   }
 }
  printf("\n-adjacents-\n");
  for(int i = 0; i<row; i++){
    for(int j = 0; j<col; j++){   
      printf("%c",adj[i*col + j]);
    }   
    printf("\n");     
  }
  free(swp);
  free(adj);

}
