#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int nome;
    int cestas;
    int recebidos;
    int pontos;
}TTIMES;

int comp(const void *a,const void *b){
    TTIMES *p1 = (TTIMES*)a,*p2 = (TTIMES*)b;
    float average;
    int diffpontos,diffcesta;
    diffpontos = p1->pontos - p2->pontos;
    if (diffpontos != 0){
        // printf("pontos");
        if(diffpontos > 0){
            return -1;
        }else{
            return 1;
        }
    }else{
        average = ((float)p1->cestas / p1->recebidos) - ((float)p2->cestas / p2->recebidos);
        if(average){
            // printf("average");
            if(average > 0){
                return -1;
            }else{
                return 1;
            }
        }else{
            diffcesta = p1->cestas - p2->cestas;
            if(diffcesta){
                // printf("cesta");
                if(diffcesta > 0){
                    return -1;
                }else{
                    return 1;
                }
            }else{
                // printf("nome");
                if(p1->nome > p2->nome){
                    return 1;
                }else{
                    return -1;
                }
            }
        }
    }
}

int main(){
    int casos,a,ntimes, instancia = 0;
    TTIMES times[100],temp1,temp2;
    scanf("%d", &ntimes);
    while(ntimes){
        for(a=0;a<ntimes;a++){
            times[a].nome = a + 1;
            times[a].cestas = 0;
            times[a].recebidos = 0;
            times[a].pontos = 0;
        }
        casos = (ntimes * (ntimes - 1)) / 2;
        for(a=0;a<casos;a++){
            scanf("%d %d %d %d", &temp1.nome, &temp1.cestas, &temp2.nome, &temp2.cestas);
            times[temp1.nome - 1].cestas += temp1.cestas;
            times[temp1.nome - 1].recebidos += temp2.cestas;
            times[temp2.nome - 1].cestas += temp2.cestas;
            times[temp2.nome - 1].recebidos += temp1.cestas;
            if(temp1.cestas > temp2.cestas){
                times[temp1.nome - 1].pontos  += 2;
                times[temp2.nome - 1].pontos++;
            }else{
                times[temp2.nome - 1].pontos  += 2;
                times[temp1.nome - 1].pontos++;
            }
        }

        qsort(times,ntimes,sizeof(TTIMES),comp);

        // for(a=0;a<ntimes;a++){
        //     printf("\npontos:%d average:%f cestas%d nome%d\n",times[a].pontos,(float)times[a].pontos / times[a].recebidos,times[a].cestas,times[a].nome);
        // }

        if(instancia){
            printf("\n\n");
        }
        instancia++;
        printf("Instancia %d\n", instancia);

        for(a=0;a<ntimes;a++){
            if(a){
                printf(" ");
            }
            printf("%d",times[a].nome);
        }
        //printf("\n");
        scanf("%d", &ntimes);
    }
    printf("\n");
    return 0;
}
