#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct listad{
    struct listad *ant;
    char tile;
    struct listad *prox;
}TLISTA;

TLISTA* geralista(int lista,int parada){
    TLISTA *aux,*bef,*inicio;
    int a;
    aux = (TLISTA*)malloc(sizeof(TLISTA));
    aux->ant = NULL;
    aux->tile = lista%2;
    lista = lista / 2;
    aux->prox = NULL;
    inicio = aux;
    bef = aux;
    inicio = aux;
    for(a=1;a<parada;a++){
        aux = (TLISTA*)malloc(sizeof(TLISTA));
        aux->tile = lista%2;
        lista = lista / 2;
        aux->prox = NULL;
        bef->prox = aux;
        aux->ant = bef;
        bef = aux;
    }
    return inicio;
}

int potencia(int K,int *C){
    int a,temp = K;
    for(a=1;a<*C;a++){
        temp = temp * K;
    }
    return temp;
}

void sequencia(TLISTA *N){
    TLISTA *aux = N;
    while(aux != NULL){
        if(aux->tile == 1){
            printf("G");
        }else{
            printf("L");
        }
        aux = aux->prox;
    }
    printf("\n");
}
TLISTA* complex(TLISTA *inicio1,int tam){
    TLISTA *aux1 = inicio1,*inicio,*bef,*aux,*aux2;
    int a;
    aux = (TLISTA*)malloc(sizeof(TLISTA));
    inicio = aux;
    bef = aux;
    aux->prox = NULL;
    aux->ant = NULL;
    while(aux1 != NULL){
        if(aux1->tile){
            aux2 = inicio1;
            while(aux2!=NULL){
            // for(a=0;a<tam;a++){
                aux = (TLISTA*)malloc(sizeof(TLISTA));
                bef->prox = aux;
                aux->ant = bef;
                aux->tile = aux1->tile;
                aux->prox = NULL;
                aux = bef;
                aux2 = aux2->prox;
            }
        }else{
            aux2 = inicio1;
            while(aux2!=NULL){
            //for(a=0;a<tam;a++){
                aux = (TLISTA*)malloc(sizeof(TLISTA));
                aux->ant = bef;
                bef->prox = aux;
                aux->tile = aux2->tile;
                aux->prox = NULL;
                aux = bef;
                aux2 = aux2->prox;
            }
        }
        aux1 = aux1->prox;
    }
    sequencia(inicio);
    inicio->prox->ant = NULL;
    // inicio = inicio->prox;
    return inicio->prox;
}
int main(){
    int vet[1000];
    int casos,a,b,c,K,C,S,ate;
    TLISTA *atual;
    scanf("%d", &casos);
    for(a=0;a<casos;a++){
        scanf("%d %d %d", &K, &C, &S);
        ate = potencia(K,&C);
        for(b=0;b<ate;b++){
            vet[b] = 0;
        }

        if(vet[b-1]){
            vet[0]++;
        }

        printf("Case #%d: ",a+1);
        ate = potencia(2,&K);
        for(b=0;b<ate;b++){
            //gerar lista
            atual = geralista(b,K);
            // adicionar complexibilidades
            for(c=1;c<C;c++){
                atual = complex(atual,potencia(K,&C));
                // sequencia(atual);
            }
        }
    }
    return 0;
}
