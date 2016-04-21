#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct regCid{
    struct regCid *ant;
    char nome[21];
    int pop;
    float area;
    struct regCid *prox;
}TCidade;

typedef struct {
    TCidade *inicio;
    TCidade *fim;
    int nitem;
    int tpop;
    double tarea;
}TLista;

void IniciarLista(TLista *Lista){
    Lista->inicio = NULL;
    Lista->fim = NULL;
    Lista->tpop = 0;
    Lista->tarea = 0.0;
    Lista->nitem = 0;
}
void InserirLista(TLista *Lista, char *cidade, int *pop, float *area){
    TCidade *aux, *temp;
    aux = (TCidade*)malloc(sizeof(TCidade));
    strcpy(aux->nome,cidade);
    aux->pop = *pop;
    aux->area = *area;
    Lista->inicio = aux;
    Lista->fim = aux;
    Lista->nitem++;
    Lista->tpop += *pop;
    Lista->tarea += *area;
    if(Lista->inicio == NULL){
        Lista->inicio = aux;
        Lista->fim = aux;
        aux->ant = NULL;
        aux->prox = NULL;
    }else{
        temp = Lista->inicio;
        while(temp->prox != NULL){
            temp = temp->prox;
        }
        aux->prox = NULL;
        aux->ant = temp;
        temp->prox = aux;
    }
}

TCidade* BuscarNaLista(TLista *Lista, char *procurado){

    return Lista->inicio;
}

void Excluir(TLista *Lista, char *procurado){

}

void Imprimir(TLista *Lista,char *cabecalho){
    if(Lista == NULL){
        printf("Lista Vazia\n");
    }else{
        printf(cabecalho);        
    }

}

int main(){
    char cidade[21];
    int op,pop;
    float area;
    TCidade aux;
    TLista Lista;
    IniciarLista(&Lista);

    do{
        printf("Qual operacao deseja realizar?\n0-Sair\n1-Inserir Cidade\n2-Buscar Cidade\n3-Excluir Cidade\n4-Visualizar");
        scanf("%d", &op);
        switch (op){
            case 0:
                break;
            case 1:
                fgets(cidade,5,stdin);
                fgets(cidade,20,stdin);
                scanf("%d %f",&pop,&area);
                aux.ant = aux.prox = NULL;
                InserirLista(&Lista,cidade,&pop,&area);
                break;
            case 2:
                fgets(cidade,5,stdin);
                fgets(cidade,20,stdin);
                BuscarNaLista(&Lista,cidade);
                break;
            case 3:
                fgets(cidade,5,stdin);
                fgets(cidade,20,stdin);
                Excluir(&Lista,cidade);
                break;
            case 4:
                Imprimir(&Lista,(char*)"Lista Atual:");
                break;
        }
    }while(op);
    return 0;
}
