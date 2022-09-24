#include <stdio.h>


int main(){
  int LAST[4][4];
  int NUMBR;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      scanf("%d\n",&NUMBR);
      LAST[i][j]=NUMBR;
    }
  }
  int MOVE[16];
  int OTHERNUM=0;
     for(int i=0;i<=3;i++){
      for(int j=3;j<=1;j--){

        if (LAST[i][0]==LAST[i][3] && LAST[i][1]==0&&LAST[i][2]==0){
          MOVE[OTHERNUM]=LAST[i][0]+LAST[i][3];
          OTHERNUM=OTHERNUM+1;
        }
        else if (LAST[i][0]==LAST[i][2] && LAST[i][1]== 0){
          MOVE[OTHERNUM]=LAST[i][0]+LAST[i][2];
          OTHERNUM=OTHERNUM+1;
        }
        else if (LAST[i][1]==LAST[i][3] && LAST[i][2]==0){
          MOVE[OTHERNUM]=LAST[i][1]+LAST[i][3];
          OTHERNUM=OTHERNUM+1;
        }        
        if (LAST[i][j]==LAST[i][j-1]){
          MOVE[OTHERNUM]=LAST[i][j]+LAST[i][j-1];
          OTHERNUM=OTHERNUM+1;
        }
      }
    }
    for(int i=0;i<=2;i++){
      for(int j=0;j<=3;j++){
        if (LAST[i][j]==LAST[i+1][j]){
          MOVE[OTHERNUM]=LAST[i][j]+LAST[i+1][j];
          OTHERNUM=OTHERNUM+1;
        }
        else if (LAST[0][j]==LAST[3][j] && LAST[1][j]==0 && LAST[2][j]==0){
          MOVE[OTHERNUM]=LAST[0][j]+LAST[3][j];
          OTHERNUM=OTHERNUM+1;
        }
        else if (LAST[0][j]==LAST[2][j] && LAST[1][j]==0){
          MOVE[OTHERNUM]=LAST[0][j]+LAST[2][j];
          OTHERNUM=OTHERNUM+1;
        }
      }
    }
  int BIG=0;
  for (int i=0;i<OTHERNUM;i++){
    if (MOVE[i]>BIG){
      BIG=MOVE[i];
      printf("%d/n",MOVE[i]);
    }
  }
 printf("BIGGGEST NUMBR IS %d\n", BIG);
  return 0;
}