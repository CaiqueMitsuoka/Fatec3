#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct LUIZ{
    int carta;
    struct LUIZ *prox;
}TCARTA;

typedef struct{
    TCARTA *inicio;
    TCARTA *fim;
    int caras;
}TLISTA;

void AdicionarFila(TLISTA *lista,TCARTA *carta){
    lista->caras = lista->caras + 1;
    if (lista->fim == NULL){
        lista->inicio = carta;
        lista->fim = carta;
    }else{
        lista->fim->prox = carta;
        lista->fim = carta;
    }
}
TCARTA* popbar(TLISTA *lista){
    TCARTA *aux;
    aux = lista->inicio;
    lista->inicio = aux->prox;
    lista->caras = lista->caras - 1;
    return aux;
}

int main(){
    int ow,a;
    TCARTA *aux;
    TLISTA *Baralho;
    Baralho = (TLISTA*)malloc(sizeof(TLISTA));
    Baralho->inicio = NULL;
    Baralho->fim = NULL;
    Baralho->caras = 0;
    scanf("%d", &ow);
    while(ow){
        Baralho = (TLISTA*)malloc(sizeof(TLISTA));
        Baralho->inicio = NULL;
        Baralho->fim = NULL;
        Baralho->caras = 0;
        for(a=1;a<=ow;a++){
            aux = (TCARTA*)malloc(sizeof(TCARTA));
            aux->carta = a;
            aux->prox = NULL;
            AdicionarFila(Baralho,aux);
        }
        printf("Discarded cards:");
        ow = 0;
        while(1){
             aux = popbar(Baralho);
             if(ow){
                 printf(",");
             }
             ow=1;
             printf(" %d", aux->carta);
             free(aux);
             if(Baralho->caras == 1){
                 break;
             }
             aux = popbar(Baralho);
             AdicionarFila(Baralho,aux);
        }
        printf("\nRemaining card: %d\n", Baralho->inicio->carta);
        free(Baralho->inicio);
        free(Baralho);
        scanf("%d", &ow);
    }
    return 0;
}
