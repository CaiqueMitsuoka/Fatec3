#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    int alunos, casos, eventos[101][501],a,j,presenca,controle;
    scanf("%d %d",&alunos,&casos);
    while(alunos && casos){
        for(a=1;a<=casos;a++){
            for(j=1;j<=alunos;j++){
                scanf("%d",&eventos[j][a]);
            }
        }
        controle = 0;
        for(a=1;a<=alunos;a++){
            presenca=0;
            for(j=1;j<=casos;j++){
                if(eventos[a][j]){
                    presenca++;
                }
            }
            if(presenca == casos){
                printf("yes\n");
                controle = 1;
                break;
            }
        }
        if(!controle){
            printf("no\n");
        }

        scanf("%d %d",&alunos,&casos);
        // if(alunos){
        //     printf("\n");
        // }
    }
    return 0;
}
