#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    char nome[101];
    char tam;
    char cor[10];
}ListaCamisa;

int comp(const void *a,const void *b){
    ListaCamisa *p1 = (ListaCamisa*)a, *p2 = (ListaCamisa*)b;
    int diffcor = strcmp(p1->cor,p2->cor),difftam,diffnom;
    if (diffcor){
        if(diffcor > 0){
            return 1;
        }else{
            return -1;
        }
    }else{
        difftam = p1->tam - p2->tam;
        if(difftam){
            if(difftam > 0){
                return -1;
            }else{
                return 1;
            }
        }else{
            diffnom = strcmp(p1->nome,p2->nome);
            if(diffnom){
                if(diffnom > 0){
                    return 1;
                }else{
                    return -1;
                }
            }else{
                return 0;
            }
        }
    }
}

int main(){
    ListaCamisa Camisetas[60];
    int casos,a,tam;
    char trash[6];
    scanf("%d",&casos);
    do{
        for(a=0;a<casos;a++){
            fgets(trash,5,stdin);
            fgets(Camisetas[a].nome,101,stdin);
            tam = 0;
            while(Camisetas[a].nome[tam]){
                tam++;
            }
            Camisetas[a].nome[tam-1] = '\0';
            scanf("%s %c", Camisetas[a].cor, &Camisetas[a].tam);
        }
        qsort(Camisetas,casos,sizeof(ListaCamisa),comp);
        for(a=0;a<casos;a++){
            printf("%s %c %s\n",Camisetas[a].cor,Camisetas[a].tam,Camisetas[a].nome);
        }
        scanf("%d",&casos);
        if(casos){
            printf("\n");
        }
    }while(casos);
    return 0;
}
