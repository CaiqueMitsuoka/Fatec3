#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct listad{
    struct listad *ant;
    char panc;
    struct listad *prox;
}TLISTA;

TLISTA* limpalist(char *panc){
    TLISTA *aux,*bef,*inicio;
    int tam = strlen(panc),a;
    for(a=0;a<tam;a++){
        if(a){
            if(panc[a] != panc[a-1]){
                aux = (TLISTA*)malloc(sizeof(TLISTA));
                aux->ant = bef;
                aux->panc = panc[a];
                aux->prox = NULL;
                bef->prox = aux;
                bef = aux;
            }
        }else{
            aux = (TLISTA*)malloc(sizeof(TLISTA));
            aux->ant = NULL;
            aux->panc = panc[a];
            aux->prox = NULL;
            bef = aux;
            inicio = aux;
        }
    }
    return inicio;
}

void swap(TLISTA *inicio){
    TLISTA *aux;
    aux = inicio->ant;
    while(aux != NULL){
        if(aux->panc == '-'){
            aux->panc = '+';
        }else{
            aux->panc = '-';
        }
        aux = aux->ant;
    }
}

int main(){
    TLISTA *aux,*inicio;
    int casos,a,cont;
    char panc[105];
    scanf("%d", &casos);
    for (a=1;a<=casos;a++){
        scanf("%s",panc);
        inicio = limpalist(panc);
        aux = inicio;
        if(inicio->prox == NULL){
            if(inicio->panc == '-'){
                printf("Case #%d: 1\n",a);
            }else{
                printf("Case #%d: 0\n",a);
            }
            continue;
        }
        swap(inicio->prox);
        aux = aux->prox;
        cont = 1;
        while(aux!=NULL){
            if(aux->ant->panc != aux->panc){
                cont++;
                swap(aux);
                aux = inicio;
            }
            aux = aux->prox;
        }
        if(inicio->panc == '-'){
            printf("Case #%d: %d\n",a,cont + 1);
        }else{
            printf("Case #%d: %d\n",a,cont);
        }
    }
    return 0;
}
