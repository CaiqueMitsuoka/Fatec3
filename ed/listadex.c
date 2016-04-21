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
}T_CID;

T_CID* busca (T_CID *inicio, char *chave){
    while(inicio){
        if(!strcmp(inicio->nome,chave)){
            return inicio;
        }
        inicio = inicio->prox;
    }
    return (T_CID*)NULL;
}

int imprimir (T_CID *inicio, char *cabecalho){
    printf("%s", cabecalho);
    while(inicio){
        printf("Nome:%25s   População: %10d Area: %.3f\n", inicio->nome,inicio->pop,inicio->area);
        inicio = inicio->ant;
    }
    return 0;
}

int remover(T_CID *inicio,char *nome){
    T_CID *ant =  NULL;
    while(inicio){
        if(!strcmp(inicio->nome,nome)){
            break;
        }
        ant = inicio;
        inicio = inicio->prox;
    }

    if(ant != NULL && inicio->prox != NULL){
        inicio->ant->prox = inicio->prox;
        inicio->prox->ant = inicio->ant;
        free(inicio);
        return 0;
    }else{
        if(ant != NULL){
            inicio->prox->ant = NULL;
        }else{
            inicio->ant->prox = NULL;
        }
        free(inicio);
        return 2;
    }
    return 1;
}

void vaievolta(T_CID *eae){
    while(eae){
        printf("Nome:%25s   População: %10d Area: %.3f\n", eae->nome,eae->pop,eae->area);
        eae = eae->ant;
    }
    while(eae){
        printf("Nome:%25s   População: %10d Area: %.3f\n", eae->nome,eae->pop,eae->area);
        eae = eae->prox;
    }
}

int main(){
    char vnome[21];
    int vpop,cod;
    float varea;
    T_CID *inicio, *final, *aux, *anterior;
    inicio = NULL;
    final = NULL;
    while(1){
        //printf("informe o nome da cidade (ou ""FIM"" p/ encerrar): \n");
        scanf("%s",vnome);
        if(!strcmp(vnome,"FIM")){
            break;
        }
        //printf("Infome a população: \n");
        scanf("%d", &vpop);
        //printf("Infome a area: \n");
        scanf("%f", &varea);

        aux = (T_CID*)malloc(sizeof(T_CID));
        if(aux == NULL){
            printf("memoria insuficiente\n");
        }

        strcpy(aux->nome, vnome);
        // aux->ant = inicio;
        aux->pop = vpop;
        aux->area = varea;
        aux->prox = NULL;

        if(inicio == NULL){
            inicio = aux;
            aux->ant = NULL;
        }else{
            final->prox = aux;
            aux->ant = final;
        }
        final = aux;
    }
    imprimir(final,(char*)"Lista Atual: \n");

    //leia o valor a ser encontrado(no caso cidade)
    scanf("%s",vnome);
    aux = busca(inicio,vnome);
    if(aux != NULL){
        imprimir(aux,(char*)"Valor encontrado!\n");
    }else{
        printf("Valor não encontrado\n");
    }

    //Leia o valor para exclusao "stap" para o processo
    scanf("%s",vnome);
    while(strcmp(vnome,"stap")){
        //chamar a remoção e retornar o codigo de retorno
        cod = remover(inicio,vnome);
        //olho se é nulo, se for deu tudo certo e a rua é nois
        if (cod == 0){
            imprimir(final,(char*)"Nova Tabela:\n");
        }else{
            //aqui deu algum ruim, então ou é o primeiro ou n achou
            if(cod == 1/*nosso querido codigo de erro*/){
                printf("Valor no encontrado\n");
            }else{
                //se não, oque ele retornou é o 2, nosso código de erro caso ele seja o primeiro
                //isso me diz que eu preciso realinha o inicio da lista que agora é o "segundo" item
                inicio = inicio->ant;
                imprimir(inicio,(char*)"Nova Tabela:\n");
            }
        }
        scanf("%s",vnome);
    }
    vaievolta(inicio);
    return 0;
}
