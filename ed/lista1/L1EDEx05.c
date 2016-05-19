//Caique Hitoshi Mitsuoka 0030481511006
//Felipe Richter Lapolla Inocencio 0030481511013

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct reg{
    struct reg *prox;
    int num;
}TREG;

typedef struct list{
    struct reg *inicio;
    struct reg *fim;
}TLISTA;

void AddItem(TLISTA *lista , int novo){
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

void PrintLista(TLISTA *lista){
    TREG *aux = lista->inicio;
    if(aux != NULL){
        printf("%d", aux->num);
        aux = aux->prox;
    }
    while(aux != NULL){
        printf(" %d", aux->num);
        aux = aux->prox;
    }
    printf("\n");
}

void DeleteItem(TLISTA *lista,int item){
    TREG *aux = lista->inicio, *bef = NULL;
    while(aux != NULL){
        if(aux->num == item){
            if(bef == NULL){
                lista->inicio = lista->inicio->prox;
                free(aux);
                break;
            }else{
                bef->prox = aux->prox;
                free(aux);
                break;
            }
        }
        bef = aux;
        aux = aux->prox;
    }
}
int main(){
    TLISTA *Lista = (TLISTA*)malloc(sizeof(TLISTA));
    int a, tLista, item, ndelete;

    scanf("%d", &tLista);

    for(a=0;a<tLista;a++){
        scanf("%d", &item);
        AddItem(Lista, item);
    }

    scanf("%d", &ndelete);

    for(a=0;a<ndelete;a++){
        scanf("%d", &item);
        DeleteItem(Lista, item);
    }

    PrintLista(Lista);
    return 0;
}
