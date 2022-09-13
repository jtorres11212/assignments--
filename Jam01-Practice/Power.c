#include <stdio.h>

int power(int base, int exp){
    if (exp ==0){
    return 1;
    }
    else if (exp == 1){
        return base;
    }
    else if(exp> 1){
        int a= base;
        int i;
        for (i=1; i<exp; i++){
            
            a= a*base;
        }
        return a;
        }

    }
    
int main(){
    int result;
    result=power(3,4);
    printf("%d\n",result);

    return 0;
}