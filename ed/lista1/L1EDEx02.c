//Caique Hitoshi Mitsuoka 0030481511006
//Felipe Richter Lapolla Inocencio 0030481511013

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct reg{
    struct reg *prox;
    float num;
}TREG;

typedef struct list{
    struct reg *inicio;
    struct reg *fim;
}TLISTA;

void AddItem(TLISTA *lista , float novo){
    TREG *aux = (TREG*)malloc(sizeof(TREG));
    aux->num = novo;
    aux->prox = NULL;
    if(lista->inicio == NULL){
        lista->inicio = aux;
    }else{
        lista->fim->prox = aux;
    }
    lista->fim = aux;
}

TLISTA* GerarListaIII(TLISTA *lista1, TLISTA *lista2){
    float v1, v2;
    TREG  *aux1 = lista1->inicio, *aux2 = lista2->inicio;
    TLISTA *lista3 = (TLISTA*)malloc(sizeof(TLISTA));
    lista3->inicio = NULL;
    lista3->fim = NULL;
    while(aux1 != NULL || aux2 != NULL){
        if(aux1 == NULL){
            v1 = 0.0;
        }else{
            v1 = aux1->num;
            aux1 = aux1->prox;
        }
        if(aux2 == NULL){
            v2 = 0.0;
        }else{
            v2 = aux2->num;
            aux2 = aux2->prox;
        }

        if(v1 > v2){
            AddItem(lista3,v1);
        }else{
            AddItem(lista3,v2);
        }
    }
    return lista3;
}

void PrintList(TLISTA *lista,char *head){
    TREG *aux = lista->inicio;
    printf("%s", head);
    while(aux != NULL){
        printf(" %.2f", aux->num);
        aux = aux->prox;
    }
    printf("\n");
}

int main(){
    TLISTA lista[2];
    int a;
    float novo;
    for(a=0;a<2;a++){
        lista[a].inicio = NULL;
        lista[a].fim = NULL;
        scanf("%f", &novo);
        while(novo >= 0){
            AddItem(&lista[a],novo);
            scanf("%f", &novo);
        }
    }
    PrintList(&lista[0], (char*)"Lista 1:");
    PrintList(&lista[1], (char*)"Lista 2:");
    PrintList(GerarListaIII(&lista[0],&lista[1]), (char*)"Lista 3:");
    return 0;
}
