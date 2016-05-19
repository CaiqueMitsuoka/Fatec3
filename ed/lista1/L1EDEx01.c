//Caique Hitoshi Mitsuoka 0030481511006
//Felipe Richter Lapolla Inocencio 0030481511013

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

typedef struct descrLista{
	Disciplina *inicio;
	Disciplina *fim;
}DLista;

void imprimeLista(DLista *descritor);
int excluiSigla(DLista *descritor,char *exSigla);
void criaLista(DLista *descritor, Disciplina leitura);

int main(){
	DLista *descritor = (DLista *) malloc(sizeof(DLista));
	descritor->inicio = NULL;
	descritor->fim = NULL;
	Disciplina leitura;
	char exSigla[6], achou;

	scanf("%s", leitura.RA);
	while(1){
		if(strcmp(leitura.RA, "XXX") == 0)
			break;
		scanf(" %s", leitura.Sigla);
		scanf("%f", &leitura.Nota);
		scanf("%d", &leitura.QtFaltas);
		criaLista(descritor, leitura);

		scanf(" %s", leitura.RA);
	}
	imprimeLista(descritor);
	scanf(" %s", exSigla);

	while(strcmp(exSigla,"XXX") != 0){
		achou = excluiSigla(descritor, exSigla);
		if(achou == 0)
			printf("Não foi encontrado essa sigla na lista\n");
		scanf(" %s", exSigla);
	}
	imprimeLista(descritor);

	return 0;
}

void criaLista(DLista *descritor, Disciplina leitura){
	Disciplina *aux = (Disciplina *) malloc(sizeof(Disciplina));

	strcpy(aux->RA,leitura.RA);
	strcpy(aux->Sigla,leitura.Sigla);
	aux->Nota = leitura.Nota;
	aux->QtFaltas = leitura.QtFaltas;
	aux->proximo = NULL;

	if(descritor->inicio==NULL){
	 	descritor->inicio = aux;
	 	aux->anterior = NULL;
	}
	else{
		descritor->fim->proximo=aux;
		aux->anterior = descritor->fim;
	}
	descritor->fim = aux;
}

void imprimeLista(DLista *descritor){
	Disciplina *aux;
	aux = descritor->inicio;

	while(aux!=NULL){
		printf("%s\n", aux->RA);
		printf("%s\n", aux->Sigla);
		printf("%.2f\n", aux->Nota);
		printf("%d\n", aux->QtFaltas);
		aux = aux->proximo;
	}
}

int excluiSigla(DLista *descritor,char *exSigla){
	Disciplina *aux, *ajudaluciano, *livre;
	aux = descritor->inicio;
	int achou = 0;

	while(aux!=NULL){
		if(strcmp(aux->Sigla, exSigla)==0){
			if(aux->anterior == NULL && aux->proximo == NULL){
				descritor->inicio = NULL;
			}
			else if(aux->anterior == NULL && aux->proximo !=NULL){
				descritor->inicio = aux->proximo;
				descritor->inicio->anterior = NULL;
			}
			else if(aux->anterior != NULL && aux->proximo != NULL){
				aux->anterior->proximo = aux->proximo;
				aux->proximo->anterior = aux->anterior;
			}
			else if(aux->proximo == NULL && aux->anterior != NULL){
				descritor->fim = aux->anterior;
				aux->anterior->proximo = NULL;
			}

			achou = 1;
			livre = aux;
			free(livre);
		}
		aux = aux->proximo;
	}
	return achou;
}
