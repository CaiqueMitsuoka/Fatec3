#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct{
	char nome[21];
	int pop;
	float area;
}TCid;

typedef struct enccidade{
	char nome[21];
	int pop;
	float area;
	struct enccidade *prox;
}eTCid;

typedef union {
    TCid con;
    eTCid le;
}TCidade;

typedef struct {
    TCidade *cidade;
    int elemento;
    long int somapop;
    double somaarea;
    char tipo;
}abtLista;

int main(){
	char tipo;
	char vnome[21];
	int vpop,cod;
	float varea;
	TCidade *inicio, *aux, *ant;

	//tipo de lista
	printf("Insira o tipo de lista(0 contigua-1 encadeado): ");
	scanf("%d",&tipo);

	if(tipo){
		//Encadeada

		inicio = NULL;
		while(1){
			printf("informe o nome da cidade (ou ""FIM"" p/ encerrar): \n");
			scanf("%s",vnome);
			if(!strcmp(vnome,"FIM")){
				break;
			}
			printf("Infome a população: \n");
			scanf("%d", &vpop);
			printf("Infome a area: \n");
			scanf("%f", &varea);

			aux = (TCidade*)malloc(sizeof(TCidade));
			if(aux == NULL){
				printf("memoria insuficiente\n");
			}

			strcpy(aux->nome, vnome);
			aux->le->pop = vpop;
			aux->le->area = varea;
			aux->le->prox = NULL;

			if(inicio == NULL){
				inicio = aux;
			}else{
				ant->prox = aux;
			}
			ant = aux;


		}

	}else{
		//contigua


	}

    return 0;
}
