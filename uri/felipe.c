#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){

int A, B, i, j, cont=0, conTT=0;
int matriz[105][505];

  while(1){
    scanf("%d %d", &A, &B);
    if(A==0 && B==0)
      break;

    for (i = 0; i < B; i++) {
      for (j = 0; j < A; j++) {
        scanf("%d", &matriz[i][j]);
      }
    }
    conTT=0;
    for (i = 0; i < A ; i++) {
        cont=0;
        for (j = 0; j < B; j++) {
          cont=cont+matriz[i][j];

        }
        if(cont / B ==1)
          conTT = 1;

    }
    if (conTT ==1)
      printf("yes\n");
    else
      printf("no\n");
 }
  return 0;
}
