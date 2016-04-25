#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct nighttrain{
    int trem;
    struct nighttrain *prox;
}TTREM;

typedef struct{
    TTREM *inicio;
    TTREM *fim;
}TLISTA;

void addstack(TTREM *novo, TLISTA *pilha){
    novo->prox = pilha->inicio;
    pilha->inicio = novo;
    if(pilha->fim == NULL){
        pilha->fim = novo;
    }
}

void addfila(TTREM *novo, TLISTA *pilha){
    pilha->fim->prox = novo;
    novo->prox = NULL;
    pilha->fim = novo;
}

TTREM* stackpop(TLISTA *brunarosada){
    TTREM *aux = brunarosada->inicio;
    if(aux == NULL){
        return aux;
    }
    brunarosada->inicio = aux->prox;
    return aux;
}

void criarlistaEntrada(TLISTA *Entrada,int *ntrem){
    int a;
    TTREM *aux;
    Entrada->inicio = NULL;
    Entrada->fim = NULL;
    for(a = *ntrem;a>0;a--){
        aux = (TTREM*)malloc(sizeof(TTREM));
        aux->trem = a;
        addstack(aux,Entrada);
    }
}

void printstack(TTREM *SDDSJIANG){
    int a;
    for(a=0;SDDSJIANG != NULL;a++){
        printf("trem: %d no lugar: %d\n",SDDSJIANG->trem,a);
        SDDSJIANG = SDDSJIANG->prox;
    }
}

int InAndOut(TLISTA *Entrada,TLISTA *Saida){
    TLISTA *stc = (TLISTA*)malloc(sizeof(TLISTA));
    TTREM *entrando;
    stc->inicio = NULL;
    stc->fim = NULL;
    while(Entrada->inicio != NULL){
        entrando = stackpop(Entrada);
        addstack(entrando, stc);
        while(stc->inicio != NULL && Saida->inicio != NULL){
            if(stc->inicio->trem == Saida->inicio->trem){
                stackpop(stc);
                stackpop(Saida);
            }else{
                break;
            }
        }
    }
    // printf("\nstc\n");
    // printstack(stc->inicio);
    if(stc->inicio == NULL && Saida->inicio == NULL){
        return 0;
    }else{
        return 1;
    }

    return 1;
}

int main(){
    TLISTA *Entrada, *Saida;
    TTREM *aux;
    int ntrem,a,trem;
    scanf("%d", &ntrem);
    while(ntrem){
        Entrada = (TLISTA*)malloc(sizeof(TLISTA));
        criarlistaEntrada(Entrada,&ntrem);

        // printf("\nentrada\n");
        // printstack(Entrada->inicio);

        scanf("%d", &trem);
        while(trem){
            Saida = (TLISTA*)malloc(sizeof(TLISTA));
            Saida->inicio = NULL;
            Saida->fim = NULL;
            aux = (TTREM*)malloc(sizeof(TTREM));
            aux->trem = trem;
            addstack(aux,Saida);
            for(a=1;a<ntrem;a++){
                scanf("%d", &trem);
                aux = (TTREM*)malloc(sizeof(TTREM));
                aux->trem = trem;
                addfila(aux,Saida);
            }
            Entrada = (TLISTA*)malloc(sizeof(TLISTA));
            criarlistaEntrada(Entrada,&ntrem);
            if(InAndOut(Entrada,Saida)){
                printf("No\n");
            }else{
                printf("Yes\n");
            }

            // printf("\nsaida\n");
            // printstack(Saida->inicio);

            scanf("%d", &trem);

            // printf("\n\n\n");
        }
        printf("\n");
        scanf("%d", &ntrem);
    }
    return 0;
}
