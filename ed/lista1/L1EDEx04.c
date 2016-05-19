//Caique Hitoshi Mitsuoka 0030481511006
//Felipe Richter Lapolla Inocencio 0030481511013

#include <stdio.h>
#include <stdlib.h>

typedef struct reg{
    struct reg *prox;
    int num;
    struct reg *ant;
}TREG;
typedef struct list{
    struct reg *inicio;
    struct reg *fim;
}TLISTA;
void PrintLista(TLISTA *lista,char *head){
    TREG *aux = lista->inicio;
    printf("%s", head);
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
void AddItem(TLISTA *lista , int novo){
    TREG *aux = (TREG*)malloc(sizeof(TREG));
    aux->num = novo;
    aux->prox = NULL;
    if(lista->inicio == NULL){
        lista->inicio = aux;
        aux->ant = NULL;
    }else{
        lista->fim->prox = aux;
        aux->ant = lista->fim;
    }
    lista->fim = aux;
}
void BubbleList(TLISTA *lista){
    TREG *aux1,*aux2;
    int temp;
    for(aux1 = lista->fim->ant; aux1 != NULL; aux1 = aux1->ant){
        for(aux2 = lista->inicio; aux2->prox != NULL; aux2= aux2->prox){
            if(aux2->num > aux2->prox->num){
                temp = aux2->num;
                aux2->num = aux2->prox->num;
                aux2->prox->num = temp;
            }
        }
    }
}
TLISTA* Uniao(TLISTA *lista1, TLISTA *lista2){
    TREG  *aux1 = lista1->inicio, *aux2 = lista2->inicio;
    TLISTA *lista3 = (TLISTA*)malloc(sizeof(TLISTA));
    lista3->inicio = NULL;
    lista3->fim = NULL;
    while(aux1 != NULL){
        while(aux2 != NULL && aux2->num < aux1->num){
            AddItem(lista3,aux2->num);
            aux2 = aux2->prox;
        }
        if(aux2 != NULL && aux2->num == aux1->num){
            AddItem(lista3,aux1->num);
            aux2 = aux2->prox;
        }else{
            AddItem(lista3,aux1->num);
        }
        aux1 = aux1->prox;
    }
    while(aux2 != NULL){
        AddItem(lista3,aux2->num);
        aux2 = aux2->prox;
    }
    return lista3;
}
TLISTA* Intersec(TLISTA *lista1, TLISTA *lista2){
    TREG  *aux1 = lista1->inicio, *aux2 = lista2->inicio;
    TLISTA *lista3 = (TLISTA*)malloc(sizeof(TLISTA));
    lista3->inicio = NULL;
    lista3->fim = NULL;
    while(aux1 != NULL){
        if(aux2 == NULL){
            break;
        }
        while(aux2 != NULL){
            if(aux2->num >= aux1->num){
                if(aux2->num == aux1->num){
                    AddItem(lista3,aux1->num);
                }
                break;
            }
            aux2 = aux2->prox;
        }
        aux1 = aux1->prox;
    }
    return lista3;
}
TLISTA* Diff(TLISTA *lista1, TLISTA *lista2){
    TREG  *aux1 = lista1->inicio, *aux2 = lista2->inicio;
    TLISTA *lista3 = (TLISTA*)malloc(sizeof(TLISTA));
    lista3->inicio = NULL;
    lista3->fim = NULL;
    while(aux1 != NULL){
        while(aux2 != NULL && aux1->num > aux2->num){
            AddItem(lista3,aux2->num);
            aux2 = aux2->prox;
        }
        aux2 = aux2->prox;
        aux1 = aux1->prox;
    }
    return lista3;
}

int main(){
    TLISTA lista[2],*uniao,*intersec,*diff1,*diff2;
    int a;
    int novo;

    for(a=0;a<2;a++){
        lista[a].inicio = NULL;
        lista[a].fim = NULL;
        printf("Insira os numeros pertencentes ao conjunto %d (""-1"": Para interromper): \n", a+1);
        scanf("%d", &novo);
        while(novo >= 0){
            AddItem(&lista[a],novo);
            scanf("%d", &novo);
        }
        /* Ordenar para diminuir as comparações; */
        BubbleList(&lista[a]);
    }

    /* Prints e chamadas das operações */
    PrintLista(&lista[0], (char*)"Conjunto 1:\n");
    PrintLista(&lista[1], (char*)"Conjunto 2:\n");
    uniao = Uniao(&lista[0],&lista[1]);
    PrintLista(uniao, (char*)"Uniao dos conjuntos:\n");
    intersec = Intersec(&lista[0],&lista[1]);
    PrintLista(intersec, (char*)"Interseccao dos conjuntos:\n");
    diff1 = Diff(intersec,&lista[0]);
    PrintLista(diff1, (char*)"Diferenca Conjunto 1 - Conjunto 2 :\n");
    diff2 = Diff(intersec, &lista[1]);
    PrintLista(diff2, (char*)"Diferenca Conjunto 2 - Conjunto 1 :\n");

    return 0;
}
