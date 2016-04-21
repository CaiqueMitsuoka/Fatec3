#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//LEIA OS COMENTARIOS DA ROTINA "remover"
//DEPOIS LEIA OS COMENTARIOS DOS RETORNO DA MAIN, LA NO FINAL
typedef struct regCid{
    struct regCid *ant;
    char nome[21];
    int pop;
    float area;
    struct regCid *prox;
}T_CID;

T_CID* busca (T_CID *inicio, char *chave){
    //enquanto o ponteiro n for nulo
    while(inicio){
        //compare e retorne o o ponteiro de onde está;
        if(!strcmp(inicio->nome,chave)){
            return inicio;
        }
        //andar para o proximo
        inicio = inicio->prox;
    }
    return (T_CID*)NULL;
}

int imprimir (T_CID *inicio, char *cabecalho){
    printf("%s", cabecalho);
    while(inicio){
        printf("Nome:%25s   População: %10d Area: %.3f\n", inicio->nome,inicio->pop,inicio->area);
        inicio = inicio->prox;
    }
    return 0;
}

int remover(T_CID *inicio,char *nome){
    T_CID *ant =  NULL;
    //eu não chamei a rotina de busca porque eu quero o ponteiro do anterior
    //procura e para com o ponteiro no cara que deve ser excluido
    while(inicio){
        if(!strcmp(inicio->nome,nome)){
            break;
        }
        ant = inicio;
        inicio = inicio->prox;
    }

    //se o anterior for nulo, estamos no primeiro caso, ou seja, temos que livrar a primeira posição e atualizar
    //o inicio do vetor na main, vamo fazer isso enviando um erro de codigo 2
    //caso o anterio não seja nulo ta de boas, é só arrumar os ponteiros e da um free;
    if(ant != NULL){
        ant->prox = inicio->prox;
        free(inicio);
        return 0;
    }else{
        ant = inicio->prox;
        free(inicio);
        return 2;
    }
    //Caso não seja encontrado nada, retorne o erro 1(cast is for good pratice);
    return 1;
}

int main(){
    char vnome[21];
    int vpop,cod;
    float varea;
    T_CID *inicio, *aux, *ant;
    inicio = NULL;
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
        aux->pop = vpop;
        aux->area = varea;
        aux->prox = NULL;

        if(inicio == NULL){
            inicio = aux;
        }else{
            ant->prox = aux;
        }
        ant = aux;
    }
    imprimir(inicio,(char*)"Lista Atual: \n");

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
            imprimir(inicio,(char*)"Nova Tabela:\n");
        }else{
            //aqui deu algum ruim, então ou é o primeiro ou n achou
            if(cod == 1/*nosso querido codigo de erro*/){
                printf("Valor no encontrado\n");
            }else{
                //se não, oque ele retornou é o 2, nosso código de erro caso ele seja o primeiro
                //isso me diz que eu preciso realinha o inicio da lista que agora é o "segundo" item
                inicio = inicio->prox;
                imprimir(inicio,(char*)"Nova Tabela:\n");
            }
        }
        scanf("%s",vnome);
    }

    return 0;
}
