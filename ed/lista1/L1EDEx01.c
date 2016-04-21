#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct disciplinas{
	struct disciplinas *anterior;
	char RA[14];
	char Sigla[6];
	float Nota;
	int QtFaltas;
	struct disciplinas *proximo;
}Disciplina;


int main(){

	int i, j, qtelementos = 0, flag = 0, encontrou = 0;
	char ExSigla[6];
	Disciplina *aux, *ant, *inicio;

	while(1){
		aux = (Disciplina *) malloc(sizeof(Disciplina));
		if(flag == 0){
			aux->anterior = NULL;
			inicio = aux;
		}
		aux->proximo = NULL;


		if(flag == 1){
			aux->anterior = ant;
			ant->proximo = aux;
		}
		
		//printf("Digite o RA\n");
		scanf(" %[^\n]", aux->RA);
		
		if(strcmp(aux->RA,"XXX") == 0)
			break;

		//printf("Digite a Sigla\n");
		scanf(" %[^\n]", aux->Sigla);
		//printf("Digite a nota\n");
		scanf("%f", &aux->Nota);
		//printf("Digite a QtFaltas\n");
		scanf("%d", &aux->QtFaltas);

		ant = aux;

		flag = 1;
		qtelementos++;
	}

	aux = inicio;

	for(i=0;i<qtelementos;i++){
		printf("%s\n", aux->RA);
		printf("%s\n", aux->Sigla);
		printf("%.2f\n", aux->Nota);
		printf("%d\n", aux->QtFaltas);
		aux = aux->proximo;
	}

	while(strcmp(ExSigla, "XXX") != 0){
		scanf(" %s", ExSigla);
		aux = inicio;
		while(aux->proximo != NULL){
			if(strcmp(aux->Sigla,ExSigla) == 0){
				if(aux->anterior != NULL){
					aux->anterior->proximo = aux->proximo;
				}

				if(aux == inicio){
					aux->proximo->anterior == NULL;
					inicio = aux->proximo;
				}

				encontrou = 1;
				qtelementos--;
				free(aux);
			}

			aux = aux->proximo;
		}
		if(encontrou == 0)
			printf("Nao foi encontrado essa sigla na lista\n");
		else if(encontrou == 1){
			encontrou = 0;
		}
	}

	aux = inicio;

	for(i=0;i<qtelementos;i++){
		printf("%s\n", aux->RA);
		printf("%s\n", aux->Sigla);
		printf("%.2f\n", aux->Nota);
		printf("%d\n", aux->QtFaltas);

		aux = aux->proximo;	
	}

	return 0;
}